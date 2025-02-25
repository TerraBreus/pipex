/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:21:43 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 11:37:26 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
Function gains its purpose mostly
from usage in other functions.
f.e see itoa edge case MIN_INT

(length + 1) for malloc is due to
null termination. null termination
is on position 'length' due to
arrays counting from 0.
*/

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*s_dup;
	int		i;

	length = ft_strlen(s);
	s_dup = (char *)malloc(length + 1);
	if (s_dup == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_dup[i] = s[i];
		i++;
	}
	s_dup[length] = '\0';
	return (s_dup);
}
