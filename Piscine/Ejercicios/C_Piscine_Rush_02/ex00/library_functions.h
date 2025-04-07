/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:24:47 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/08 12:24:50 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_FUNCTIONS_H
# define LIBRARY_FUNCTIONS_H

// ft_rush02.c
typedef struct s_dict
{
	int		digits;
	char	*first_number;
	char	*name;
}			t_dict;

// ft_rush02.c
int			ft_rush02(char *dict, char *arr);

// ft_chekers.c
int			ft_number_arguments (char *arr);
int			ft_strlen(char *arr);
int			ft_check_dict(char *dict);

// ft_convert.c
int			ft_count_digits(char *arr);

// ft_read_document.c
t_dict		*ft_read_document(char *loc_dict, t_dict *arr_dict);

// ft_putchar.c
void		ft_put_error(char *arr);
void		ft_recor_string(char *arr);

#endif

/*
	*library_functions.h:
		Es un archivo que contiene los prototipos
		de las funciones que se encuentran en los archivos .c.

*/
