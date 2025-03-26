/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_children.c                                   :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: terramint <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:26:12 by terramint         #+#    #+#             */
/*   Updated: 2025/03/26 13:55:35 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	create_children(int cmd_c, char *argv[], char *envp[])
{
	int	pid_t;
	int	i;
	int	saved_fd;

	i = -1;
	while (++i < cmd_c)
	{
		if (setup_std_in_out(i, cmd_c, argv, &saved_fd) == -1)
		{
			close(0);
			close(1);
			return (-1);
		}
		pid_t = fork();
		if (pid_t == -1)
		{
			perror("Forking failed. Closing all file descriptors:");
			setup_std_in_out(-1, cmd_c, argv, &saved_fd);
			close(0);
			close(1);
			return (-1);
		}
		if (pid_t == 0)
		{
			if (i < cmd_c -1)
				close(saved_fd);
			if (exec_cmd(argv[i + 1], envp) == -1)
			{
				close(0);
				close(1);
				exit(EXIT_FAILURE);
			}
		}
	}
	close(0);
	close(1);
	return (pid_t);
}
