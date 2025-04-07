/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:24:47 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/12 16:43:49 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_FUNCTIONS_H
# define LIBRARY_FUNCTIONS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1024

// ft_map_reader.c
char	**ft_map_reader(char *file, char **map, int rows_header);

// ft_checkers.c
char	**ft_check_map(char **map, char *fill, int *num_caracters);

// ft_chekers_2.c
char	*ft_header_map_num(char *file);
int		ft_get_num_header_rows(char *file);
char	*ft_get_fills(char *file);

// ft_put.c
void	ft_put_map(char **map, int rows);
void	ft_putchar(char c);
void	ft_put_error(char *arr);

// ft_counts.c
int		ft_get_document_rows(char *file);
int		ft_get_document_cols(char *file);
int		ft_strlen(char *str);

// ft_file.c
int		ft_open_file(char *file);
int		ft_close_file(int fd);

#endif

/*
	*library_functions.h:
		Es un archivo que contiene los prototipos
		de las funciones que se encuentran en los archivos .c.

*/
