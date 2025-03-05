/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   free.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/05 09:38:33 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/05 11:29:56 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_vector(char **strv)
{
	int	i;

	i = -1;
	while (strv[++i])
		free(strv[i]);
	free(strv);
}
