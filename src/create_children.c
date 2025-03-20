/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terramint <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:26:12 by terramint         #+#    #+#             */
/*   Updated: 2025/03/20 19:42:47 by terramint        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	create_children(int cmd_c, char *argv[], char *envp[])
{
	int	infile_fd;
	int	outfile_fd;
	int	pid_t;
	int	i;

	infile_fd = open(argv[0]);
	if (infile_fd == -1)
		return (-1);
	outfile_fd = open(argv[cmd_c + 1]);
	if (outfile_fd == -1)
	{
		close(infile_fd);
		return (-1);
	}
	i = -1;
	while (++i < cmd_c)
	{
		if (setup_std_in_out(i, cmd_c, infile_fd, outfile_fd) == -1)
		{
			close(0);
			close(1);
			return (-1);
		}
		pid_t = fork();
		if (pid_t == -1)
		{
			close(0);
			close(1);
			return (-1);
		}
		if (pid_t == 0)
		{
			if (exec_cmd(arg[i + 1], envp) == -1)
			{
				close(0);
				close(1);
				return (-1);
			}
		}
	}
	close(0);
	close(1);
	return (0);
}
