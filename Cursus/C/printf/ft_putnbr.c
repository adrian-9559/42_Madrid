/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putnbr.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: adriescr <adriescr@student.42madrid.com	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/30 02:55:28 by adriescr		  #+#	#+#			 */
/*   Updated: 2025/04/30 03:24:01 by adriescr		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		count_char;

	count_char = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count_char += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count_char += ft_putnbr(n / 10);
	count_char += ft_putchar(n % 10 + '0');
	return (count_char);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		count_char;

	count_char = 0;
	if (n >= 10)
		count_char += ft_putnbr_unsigned(n / 10);
	count_char += ft_putchar(n % 10 + '0');
	return (count_char);
}
