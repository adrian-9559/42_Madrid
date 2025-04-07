/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavarro <jnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:52:25 by jnavarro          #+#    #+#             */
/*   Updated: 2025/02/23 21:51:58 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putchar_error(void);

void	checkifrow(int col[], char start, char middle, char end)
{
	if (col[0] == 1)
	{
		ft_putchar(start);
		if (col[1] == 1)
			ft_putchar('\n');
	}
	else if (col[0] == col[1])
	{
		ft_putchar(end);
		ft_putchar('\n');
	}
	else
		ft_putchar(middle);
}

void	checkrow(int controw, int contcol, int x, int y)
{
	int	row[2];

	row[0] = contcol;
	row[1] = x;
	if (controw == 1)
		checkifrow(row, 'A', 'B', 'C');
	else if (controw == y)
		checkifrow(row, 'C', 'B', 'A');
	else
		checkifrow(row, 'B', ' ', 'B');
}

void	rush(int x, int y)
{
	int	controw;
	int	contcol;

	controw = 1;
	if (x < 0 || y < 0)
		ft_putchar_error();
	while (controw <= y)
	{
		contcol = 1;
		while (contcol <= x)
		{
			checkrow(controw, contcol, x, y);
			contcol++;
		}
		controw++;
	}
}
