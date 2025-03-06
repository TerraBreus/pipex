/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipex.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/03 10:49:19 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/06 15:46:39 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

/*
void	pipex(int nmbr_of_cmds, char *argv[], char *path)

infile = argv[1];			(first string)
outfile = argv[nmbr_of_cmds + 2];	(last string)

int	**pfdv;				(an array of pipes);
pfdv = create_pipes(nmbr_of_cmds);

pipe_in(infile, pfdv[0], argv[0])
if (nmbr_of_cmds > 1)
	for i in nmbr_of_cmds
		pipe_through(pfdv[i], argv[i]);
pipe_out(outfile, pfdv[nmbr_of_cmds], argv[nmbr_of_cmds + 1]);

close_all();				(infile, outfile, all pipes)
*/

#include "pipex.h"

void	pipex(int cmd_c, char *argv[], char **paths)
{
	int	**pfd_v;
	int	i;
	int	infile_fd;
	int	outfile_fd;

	pfd_v = create_pipes(cmd_c);
	infile_fd = open(argv[1], O_RDONLY);
	outfile_fd = open(argv[cmd_c + 2], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	i = -1;
	while (++i < cmd_c)
	{
		if (i == 0)
			pipe_in(infile_fd, argv[2], pfd_v[i][1], paths);
		else if (i != cmd_c - 1)
			pipe_through(argv[i + 2], pfd_v, i, paths);
		else
			pipe_out(outfile_fd, argv[cmd_c + 1], pfd_v[cmd_c - 2][0], paths);
	}
	close_and_free_pipes(pfd_v, cmd_c - 1);
	close_files(infile_fd, outfile_fd);
}
