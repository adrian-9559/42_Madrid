/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 23:00:00 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/26 23:03:54 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <sstream>

using namespace std;

/**
 * ENGLISH: Private default constructor (class is not instantiable).
 *
 * SPANISH: Constructor privado por defecto (la clase no es instanciable).
 */
PmergeMe::PmergeMe()
{
}

/**
 * ENGLISH: Copy constructor.
 *
 * SPANISH: Constructor de copia.
 *
 * @param other The source object. / El objeto fuente.
 */
PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

/**
 * ENGLISH: Copy assignment operator.
 *
 * SPANISH: Operador de asignación de copia.
 *
 * @param other The source object. / El objeto fuente.
 *
 * @return Reference to this object. // Referencia a este objeto.
 */
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

/**
 * ENGLISH: Destructor.
 *
 * SPANISH: Destructor.
 */
PmergeMe::~PmergeMe()
{
}

/**
 * ENGLISH: Checks if a token represents a positive integer (optionally
 *          prefixed with '+').
 *
 * SPANISH: Comprueba si un token representa un entero positivo
 *          (opcionalmente prefijado con '+').
 *
 * @param token The string to validate. / La cadena a validar.
 *
 * @return true if the token is a positive integer, false otherwise.
 *         // true si el token es un entero positivo, false en caso contrario.
 */
static bool isPositiveInteger(const string &token)
{
	size_t index = 0;

	if (token.empty())
		return (false);
	if (token[0] == '+')
		index = 1;
	if (index == token.size())
		return (false);
	for (; index < token.size(); ++index)
	{
		if (!isdigit(static_cast<unsigned char>(token[index])))
			return (false);
	}
	return (true);
}

/**
 * ENGLISH: Parses a token, validates it is a positive int, checks for
 *          duplicates, and appends it to the value vector.
 *
 * SPANISH: Analiza un token, valida que sea un int positivo, comprueba
 *          duplicados y lo añade al vector de valores.
 *
 * @param values The output vector of integers. / El vector de salida.
 * @param seen   Set of already-seen values for duplicate detection.
 *               / Conjunto de valores ya vistos para detectar duplicados.
 * @param token  The string to parse. / La cadena a analizar.
 *
 * @return true if the token was parsed and appended, false on error.
 *         / true si se añadió, false si hubo error.
 */
static bool appendToken(vector<int> &values, set<int> &seen, const string &token)
{
	char *end = NULL;
	long parsed;

	if (!isPositiveInteger(token))
		return (false);
	errno = 0;
	parsed = strtol(token.c_str(), &end, 10);
	if (errno == ERANGE || end == NULL || *end != '\0' || parsed <= 0 || parsed > INT_MAX)
		return (false);
	if (!seen.insert(static_cast<int>(parsed)).second)
		return (false);
	values.push_back(static_cast<int>(parsed));
	return (true);
}

/**
 * ENGLISH: Parses command-line arguments into a vector of positive integers.
 *          Each argument may contain multiple space-separated tokens.
 *
 * SPANISH: Analiza los argumentos de línea de comandos en un vector de
 *          enteros positivos. Cada argumento puede contener varios tokens
 *          separados por espacios.
 *
 * @param argc   The argument count. / El conteo de argumentos.
 * @param argv   The argument vector. / El vector de argumentos.
 * @param values The output vector of integers. / El vector de salida.
 *
 * @return true if parsing succeeded, false on error.
 *         / true si el análisis fue exitoso, false en caso de error.
 */
bool PmergeMe::parseInput(int argc, char **argv, vector<int> &values)
{
	set<int> seen;
	int index;

	values.clear();
	if (argc < 2)
		return (false);
	for (index = 1; index < argc; ++index)
	{
		istringstream stream(argv[index]);
		string token;
		while (stream >> token)
		{
			if (!appendToken(values, seen, token))
				return (false);
		}
	}
	return (!values.empty());
}

/**
 * ENGLISH: Prints a sequence of integers to standard output, space-separated.
 *
 * SPANISH: Imprime una secuencia de enteros en la salida estándar,
 *          separados por espacios.
 *
 * @param values The vector of integers to print. / El vector de enteros
 *               a imprimir.
 */
void PmergeMe::printSequence(const vector<int> &values)
{
	for (size_t index = 0; index < values.size(); ++index)
	{
		if (index > 0)
			cout << ' ';
		cout << values[index];
	}
	cout << endl;
}
