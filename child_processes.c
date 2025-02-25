/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   child_processes.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/19 15:40:44 by zivanov        #+#    #+#                */
/*   Updated: 2025/02/19 15:45:49 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd1(int pfd, char *infile, char *cmd1, char **paths)
{
	int		fd_infile;	

	fd_infile = open(infile, 0);
	if (fd_infile == -1)
		return (perror("open infile"));
	if (dup2(fd_infile, 0) == -1)
	{
		close(fd_infile);
		return (perror("dup2 infile"));
	}
	close(fd_infile);
	if (dup2(pfd, 1) == -1)
	{
		close(pfd);
		return (perror("dup2 pfd_out"));
	}
	close(pfd);
	new_process(paths, cmd1);
}

static void	exec_cmd2(int pfd, char *outfile, char *cmd2, char **paths)
{
	int	fd_outfile;	

	fd_outfile = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_outfile == -1)
		return (perror("open outfile"));
	if (dup2(fd_outfile, 1) == -1)
	{
		close(fd_outfile);
		return (perror("dup2 outfile"));
	}
	close(fd_outfile);
	if (dup2(pfd, 0) == -1)
	{
		close(pfd);
		return (perror("dup2 pfd_in"));
	}
	close(pfd);
	new_process(paths, cmd2);
}

void	child_processes(char *infile, char *cmd1, char *cmd2, char *outfile, char **paths)
{
	int	pd[2];
	int	pid;

	if (pipe(pd) == -1)
		return (perror("pipe child"));
	pid = fork();
	if (pid == -1)
		return (perror("fork child"));
	if (pid == 0)
	{
		close(pd[0]);
		exec_cmd1(pd[1], infile, cmd1, paths);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(pd[1]);
		exec_cmd2(pd[0], outfile, cmd2, paths);
	}
}
