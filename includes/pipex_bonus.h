/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:09:50 by bcaffere          #+#    #+#             */
/*   Updated: 2022/03/22 14:11:30 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/*to perror*/
# include <stdio.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_ENVP "Environment"
# define ERR_CMD "Command not found: "
# define ERR_HEREDOC "here_doc"

typedef struct s_ppxb
{
	int		infile;
	int		outfile;
	char	*env_path;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	pid_t	pid;
	int		cmd_nmbs;
	int		pipe_nmbs;
	int		*pipe;
	int		idx;
}t_ppxb;

/* pipex_bonus.c */
void	close_pipes(t_ppxb *pipex);

/* child_bonus.c */
void	child(t_ppxb pipex, char **argv, char **envp);

/* free.c */
void	parent_free(t_ppxb *pipex);
void	child_free(t_ppxb *pipex);
void	pipe_free(t_ppxb *pipex);

/* files_bonus.c */
char	*find_path(char **envp);
void	get_infile(char **argv, t_ppxb *pipex);
void	get_outfile(char *argv, t_ppxb *pipex);

/* error_bonus.c */
void	msg_error(char *err);
void	msg_pipe(char *arg);
int		msg(char *err);

/* funcions */
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

#endif
