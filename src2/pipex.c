/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                             :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: terramint <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:21:59 by terramint         #+#    #+#             */
/*   Updated: 2025/03/26 14:01:00 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_permissions(char *infile, char *outfile, bool *outfile_exists)
{
	if (access(infile, F_OK | R_OK) == -1)
		perror("Infile insufficient requirements:");
	if (access(outfile, F_OK) == -1)
		*outfile_exists = false;
	if (access(outfile, W_OK) == -1)
		perror("Outfile not writable");
}

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
	check_permissions(argv[1], argv[argc - 1], &outfile_exists);
	
	last_pid = create_children(argc - 3, ++argv, envp);
	if (last_pid == -1)
	{
		if (outfile_exists == false)
			unlink(argv[argc - 1]);
		return (1);
	}

	waitpid(last_pid, &status, 0);

	int	i;
	i = 0;
	while (i < argc - 4)
	{
		int pid_w;
		ft_putstr_fd("waiting for children\n", 2);
		pid_w = wait(NULL);
		i++;
	}

	if (WIFEXITED(status) != 0)
		return (WEXITSTATUS(status));
	return (1);
}
	
