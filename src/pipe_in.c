/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipe_in.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/03 11:30:20 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/06 15:50:06 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_in(int infile_fd, char *cmdline, int pfd_write, char **paths)
{
	if (infile_fd == -1)
		return (perror("open infile"));
	if (dup2(infile_fd, 0) == -1)
	{
		close(infile_fd);
		return (perror("pipe_in -> dup2 infile"));
	}
	close(infile_fd);
	if (dup2(pfd_write, 1) == -1)
	{
		close(pfd_write);
		return (perror("pipe_in -> dup2 pfd_write"));
	}
	close(pfd_write);
	exec_cmd(paths, cmdline);
}
