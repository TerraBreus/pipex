/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:54:58 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/21 17:06:21 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

/*
malloc but instead of using sizeof() we make a product.
(also we make sure we 'nulify' the dedotaded wam)
NB: We check for overflow by dividing by size.
However if we divide by zero (fe size = 0)
we get undefined behaviour.
Hence the extra statement. 
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	product;
	size_t	i;
	void	*ptr;

	i = 0;
	product = nmemb * size;
	if (size != 0)
	{
		if (product / size != nmemb)
			return (NULL);
	}
	ptr = malloc(product);
	if (ptr == NULL)
		return (NULL);
	while (i < product)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

// int main()
// {
// 	void *ptr = calloc(2, 5);
// 	free(ptr);
// 	return (0);
// }