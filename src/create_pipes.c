/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   create_pipes.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/03 11:43:17 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/03 15:44:07 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**create_pipes(int cmd_c)
{
	int	**pfd_v;
	int	i;

	pfd_v = (int **) malloc(sizeof(int *) * (cmd_c - 1));
	if (pfd_v == NULL)
	{
		perror("pfd_v malloc failure");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < (cmd_c - 1))
	{
		pfd_v[i] = (int *) malloc(sizeof(int) * 2);
		if (pfd_v[i] == NULL)
		{
			perror("pfd_v[i] malloc failure");
			exit(EXIT_FAILURE);
		}
		pipe(pfd_v[i]);
	}
	return (pfd_v);
}
