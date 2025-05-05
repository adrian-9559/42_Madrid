/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:09:31 by adriescr          #+#    #+#             */
/*   Updated: 2025/05/05 23:51:57 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "unistd.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_gnl_vars
{
	char	*line;
	char	*buffer;
	char	*temp;
}			t_gnl_vars;

char		*get_next_line(int fd);
char		*ft_extract_line(char *remainder);
char		*ft_update_remainder(char *remainder);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin_free(char *s1, char *s2);

#endif
