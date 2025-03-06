/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   close_and_free_pipes.c                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/06 14:48:08 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/06 15:07:57 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_and_free_pipes(int **pfd_v, int pipe_c)
{
	if (pfd_v != NULL)
	{
		while (0 <= --pipe_c)
		{
			close(pfd_v[pipe_c][0]);
			close(pfd_v[pipe_c][1]);
			if (pfd_v[pipe_c])
				free(pfd_v[pipe_c]);
		}
		free(pfd_v);
	}
}
