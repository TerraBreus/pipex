/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:39:36 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 10:43:05 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
The manual states that if either 
dest or src are invalid/NULL pointer, behaviour is undefined.
Without the if statement on line 34, 
our function would not segv 
(both are NULL pointers -> NULL can still be NULL)
Same goes for ft_memmove.c 
To see in practice, uncomment the main.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*cpy_dest;
	const char	*cpy_src;

	cpy_src = src;
	cpy_dest = dest;
	i = 0;
	if ((!dest && !src) && n > 0)
		return (NULL);
	while (i < n)
	{
		*cpy_dest = *cpy_src;
		cpy_dest++;
		cpy_src++;
		i++;
	}
	return (dest);
}

// #include <string.h>
// int main ()
// {
// 	void *test = NULL;
// 	char	*test2 = "Hello";
// 	if (ft_memcpy(test, test2, 2) == NULL)
// 		printf("Does mine work?");
// 	else
// 		printf("Oops?");
// 	// if (memcpy(test, test2, 2) == NULL)
// 	// 	printf("Weird...");
// }