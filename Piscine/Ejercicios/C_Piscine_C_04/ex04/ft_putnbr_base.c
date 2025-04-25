/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:02:12 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/25 19:46:00 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = 0;
		while (base[j])
		{
			if (j != i && base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	my_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

int	ft_change_negative(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (-nbr);
	}
	return (nbr);
}

void	ft_putstr(char *rev_digits, int i)
{
	while (i-- > 0)
		write(1, rev_digits + i, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				long_base;
	int				i;
	unsigned int	num_absolute;
	char			rev_digits[1024];

	if (!check_base(base))
		return ;
	long_base = my_strlen(base);
	if (nbr == 0)
	{
		write(1, base, 1);
		return ;
	}
	i = 0;
	num_absolute = ft_change_negative(nbr);
	while (num_absolute > 0)
	{
		rev_digits[i++] = base[num_absolute % long_base];
		num_absolute /= long_base;
	}
	ft_putstr(rev_digits, i);
}

/*
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int number = 0;
		int i = 0;
		while (argv[1][i])
		{
			number = number * 10 + (argv[1][i] - '0');
			i++;
		}
		ft_putnbr_base(number, argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}
*/
/*

	check_base: Comprueba que la base sea correcta.
		Devuelve 1 si la base es correcta.
		Devuelve 0 si la base no es correcta.

	my_strlen: Devuelve la longitud de una cadena.

	ft_change_negative: Si el número es negativo,
		escribe un '-' y convierte el número a positivo.
		Devuelve el número positivo.

	ft_putnbr_base: Escribe un número en la base indicada.
		Si la base no es correcta, no hace nada.
		Si el número es 0, escribe el primer carácter de la base.
		Si el número es negativo,
			escribe un '-' y convierte el número a positivo.
		Calcula el número en la base indicada y lo escribe.

*/