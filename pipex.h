/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipex.h                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/10 18:06:59 by zivanov        #+#    #+#                */
/*   Updated: 2025/02/19 15:44:58 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include "./libft/libft.h"

char	**create_possible_paths(char *envp[]);
char	*find_full_path(char *paths[], char *cmd);
void	ft_freev(char *strv[]);
void	new_process(char **paths, char *cmd_str);
void	child_processes(char *infile, char *cmd1, char *cmd2, char *outfile, char **paths);
#endif
