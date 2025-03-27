/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                             :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: terramint <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:21:59 by terramint         #+#    #+#             */
/*   Updated: 2025/03/27 15:49:48 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_usage(void)
{
	ft_putstr_fd("Usage: <infile> <cmd> ... <cmd> <outfile>\n", STDERR_FILENO);
	return (1);
}

bool	argv_has_empty_str(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i] != NULL)
	{
		if (argv[i][0] == '\0')
			return (true);
	}
	return (false);
}

int	ft_wait(int last_pid, int *status)
{
	if (last_pid > 0)
	{
		waitpid(last_pid, status, 0);
		while (wait(NULL) != -1)
			;
		if (WIFEXITED(*status) != 0)
			return (WEXITSTATUS(*status));
	}
	while (wait(NULL) != -1)
		;
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	bool	outfile_exists;
	int		status;
	int		last_pid;

	if (argc < 5 || argv_has_empty_str(argv) == true)
		return (ft_usage());
	outfile_exists = true;
	if (access(argv[argc - 1], F_OK) == -1)
		outfile_exists = false;
	last_pid = 0;
	if (create_children(argc - 3, ++argv, envp, &last_pid) == -1)
	{
		if (outfile_exists == false)
			unlink(argv[argc - 1]);
		return (ft_wait(last_pid, &status));
	}
	return (ft_wait(last_pid, &status));
}
