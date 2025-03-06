/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_through.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:31:04 by zivanov           #+#    #+#             */
/*   Updated: 2025/03/06 16:43:54 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_through(char *cmdline, int **pfd_v, int i, char **paths)
{
	if (dup2(pfd_v[i - 1][0], 0) == -1)
	{
		perror("pipe_through -> dup2 pfdv_read");
		exit(EXIT_FAILURE);
	}
	close(pfd_v[i - 1][0]);
	if (dup2(pfd_v[i][1], 1) == -1)
	{
		perror("pipe_through -> dup2 pfdv_write");
		exit(EXIT_FAILURE);
	}
	close(pfd_v[i][1]);
	exec_cmd(paths, cmdline);
}
