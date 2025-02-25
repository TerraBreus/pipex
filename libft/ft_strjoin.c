/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:00:43 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 11:50:07 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
Train of Thought (choochoo)
1. take length of both strings
2. allocate for its sum + 1 for null termination
3. iterate through string 1 and copy
4. iterate through string 2 and copy
nb: note indexing (i+j) of strjoined
5. null terminate
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;
	char	*strjoined;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strjoined = (char *)malloc(len_s1 + len_s2 + 1);
	if (strjoined == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		strjoined[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		strjoined[i + j] = s2[j];
		j++;
	}
	strjoined[i + j] = '\0';
	return (strjoined);
}
