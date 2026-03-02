/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:29:30 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/25 00:12:46 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * ENGLISH: Prints an integer to the specified file descriptor.
 * 		Returns the number of characters printed.
 * SPANISH: Imprime un entero en el descriptor de archivo
 * 		especificado. Devuelve el número de caracteres impresos.
 *
 * @param fd   The file descriptor to write to. /
 * 			El descriptor de archivo al que escribir.
 * @param number    The integer to print. / El entero a imprimir.
 *
 * @returns The number of characters printed. /
 *          El número de caracteres impresos.
 */
static int	print_int(int fd, int number)
{
	return (ft_putnbr_fd((long)number, fd));
}

/**
 * ENGLISH: Prints an unsigned integer to the specified file descriptor.
 * 		Returns the number of characters printed.
 * SPANISH: Imprime un entero sin signo en el descriptor de archivo
 * 		especificado. Devuelve el número de caracteres impresos.
 *
 * @param fd   The file descriptor to write to. /
 * 			El descriptor de archivo al que escribir.
 * @param number    The unsigned integer to print.
 *			/ El entero sin signo a imprimir.
 *
 * @returns The number of characters printed. /
 *          El número de caracteres impresos.
 */
static int	print_uint(int fd, unsigned int number)
{
	return (ft_putnbr_fd((long)number, fd));
}

/**
 * ENGLISH: Handles a single format specifier for ft_fprintf,
 * 			printing the corresponding argument.
 *
 * SPANISH: Maneja un solo especificador de formato para ft_fprintf,
 * 			imprimiendo el argumento correspondiente.
 *
 * @param fd   The file descriptor to write to. /
 *             El descriptor de archivo al que escribir.
 *
 * @param spec   The format specifier character (e.g., 'd', 's', 'c'). /
 *               El carácter del especificador de formato (por ejemplo,
 * 				'd', 's', 'c').
 *
 * @param ap   Pointer to the variable argument list. /
 *             Puntero a la lista de argumentos variables.
 *
 * @returns The number of characters printed for this specifier. /
 *          El número de caracteres impresos para este especificador.
 */
static int	handle_format(int fd, char spec, va_list *ap)
{
	char	*str;

	if (spec == 's')
	{
		str = va_arg(*ap, char *);
		if (!str)
			str = "(null)";
		ft_putstr_fd(str, fd);
		return ((int)ft_strlen(str));
	}
	else if (spec == 'd' || spec == 'i')
		return (print_int(fd, va_arg(*ap, int)));
	else if (spec == 'u')
		return (print_uint(fd, va_arg(*ap, unsigned int)));
	else if (spec == 'c')
		return (write(fd, &(char){va_arg(*ap, int)}, 1));
	else if (spec == '%')
		return (write(fd, "%", 1));
	else
		return (write(fd, &spec, 1));
}

/**
 * ENGLISH: Writes formatted output to the specified file descriptor,
 * 			similar to printf.
 *
 * SPANISH: Escribe una salida formateada en el descriptor de archivo
 * 			especificado, igual que printf.
 *
 * @param fd   The file descriptor to write to. /
 *             El descriptor de archivo al que escribir.
 *
 * @param fmt   The format string containing the text and format specifiers. /
 *              La cadena de formato que contiene el texto y los especificadores
 *              de formato.
 *
 * @param ... Additional arguments to be formatted and printed. /
 *              Argumentos adicionales que serán formateados e impresos.
 *
 * @returns The total number of characters written. /
 *          El número total de caracteres escritos.
 */
int	ft_fprintf(int fd, const char *fmt, ...)
{
	va_list		ap;
	int			written;
	const char	*p = fmt;

	written = 0;
	va_start(ap, fmt);
	while (*p)
	{
		if (*p == '%' && *(p + 1))
		{
			written += handle_format(fd, *(++p), &ap);
			p++;
		}
		else
		{
			write(fd, p, 1);
			written++;
			p++;
		}
	}
	va_end(ap);
	return (written);
}
