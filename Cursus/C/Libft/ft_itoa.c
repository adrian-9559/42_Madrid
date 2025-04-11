/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:55:53 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/11 10:16:31 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;
	int		i;

	sign = 1;
	len = 0;
	if (n < 0) 
	{
		sign = -1;
		n = -n;
	}
	if (n == 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = len - 1;
	n *= sign;
	while (i >= 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
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
