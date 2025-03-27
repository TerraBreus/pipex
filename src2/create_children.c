/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_children.c                                   :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: terramint <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:26:12 by terramint         #+#    #+#             */
/*   Updated: 2025/03/27 14:21:04 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	check_permissions(int i, int cmd_c, char **argv)
{
	if (i == 0)
	{
		if (access(argv[0], F_OK | R_OK) == -1)
		{
			perror("Infile insufficient requirements:");
			return (false);
		}
	}
	else if (i == cmd_c - 1)
	{
		if (access(argv[cmd_c + 1], W_OK) == -1 \
			&& access(argv[cmd_c + 1], F_OK) == 0)
		{
			perror("Outfile insuffcient requirements");
			return (false);
		}
	}
	return (true);
}

int	close_stdio_and_return(int return_status)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	return (return_status);
}

void	execfail_exit(void)
{
	close_stdio_and_return(0);
	if (errno == ENOENT)
		exit(127);
	exit(EXIT_FAILURE);
}

int	fork_failure(int *saved_fd)
{
	perror("Forking failed. Closing all file descriptors:");
	setup_std_in_out(-1, 0, NULL, saved_fd);
	return (close_stdio_and_return(-1));
}

int	create_children(int cmd_c, char *argv[], char *envp[], int *last_pid)
{
	int	pid_t;
	int	i;
	int	saved_fd;

	i = -1;
	while (++i < cmd_c)
	{
		if (setup_std_in_out(i, cmd_c, argv, &saved_fd) == -1)
			return (close_stdio_and_return(-1));
		if (check_permissions(i, cmd_c, argv) == true)
		{
			pid_t = fork();
			if (pid_t == -1)
				return (fork_failure(&saved_fd));
			if (pid_t == 0)
			{
				if (i < cmd_c -1)
					close(saved_fd);
				if (exec_cmd(argv[i + 1], envp) == -1)
					execfail_exit();
			}
		}
	}
	*last_pid = pid_t;
	return (close_stdio_and_return(0));
}
