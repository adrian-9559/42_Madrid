/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:12:12 by adriescr          #+#    #+#             */
/*   Updated: 2025/05/22 16:42:00 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exect_cmd(char *cmd, char **envp)
{
	char	**argv_exec;
	char	*cmd_path;

	argv_exec = ft_split_shell(cmd);
	if (!argv_exec || !argv_exec[0])
	{
		ft_print_error_str("pipex: ");
		ft_print_error_str(cmd);
		ft_print_error_str(": command not found\n");
		ft_free_split(argv_exec);
		exit(127);
	}
	cmd_path = ft_get_cmd_path(argv_exec[0], envp);
	if (cmd_path)
		execve(cmd_path, argv_exec, envp);
	ft_print_error_str("pipex: ");
	ft_print_error_str(cmd);
	ft_print_error_str(": command not found\n");
	ft_free_split(argv_exec);
	exit(127);
}

static void	ft_pipex_cleanup(t_pipex_ctx *ctx)
{
	close(ctx->fd[0]);
	close(ctx->fd[1]);
	if (!ctx->infile_error)
		close(ctx->infile);
	close(ctx->outfile);
}

static int	ft_pipex_init(t_pipex_ctx *ctx, char **argv, char **envp)
{
	int	ret;

	ret = 0;
	ctx->argv = argv;
	ctx->envp = envp;
	ctx->infile_error = 0;
	ctx->infile = open_infile(argv[1], &ctx->infile_error);
	ctx->outfile = open_outfile(argv[4], ctx->infile, ctx->infile_error);
	if (ctx->outfile < 0)
		ret = 1;
	if (ret == 0 && pipe(ctx->fd) == -1)
	{
		perror("pipex: pipe");
		if (!ctx->infile_error)
			close(ctx->infile);
		close(ctx->outfile);
		ret = 1;
	}
	return (ret);
}

int	ft_pipex(int argc, char **argv, char **envp)
{
	t_pipex_ctx	ctx;
	pid_t		pid1;
	pid_t		pid2;
	int			status1;
	int			status2;

	if (argc != 5)
	{
		ft_print_error_str("Usage: ./pipex infile cmd1 cmd2 outfile\n");
		return (1);
	}
	if (ft_pipex_init(&ctx, argv, envp))
		return (1);
	pid1 = fork();
	if (pid1 == 0)
		child1_process(&ctx);
	pid2 = fork();
	if (pid2 == 0)
		child2_process(&ctx);
	ft_pipex_cleanup(&ctx);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	return ((status2 >> 8) & 0xFF);
}

int	main(int argc, char **argv, char **envp)
{
	return (ft_pipex(argc, argv, envp));
}
