/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:14:27 by adriescr          #+#    #+#             */
/*   Updated: 2025/05/21 18:16:12 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(const char *filename, int *infile_error)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "pipex: ", 7);
		perror(filename);
		*infile_error = 1;
	}
	return (fd);
}

int	open_outfile(const char *filename, int infile, int infile_error)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		write(2, "pipex: ", 7);
		perror(filename);
		if (!infile_error)
			close(infile);
	}
	return (fd);
}

void	child1_process(t_pipex_ctx *ctx)
{
	int	devnull;

	if (ctx->infile_error)
	{
		devnull = open("/dev/null", O_RDONLY);
		dup2(devnull, 0);
		close(devnull);
	}
	else
		dup2(ctx->infile, 0);
	dup2(ctx->fd[1], 1);
	close(ctx->fd[0]);
	close(ctx->fd[1]);
	if (!ctx->infile_error)
		close(ctx->infile);
	close(ctx->outfile);
	ft_exect_cmd(ctx->argv[2], ctx->envp);
}

void	child2_process(t_pipex_ctx *ctx)
{
	dup2(ctx->fd[0], 0);
	dup2(ctx->outfile, 1);
	close(ctx->fd[0]);
	close(ctx->fd[1]);
	if (!ctx->infile_error)
		close(ctx->infile);
	close(ctx->outfile);
	ft_exect_cmd(ctx->argv[3], ctx->envp);
}
