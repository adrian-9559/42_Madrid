/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:55:53 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/14 21:00:37 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (len >= 0 && str[len] != '-')
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

/*
int main(void)
{
	int num = -12345;
	char *result = ft_itoa(num);
	int num2 = -12345;
	char *result2 = 
	printf("El número %d como cadena es: %s\n", num, result);
	free(result);
	return 0;
}
*/
