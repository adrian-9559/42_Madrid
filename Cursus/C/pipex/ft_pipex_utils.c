/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:18:46 by adriescr          #+#    #+#             */
/*   Updated: 2025/05/21 17:51:54 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_extract_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			return (path);
		}
		i++;
	}
	return (NULL);
}

int	ft_open_fd(const char *filename, int in_or_out)
{
	int	flags;
	int	fd;

	if (in_or_out == 0)
		flags = O_RDONLY;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	fd = open(filename, flags, 0644);
	if (fd == -1)
	{
		close(fd);
		perror("Error opening file");
		exit(EXIT_FAILURE);
		return (-1);
	}
	return (fd);
}

void	skip_whitespace(const char *cmd, int *i)
{
	while (ft_isspace(cmd[*i]))
		(*i)++;
}

void	skip_argument(const char *cmd, int *i)
{
	int		in_quote;
	char	quote;

	in_quote = 0;
	quote = 0;
	while (cmd[*i])
	{
		if (!in_quote && (cmd[*i] == '\'' || cmd[*i] == '"'))
		{
			in_quote = 1;
			quote = cmd[(*i)++];
		}
		else if (in_quote && cmd[*i] == quote)
		{
			in_quote = 0;
			(*i)++;
		}
		else if (!in_quote && ft_isspace(cmd[*i]))
			break ;
		else
			(*i)++;
	}
}
