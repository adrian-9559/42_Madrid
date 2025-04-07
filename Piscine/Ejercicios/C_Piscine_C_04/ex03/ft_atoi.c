/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:57:51 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/05 17:57:54 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_empty(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0')
	{
		return (0);
	}
	return (1);
}

int	ft_is_space(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
	{
		j++;
		i++;
	}
	return (j);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (ft_empty(str))
		return (0);
	i = ft_is_space(str, i);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
