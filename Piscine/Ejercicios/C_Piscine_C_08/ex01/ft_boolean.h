/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:51:51 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/13 16:51:56 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include "ft_boolean.h"

# define EVEN(nbr) (nbr % 2 == 0)
# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

typedef int	t_bool;

void		ft_putstr(char *str);
t_bool		ft_is_even(int nbr);
int			main(int argc, char **argv);

#endif
