/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   check_in_out_files.c                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/06 14:32:01 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/06 16:02:45 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_infile_outfile(char *infile, char *outfile)
{
	if (access(infile, F_OK | R_OK) == -1)
	{
		perror("check_infile");
		exit(EXIT_FAILURE);
	}
	if (access(outfile, F_OK) == -1)
		return ;
	if (access(outfile, W_OK) == -1)
	{
		perror("check_outfile");
		exit(EXIT_FAILURE);
	}
}
