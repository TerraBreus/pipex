/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_path.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/11 09:04:39 by zivanov        #+#    #+#                */
/*   Updated: 2025/02/19 15:43:16 by zivanov        ########   odam.nl        */
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

char	*find_full_path(char *paths[], char *cmd)
{
	char	*full_dir;
	char	*dir;
	int		i;

	if ((paths == NULL) || (cmd == NULL))
		return (perror("find_full_path: input is NULL"), NULL);
	dir = ft_strjoin("/", cmd);
	if (dir == NULL)
		return (perror("dir malloc"), NULL);
	i = -1;
	while (paths[++i])
	{
		full_dir = ft_strjoin(paths[i], dir);
		if (full_dir == NULL)
			return (free(dir), perror("full_dir malloc"), NULL);
		if (access(full_dir, X_OK | F_OK) == 0)
			return (free(dir), full_dir);
		free(full_dir);
	}
	free(dir);
	return (perror("File not found"), NULL);
}
