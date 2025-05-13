/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:50:02 by adriescr          #+#    #+#             */
/*   Updated: 2025/05/13 18:13:55 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	dot;
	int	hash;
	int	plus;
	int	space;
}	t_flags;

int			ft_printf(const char *format, ...);
// Funciones obligatorias de la libreria
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr(int n);
int			ft_putnbr_unsigned(unsigned int n);
int			ft_putnbr_base(unsigned long nbr, int upper);
int			ft_putptr(void *ptr);
// Funciones para bonus
int			ft_putnchar(char c, int n);
int			ft_strlen(const char *str);
int			ft_ptrlen(unsigned long ptr);
int			ft_numlen(int n);
int			ft_numlen_unsigned(unsigned int n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
int			ft_handle_char(char c, t_flags flags);
int			ft_handle_string(char *str, t_flags flags);
int			ft_handle_pointer(void *ptr, t_flags flags);
int			ft_handle_integer(int n, t_flags flags);
int			ft_handle_unsigned(unsigned int n, t_flags flags);
int			ft_handle_hex(unsigned int n, char specifier, t_flags flags);

#endif