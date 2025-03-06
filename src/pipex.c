/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:49:19 by zivanov           #+#    #+#             */
/*   Updated: 2025/03/06 18:55:50 by zivanov          ###   ########.fr       */
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
// int setupIO(int num_cmds,  int infile, int outfile) {
// 	static last_read_end;
// 	static cmd_idx = 0;

// 	if (cmd_idx == 0) {
// 		// redirect I -> infile
// 		// redirect O -> pipe[1]
// 		// last_read_end = pipe[0]
// 	} else if (cmd_idx == num_cmds - 1) {
// 		// redirect I -> last_read_end
// 		// redirect O -> outfile
// 	} else {
// 		// redirect I -> last_read_end
// 		// redirect O -> pipe[1]
// 		// last_read_end = pipe[0]
// 	}
// 	cmd_idx++;
// 	// 
// }

// void cmd_pipeline() {
// 	while(i < num_cmds) {
// 		if (setupIO() == -1)
// 			; // TODO: handle
// 		pid_t pid = fork();
// 		if (pid == 0) {\
// 			// child
// 			// read from stdin
// 			// write to stdout
// 		} else {
// 			// parent
// 			// free/wait/close?

// 		}
// 	}
// 	// close STDIN
// 	// close STDOUT
// }
