/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipe_out.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/03 16:39:03 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/03 16:51:43 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_out(char *outfile, char *cmdline, int pfd_read, char *paths)
{
	int	fd_outfile;	

	fd_outfile = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_outfile == -1)
		return (perror("pipe_out -> open outfile"));
	if (dup2(fd_outfile, 1) == -1)
	{
		close(fd_outfile);
		return (perror("pipe_out -> dup2 outfile"));
	}
	close(fd_outfile);
	if (dup2(pfd_read, 0) == -1)
	{
		close(pfd_read);
		return (perror("piep_out -> dup2 pfd_in"));
	}
	close(pfd);
	exec_cmd(paths, cmd_line);
}

