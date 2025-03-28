/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_children.c                                   :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: terramint <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:26:12 by terramint         #+#    #+#             */
/*   Updated: 2025/03/27 18:22:51 by zivanov        ########   odam.nl        */
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
	ft_close(STDIN_FILENO);
	ft_close(STDOUT_FILENO);
	return (return_status);
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
				if (i < cmd_c - 1)
					ft_close(saved_fd);
				child_operation(i, argv, envp);
			}
		}
	}
	*last_pid = pid_t;
	return (close_stdio_and_return(0));
}
