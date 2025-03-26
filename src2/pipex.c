/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                             :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: terramint <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:21:59 by terramint         #+#    #+#             */
/*   Updated: 2025/03/26 19:21:36 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	bool	outfile_exists;
	int	status;
	int	last_pid;

	if (argc < 5)
	{
		ft_putstr_fd("Usage: <infile> <cmd> ... <cmd> <outfile>\n", 1);
		return (1);
	}
	outfile_exists = true;

	if (access(argv[argc - 1], F_OK) == -1)
		outfile_exists = false;
	last_pid = 0; 
	if (create_children(argc - 3, ++argv, envp, &last_pid) == -1)
	{
		if (outfile_exists == false)
			unlink(argv[argc - 1]);
		if (last_pid > 0)
		{
			waitpid(last_pid, &status, 0);
			while (wait(NULL) != -1);
			if (WIFEXITED(status) != 0)
				return (WEXITSTATUS(status));
		}
		while (wait(NULL) != -1);
		return (1);
	}

	waitpid(last_pid, &status, 0);
	while (wait(NULL) != -1);

	if (WIFEXITED(status) != 0)
		return (WEXITSTATUS(status));
	return (1);
}
	
