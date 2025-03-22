/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terramint <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:21:59 by terramint         #+#    #+#             */
/*   Updated: 2025/03/22 14:28:44 by terramint        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_permissions(char *infile, char *outfile, bool *outfile_exists)
{
	if (access(infile, F_OK | R_OK) == -1)
		return (-1);
	if (access(outfile, F_OK) == -1)
	{
		*outfile_exists = false;
		return (0);
	}
	if (access(outfile, W_OK) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	bool	outfile_exists;
	int	status;
	if (argc < 5)
	{
		ft_putstr_fd("Usage: <infile> <cmd> ... <cmd> <outfile>\n", 1);
		return (1);
	}
	outfile_exists = true;
	if (check_permissions(argv[1], argv[argc - 1], &outfile_exists) == -1)
		return (errno);
	if (create_children(argc - 3, ++argv, envp) != 0)
	{
		if (outfile_exists == false)
			unlink(argv[argc - 1]);
		return (errno);
	}
	wait(&status);
	if (WIFEXITED(status) != 0)
		return (WEXITSTATUS(status));
	return (0);
}
	
