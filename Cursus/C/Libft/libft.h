/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:52:13 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/11 11:26:15 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef libft
# define libft

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <stddef.h>

int	ft_atoi(char *str);
void	*ft_bzero(void *s, size_t len);
int	ft_isalnum(unsigned int c);
int	ft_isalpha(unsigned int c);
int	ft_isascii(unsigned int c);
int	ft_isdigit(unsigned int c);
int	ft_isprint(unsigned int c);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, size_t c);
size_t	ft_strlcat(char *dest, char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str1, const char *str2, size_t len);
char	*ft_strrchr(const char *s, size_t c);
unsigned int	ft_tolower(unsigned int c);
unsigned int	ft_toupper(unsigned int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

// funciones extra para comprobar los resutados
size_t	strlcat(char *dest, char *src, size_t size);
size_t strlcpy(char *dst, const char *src, size_t dstsize);
char *strnstr(const char *haystack, const char *needle, size_t len);
char	*substr(char const *s, unsigned int start, size_t len);
char	*strjoin(char const *s1, char const *s2);
char	*strtrim(char const *s1, char const *set);
char	**split(char const *s, char c);
void free_split(char **split_result);

#endif
