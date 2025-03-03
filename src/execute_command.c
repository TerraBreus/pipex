/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   execute_command.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/03 16:52:26 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/03 16:55:35 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

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
	perror("File not found");
	exit(127);
}
