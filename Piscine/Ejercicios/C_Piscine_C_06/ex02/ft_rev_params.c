/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:48:04 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/10 13:48:08 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	int	strlen;

	if (argc < 2)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		strlen = ft_strlen(argv[argc - i - 1]);
		write(1, argv[argc - i - 1], strlen);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
