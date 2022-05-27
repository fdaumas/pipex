/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:24:52 by fdaumas           #+#    #+#             */
/*   Updated: 2022/05/27 10:00:51 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"
#include <sys/wait.h>

static void	creat_pipes(t_ppxb *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_nmbs - 1)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			parent_free(pipex);
		i++;
	}
}

void	close_pipes(t_ppxb *pipex)
{
	int	i;
	int	y;

	i = 0;
	y = -1;
	while (i < (pipex->pipe_nmbs))
	{
		close(pipex->pipe[i]);
		i++;
	}
	while (++y < pipex->cmd_nmbs)
		waitpid(-1, 0, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_ppxb	pipex;

	if (argc != 5)
		return (msg(ERR_INPUT));
	get_infile(argv, &pipex);
	get_outfile(argv[argc - 1], &pipex);
	pipex.cmd_nmbs = argc - 3;
	pipex.pipe_nmbs = 2 * (pipex.cmd_nmbs - 1);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.pipe_nmbs);
	if (!pipex.pipe)
		msg_error(ERR_PIPE);
	pipex.env_path = find_path(envp);
	if (pipex.env_path)
	{
		pipex.cmd_paths = ft_split(pipex.env_path, ':');
		if (!pipex.cmd_paths)
			pipe_free(&pipex);
	}
	creat_pipes(&pipex);
	pipex.idx = -1;
	while (++(pipex.idx) < pipex.cmd_nmbs)
		child(pipex, argv, envp);
	close_pipes(&pipex);
	parent_free(&pipex);
	return (0);
}
