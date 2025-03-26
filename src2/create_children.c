/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_children.c                                   :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: terramint <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:26:12 by terramint         #+#    #+#             */
/*   Updated: 2025/03/26 19:26:08 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
bool	check_permissions(char *infile, char *outfile)
{
	if (access(infile, F_OK | R_OK) == -1)
	{
		perror("Infile insufficient requirements:");
		return (false);
	}
	if (access(outfile, W_OK) == -1 && access(outfile, F_OK) == 0)
	{
		perror("Outfile insuffcient requirements");
		return (false);
	}
	return (true);
}
int	create_children(int cmd_c, char *argv[], char *envp[], int* last_pid)
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
		if (!((i == 0 && access(argv[0], F_OK | R_OK)) || (i == cmd_c -1 && access(argv[cmd_c + 1], W_OK == -1))))
		{
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
					if (errno == ENOENT)
						exit(127);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	close(0);
	close(1);
	*last_pid = pid_t;
	return (0);
}
