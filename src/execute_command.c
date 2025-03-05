/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   execute_command.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/03 16:52:26 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/05 12:18:01 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_full_path(char *paths[], char *cmd)
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
	perror("File not found");
	exit(127);
}

void	exec_cmd(char **paths, char *cmdline)
{
	char	*path;
	char	**cmd_and_flags;
	int		pid;

	cmd_and_flags = ft_split(cmdline, ' ');
	path = find_full_path(paths, cmd_and_flags[0]);
	pid = fork();
	if (pid == 0)
		execve(path, cmd_and_flags, NULL);
	free(path);
	ft_free_vector(cmd_and_flags);
	if (pid == 0)
		exit(EXIT_FAILURE);
}
