/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: adriescr <adriescr@student.42madrid.com	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/23 19:10:11 by adriescr		  #+#	#+#			 */
/*   Updated: 2025/04/25 20:20:57 by adriescr		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list va, char *str)
{
	size_t	counter;

	counter = 0;
	if (*str == 'c')
		counter += ft_putchar(va_arg(va, int));
	else if (*str == 's')
		counter += ft_putstr(va_arg(va, char *));
	else if (*str == 'p')
		counter += ft_putptr(va_arg(va, void *));
	else if (*str == 'i' || *str == 'd')
		counter += ft_putnbr(va_arg(va, int));
	else if (*str == 'u')
		counter += ft_putnbr_unsigned(va_arg(va, unsigned int));
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			counter += ft_putnbr_base(va_arg(va, unsigned int), 0);
		else
			counter += ft_putnbr_base(va_arg(va, unsigned int), 1);
	}
	else if (*str == '%')
		counter += ft_putchar(*str);
	return (counter);
}

int	ft_printf(char const *str, ...)
{
	va_list		va;
	size_t		counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			counter += ft_format(va, (char *)str);
		}
		else
			counter += ft_putchar(*str);
		str++;
	}
	va_end(va);
	return (counter);
}
