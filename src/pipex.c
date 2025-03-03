/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipex.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/03 10:49:19 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/03 12:15:25 by zivanov        ########   odam.nl        */
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

void	pipex(int cmd_c, char *argv, char **paths)
{
	int	**pfd_v;
	int	i;

	pfd_v = create_pipes(cmd_c);
	i = -1;
	while (++i < cmd_c)
	{
		if (i == 0)
			pipe_in(argv[1], pfd_v[i], argv[2], paths);
		else if (i != cmd_c - 1)
			pipe_through(pfd_v, i, argv[i + 2], paths);
		else
			pipe_out(argv[cmd_c + 2], pfd_v[cmd_c - 2], argv[cmd_c + 1], paths);
	}
	close_all_pipes(pfd_v);
}
