/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:39:46 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/21 17:16:56 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
Memchr: find a specific character 
(starting from the left)
and return its position.
Weird prototyping asks us to
use int c even though we
want to use it as 
unsigned char.
Thus we learned about
casting...
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*cpy_s;

	cpy_s = s;
	i = 0;
	while (i < n)
	{
		if (cpy_s[i] == (unsigned char)c)
			return ((void *)(cpy_s + i));
		i++;
	}
	return (NULL);
}
