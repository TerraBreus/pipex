/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipe_out.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/03 16:39:03 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/06 15:45:14 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_out(int outfile_fd, char *cmdline, int pfd_read, char **paths)
{
	if (outfile_fd == -1)
		return (perror("pipe_out -> open outfile"));
	if (dup2(outfile_fd, 1) == -1)
	{
		close(outfile_fd);
		return (perror("pipe_out -> dup2 outfile"));
	}
	close(outfile_fd);
	if (dup2(pfd_read, 0) == -1)
	{
		close(pfd_read);
		return (perror("pipe_out -> dup2 pfd_read"));
	}
	close(pfd_read);
	exec_cmd(paths, cmdline);
}
