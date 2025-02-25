/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:59:18 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 10:45:16 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
fills the first n bytes 
with constant byte c.
Casting c into char
to force interpretation
as single byte.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = s;
	while (i < n)
	{
		*cpy = (char)c;
		cpy++;
		i++;
	}
	return (s);
}
