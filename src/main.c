/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/03 10:46:23 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/03 15:51:56 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;

	if (argc < 5)
		return(0, usage());
	check_infile_outfile(argv[0], argv[argc]);
	paths = find_possible_paths(envp);
	pipex(argc - 3, argv, paths);
	ft_free_vector(paths);
	return(0);
}
