/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:34:07 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 12:28:46 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_of_dst;
	size_t	len_of_src;
	size_t	i;
	size_t	j;

	len_of_dst = ft_strlen(dst);
	len_of_src = ft_strlen(src);
	if (size <= len_of_dst)
	{
		return (size + len_of_src);
	}
	i = len_of_dst;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < size)
		dst[i] = '\0';
	return (len_of_dst + len_of_src);
}
