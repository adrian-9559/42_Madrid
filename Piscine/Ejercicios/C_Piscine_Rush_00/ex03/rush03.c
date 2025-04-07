/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavarro <jnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:52:25 by jnavarro          #+#    #+#             */
/*   Updated: 2025/02/22 15:33:49 by jnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	checkifcolfirst(int contcol, int col)
{
	if (contcol == 1)
	{
		ft_putchar('A');
	}
	else if (contcol == col)
	{
		ft_putchar('C');
		ft_putchar('\n');
	}
	else
	{
		ft_putchar('B');
	}
}

void	checkifcolfinal(int contcol, int col)
{
	if (contcol == 1)
	{
		ft_putchar('A');
	}
	else if (contcol == col)
	{
		ft_putchar('C');
		ft_putchar('\n');
	}
	else
	{
		ft_putchar('B');
	}
}

void	checkifcol(int contcol, int col)
{
	if (contcol == 1)
	{
		ft_putchar('B');
	}
	else if (contcol == col)
	{
		ft_putchar('B');
		ft_putchar('\n');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int y, int x)
{
	int	controw;
	int	contcol;

	controw = 1;
	while (controw <= x)
	{
		contcol = 1;
		while (contcol <= y)
		{
			if (controw == 1)
			{
				checkifcolfirst(contcol, y);
			}
			else if (controw == x)
			{
				checkifcolfinal(contcol, y);
			}
			else
			{
				checkifcol(contcol, y);
			}
			contcol++;
		}
		controw++;
	}
}
