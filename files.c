/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:20:39 by fdaumas           #+#    #+#             */
/*   Updated: 2022/04/05 15:20:44 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	get_infile(char **argv, t_ppxb *pipex)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		msg_error(ERR_INFILE);
}

void	get_outfile(char *argv, t_ppxb *pipex)
{
	pipex->outfile = open(argv, O_CREAT | O_RDWR | O_TRUNC);
	if (pipex->outfile < 0)
		msg_error(ERR_OUTFILE);
}
