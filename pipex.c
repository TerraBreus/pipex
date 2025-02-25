/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                             :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: terrabuntu <terrabuntu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:30:02 by zivanov           #+#    #+#             */
/*   Updated: 2025/02/19 15:47:43 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;
	int		pid;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 1);
		return (0);
	}
	if (access(argv[1], F_OK | R_OK))
	{
		perror("access infile");
		return (-1);
	}
	paths = create_possible_paths(envp);
	if (paths == NULL)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		child_processes(argv[1], argv[2], argv[3], argv[4], paths);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, NULL, 0);
	ft_freev(paths);
	return (0);
}
