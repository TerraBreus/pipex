/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipex.h                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/03 10:39:35 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/06 15:50:42 by zivanov        ########   odam.nl        */
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
# include "../libft/libft.h"

void	pipex(int cmd_c, char *argv[], char **paths);
int		**create_pipes(int cmd_c);
void	exec_cmd(char **paths, char *cmdline);
void	ft_free_vector(char **strv);
char	**create_possible_paths(char *envp[]);
void	pipe_in(int infile_fd, char *cmdline, int pfd_write, char **paths);
void	pipe_out(int outfile_fd, char *cmdline, int pfd_read, char **paths);
void	pipe_through(char *cmdline, int **pfd_v, int i, char **paths);
void	check_infile_outfile(char *infile, char *outfile);
void	close_and_free_pipes(int **pfd_v, int pipe_c);
void	close_files(int infile_fd, int outfile_fd);

#endif
