/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terramint <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:02:34 by terramint         #+#    #+#             */
/*   Updated: 2025/03/21 15:38:41 by terramint        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_full_path(char *paths[], char *cmd)
{
	char	*addendum;
	char	*path;
	int	i;

	addendum = ft_strjoin("/", cmd);
	if (addendum == NULL)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], addendum);
		if (path == NULL)
		{
			free(addendum);
			return (NULL);
		}
		if (access(path, X_OK | F_OK) == 0)
		{
			free(addendum);
			return (path);
		}
		free(path);
	}
	free(addendum);
	ft_putstr_fd("Error: command not found.", 2);
	return (NULL);
}
void	free_paths(char **possible_paths)
{
	int	i;
	
	i = -1;
	while (possible_paths[++i] != NULL)
		free(*possible_paths);
	free(possible_paths);
}

int	exec_cmd(char *cmdline, char *envp[])
{
	char	**cmd_and_flags;
	char	**possible_paths;
	char	*path;

	possible_paths = create_possible_paths(envp);
	if (possible_paths == NULL)
		return (-1);
	cmd_and_flags = ft_split(cmdline, ' ');
	if (cmd_and_flags == NULL)
	{
		free_paths(possible_paths);
		return (-1);
	}
	path = find_full_path(possible_paths, cmd_and_flags[0]);
	free_paths(possible_paths);
	if (path == NULL)
	{
		free(cmd_and_flags);
		return (-1);
	}
	execve(path, cmd_and_flags, envp)
	free(path);
	free_paths(cmd_and_flags);
	return (-1);
}
	
