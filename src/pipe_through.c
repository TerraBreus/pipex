/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipe_through.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/03 16:31:04 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/03 16:51:28 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_through(char *cmdline, int **pfd_v, int i, char **paths)
{
	if (dup2(pfd_v[i - 1][0], 0))
		return (perror("pipe_through -> dup2 pfdv_read"));
	close(pfd_v[i - 1][0]);
	if (dup2(pfd_v[i][1], 1))
		return (perror("pipe_through -> dup2 pfdv_write"));
	close(pfd_v[i][1]);
	exec_cmd(paths, cmdline);
}
