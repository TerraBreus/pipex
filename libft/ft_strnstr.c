/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:08:34 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 12:03:17 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
Note the condition (i+j) < len.
consider the following
big = hallhallo
little = hallo
len = 5

at the second 'h'the second
while loop would return succesfully
pointing to the second 'h'.
But we were only allowed to look in the first 5 elements.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len && big[i])
	{
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
		j = 0;
	}
	if (little[j] == '\0')
		return ((char *)&big[j]);
	return (NULL);
}
