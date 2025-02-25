/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   new_process.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/12 16:17:06 by zivanov        #+#    #+#                */
/*   Updated: 2025/02/19 15:43:40 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Questionable name for function.
void	new_process(char **paths, char *cmd_str)
{
	char	**argv;
	char	*pathname;

	argv = ft_split(cmd_str, ' ');
	pathname = find_full_path(paths, argv[0]);
	execve(pathname, argv, NULL);
	free(pathname);
	ft_freev(argv);
}
