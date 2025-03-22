/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/03 10:39:35 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/22 12:12:07 by terramint        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/wait.h>
# include "../libft/libft.h"

int	setup_std_in_out(int cmd_i, int cmd_c, int infile_fd, int outfile_fd);
int	create_children(int cmd_c, char *argv[], char *envp[]);
int	exec_cmd(char *cmdline, char *envp[]);
#endif
