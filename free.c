/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:22:25 by fdaumas           #+#    #+#             */
/*   Updated: 2022/05/27 09:55:58 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"
#include <unistd.h>

void	parent_free(t_ppxb *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
//	while (pipex->cmd_paths[i])
//	{
//		free(pipex->cmd_paths[i]);
//		i++;
//	}
//	free(pipex->cmd_paths);
	i = 0;
	while (i < (pipex->pipe_nmbs))
	{
		close(pipex->pipe[i]);
		i++;
	}
	exit(0);
}

void	child_free(t_ppxb *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	pipe_free(t_ppxb *pipex)
{
	int	i;

	close(pipex->infile);
	close(pipex->outfile);
	i = 0;
	while (i < (pipex->pipe_nmbs))
	{
		close(pipex->pipe[i]);
		i++;
	}
	msg(ERR_ENVP);
	exit(1);
}
