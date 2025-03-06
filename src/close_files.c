/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   close_files.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/06 15:06:17 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/06 15:51:15 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_files(int infile_fd, int outfile_fd)
{
	close(infile_fd);
	close(outfile_fd);
}
