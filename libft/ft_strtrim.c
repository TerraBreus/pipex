/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:47:51 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 15:55:32 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_is_in_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str_trimmed;

	start = 0;
	i = 0;
	while (ft_is_in_set(s1[start], set) && (s1[start] != '\0'))
		start++;
	end = ft_strlen(s1);
	if (start == end)
		return (ft_strdup(""));
	while (ft_is_in_set(s1[end - 1], set))
		end--;
	str_trimmed = (char *)malloc(end - start + 1);
	if (str_trimmed == NULL)
		return (NULL);
	while (start + i < end)
	{
		str_trimmed[i] = s1[start + i];
		i++;
	}
	str_trimmed[i] = '\0';
	return (str_trimmed);
}
