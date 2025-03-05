/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipe_in.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/03 11:30:20 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/05 12:41:48 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

//This should all be done as a child!

/*
void	pipe_in(char *infile, char *cmdline, int *pipefd, char *path)

open(infile)
	check if it exists and if we can read it and attach it to a fd_infile

dup2(infile, 0)	
	make std_in be a duplicate of the infile_fd

close(infile)
	we don't need it anymore since std_in is a duplicate of it anyways.

close(pipefd[0])
	close the read side of the pipe since we will only be writing.

dup2(pipefd[1], 1)
	make std_out be a duplicate of the write side of the pipe.

close(pipefd[1])
	we don't need it anymore since we have std_out as its duplicate.

split commandline into command and flags.
	command = ft_split(cmdline, ' ');
	MALLOCING!

create the full path
	full_path = create_path(path, command[0]);
	MALLOCING!

execute command.
	execve(path, command, NULL);

clean up if execve has failed.
*/

#include "pipex.h"

void	pipe_in(char *infile, char *cmdline, int pfd_write, char **paths)
{
	int		fd_infile;	

	fd_infile = open(infile, O_RDONLY);
	if (fd_infile == -1)
		return (perror("open infile"));
	if (dup2(fd_infile, 0) == -1)
	{
		close(fd_infile);
		return (perror("pipe_in -> dup2 infile"));
	}
	close(fd_infile);
	if (dup2(pfd_write, 1) == -1)
	{
		close(pfd_write);
		return (perror("pipe_in -> dup2 pfd_write"));
	}
	close(pfd_write);
	exec_cmd(paths, cmdline);
}
