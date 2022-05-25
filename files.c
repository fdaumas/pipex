/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:20:39 by fdaumas           #+#    #+#             */
/*   Updated: 2022/05/25 16:22:06 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"
#include <sys/unistd.h>
#include <unistd.h>

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5);
}

void	get_infile(char **argv, t_ppxb *pipex)
{
	if (access(argv[1], F_OK | R_OK) == -1)
	{
		msg_error(ERR_INFILE);
		pipex->infile = -1;
	}
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
			msg_error(ERR_INFILE);
	}
}

void	get_outfile(char *argv, t_ppxb *pipex)
{
	if (access(argv, F_OK) != -1 && access(argv, W_OK) == -1)
	{
		msg_error(ERR_OUTFILE);
		pipex->outfile = -1;
	}
	else
	{
		pipex->outfile = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (pipex->outfile < 0)
			msg_error(ERR_OUTFILE);
	}
}
