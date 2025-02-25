/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:42:15 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 12:05:50 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
Same as strchr but backwards.
Locates last occurance of
character c in string s.
*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	length;

	length = ft_strlen(s);
	while (length > 0)
	{
		if (s[length] == (char)c)
			return ((char *)(s + length));
		length--;
	}
	if (s[length] == (char)c)
		return ((char *)(s + length));
	return (NULL);
}
