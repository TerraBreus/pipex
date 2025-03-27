/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   utils.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/27 18:12:39 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/27 18:34:08 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	is_only_space(char *str)
{
	while (*str != '\0')
	{
		if (*str != ' ')
			return (false);
		str++;
	}
	return (true);
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		perror("error closing\n");
}
