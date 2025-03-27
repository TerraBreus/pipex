/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                          :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: terramint <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:02:34 by terramint         #+#    #+#             */
/*   Updated: 2025/03/27 18:23:39 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_full_path(char *paths[], char *cmd)
{
	char	*addendum;
	char	*path;
	int		i;

	if (paths == NULL)
		return (ft_strdup(cmd));
	addendum = ft_strjoin("/", cmd);
	if (addendum == NULL)
		return (NULL);
	i = -1;
	while (paths[++i] != NULL)
	{
		path = ft_strjoin(paths[i], addendum);
		if (path == NULL)
			return (free(addendum), NULL);
		if (access(path, F_OK) == 0)
			return (free(addendum), path);
		free(path);
	}
	free(addendum);
	return (ft_strdup(cmd));
}

char	**create_possible_paths(char *envp[])
{
	int		i;
	char	**possible_paths;

	i = -1;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			break ;
	}
	if (envp[i] == NULL)
		return (envp);
	possible_paths = ft_split(envp[i] + 5, ':');
	if (possible_paths == NULL)
		return (NULL);
	return (possible_paths);
}

void	free_paths(char **possible_paths)
{
	int		i;

	i = -1;
	if (possible_paths != NULL)
	{
		while (possible_paths[++i] != NULL)
			free(possible_paths[i]);
		free(possible_paths);
	}
}

int	exec_cmd(char *cmdline, char *envp[])
{
	char	**cmd_and_flags;
	char	**possible_paths;
	char	*path;

	possible_paths = create_possible_paths(envp);
	if (possible_paths == NULL)
		return (-1);
	if (possible_paths == envp)
		possible_paths = NULL;
	if (is_only_space(cmdline) == true)
		cmd_and_flags = ft_split(cmdline, ':');
	else
		cmd_and_flags = ft_split(cmdline, ' ');
	if (cmd_and_flags == NULL)
		return (free_paths(possible_paths), -1);
	path = find_full_path(possible_paths, cmd_and_flags[0]);
	free_paths(possible_paths);
	if (path == NULL)
		return (free_paths(cmd_and_flags), -1);
	execve(path, cmd_and_flags, envp);
	perror(path);
	free(path);
	free_paths(cmd_and_flags);
	return (127);
}

void	child_operation(int i, char **argv, char **envp)
{
	int	err_code;

	err_code = exec_cmd(argv[i + 1], envp);
	ft_close(STDIN_FILENO);
	ft_close(STDOUT_FILENO);
	if (err_code == 127)
		exit(127);
	exit(EXIT_FAILURE);
}
