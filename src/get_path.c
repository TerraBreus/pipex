/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_path.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/05 09:19:48 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/05 09:31:14 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_possible_paths(char *envp[])
{
	int		i;
	char	**possible_paths;

	i = -1;
	while (ft_strncmp("PATH=", envp[++i], 5) != 0)
	{
		if (envp[i] == NULL)
			return (perror("No path parameter found\n"), NULL);
	}
	possible_paths = ft_split(envp[i] + 5, ':');
	if (possible_paths == NULL)
		return (perror("possible_paths malloc"), NULL);
	return (possible_paths);
}
