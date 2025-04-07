/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:02:50 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/06 19:27:11 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	change_to_minus_array(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
}

void	change_mayus(char *str, int c)
{
	if (str[c] >= 'a' && str[c] <= 'z')
		str[c] -= 32;
}

char	*ft_strcapitalize(char *str)
{
	int	c;

	change_to_minus_array(str);
	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] >= 'a' && str[c] <= 'z')
		{
			if (c == 0)
				change_mayus(str, c);
			else if (!(str[c - 1] >= 'a' && str[c - 1] <= 'z')
				&& !(str[c - 1] >= 'A' && str[c - 1] <= 'Z')
				&& !(str[c - 1] >= '0' && str[c - 1] <= '9'))
				change_mayus(str, c);
		}
		c++;
	}
	return (str);
}
