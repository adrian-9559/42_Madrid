/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:27:05 by adriescr          #+#    #+#             */
/*   Updated: 2025/05/21 18:26:10 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_pipex_ctx
{
	int		infile;
	int		infile_error;
	int		fd[2];
	int		outfile;
	char	**argv;
	char	**envp;
}	t_pipex_ctx;

int		ft_print_str(char *str);
int		ft_print_error_str(char *str);
char	*ft_extract_path(char **envp);
int		ft_open_fd(const char *filename, int in_or_out);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	ft_free_split(char **split);
char	*ft_strdup(const char *s1);
int		ft_isspace(int c);
size_t	ft_strlen(const char *s);
char	*ft_strncpy(char *dest, const char *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
char	*ft_get_cmd_path(char *cmd, char **envp);
char	**ft_split_shell(const char *cmd);
void	skip_whitespace(const char *cmd, int *i);
void	skip_argument(const char *cmd, int *i);
void	ft_unescape_quotes(char *arg);
int		ft_exect_cmd(char *cmd, char **envp);
int		open_infile(const char *filename, int *infile_error);
int		open_outfile(const char *filename, int infile, int infile_error);
void	child1_process(t_pipex_ctx *ctx);
void	child2_process(t_pipex_ctx *ctx);

#endif