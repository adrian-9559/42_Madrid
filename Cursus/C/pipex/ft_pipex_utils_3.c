/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:31:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/05/21 17:32:49 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_count_args(const char *cmd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		skip_whitespace(cmd, &i);
		if (!cmd[i])
			break ;
		skip_argument(cmd, &i);
		count++;
	}
	return (count);
}

static int	ft_arg_len(const char *cmd, int *i)
{
	int		start;
	int		in_quote;
	char	quote;

	start = *i;
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
	return (*i - start);
}

static void	ft_trim_quotes(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (len >= 2 && ((arg[0] == '"' && arg[len - 1] == '"')
			|| (arg[0] == '\'' && arg[len - 1] == '\'')))
	{
		ft_memmove(arg, arg + 1, len - 2);
		arg[len - 2] = '\0';
	}
}

static char	*ft_get_next_arg(const char *cmd, int *i)
{
	int		len;
	char	*arg;

	while (ft_isspace(cmd[*i]))
		(*i)++;
	if (!cmd[*i])
		return (NULL);
	len = ft_arg_len(cmd, i);
	arg = malloc(len + 1);
	if (!arg)
		return (NULL);
	ft_strncpy(arg, cmd + *i - len, len);
	arg[len] = '\0';
	ft_trim_quotes(arg);
	ft_unescape_quotes(arg);
	return (arg);
}

char	**ft_split_shell(const char *cmd)
{
	int		i;
	int		arg_idx;
	int		argc;
	char	**args;
	char	*arg;

	i = 0;
	arg_idx = 0;
	argc = ft_count_args(cmd);
	args = malloc(sizeof(char *) * (argc + 1));
	if (!args)
		return (NULL);
	arg = ft_get_next_arg(cmd, &i);
	while (arg)
	{
		args[arg_idx++] = arg;
		arg = ft_get_next_arg(cmd, &i);
	}
	args[arg_idx] = NULL;
	return (args);
}
