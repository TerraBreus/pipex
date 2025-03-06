/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/03 10:46:23 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/06 15:51:52 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	usage(void)
{
	ft_putstr_fd("Usage: ./pipex [infile] [cmd_1 \
	cmd_2 ... cmd_n] [outfile]\n", 1);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;

	if (argc < 5)
		return (usage(), 0);
	check_infile_outfile(argv[0], argv[argc]);
	paths = create_possible_paths(envp);
	pipex(argc - 3, argv, paths);
	ft_free_vector(paths);
	return (0);
}
