/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terramint <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:21:59 by terramint         #+#    #+#             */
/*   Updated: 2025/03/22 13:31:19 by terramint        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
//	int	infile_fd;
//	int	outfile_fd;
//	bool	outfile_exist;
	int	status;
	if (argc < 5)
	{
		ft_putstr_fd("Usage: <infile> <cmd> ... <cmd> <outfile>\n", 1);
		return (1);
	}
//	outfile_exist = true;
	//Write function to check permissions infile & outfile.
	//If outfile does not exist, set outfile_exist to false.

	if (create_children(argc - 3, ++argv, envp) != 0)
		return (errno);
	wait(&status);
	return (status);
}
	
