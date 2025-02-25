/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:23:44 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 10:43:15 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
The manual states that if either 
dest or src are invalid/NULL pointer, behaviour is undefined.
Without the if statement on line 35, 
our function would not segv 
(both are NULL pointers -> NULL can still be NULL)
Same goes for ft_memcpy.c 
To see in practice, uncomment the main.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*copy_dest;
	const char	*copy_src;
	size_t		i;

	copy_dest = dest;
	copy_src = src;
	if ((!dest && !src) && n > 0)
		return (NULL);
	if (copy_src < copy_dest)
	{
		i = n;
		while (i--)
			copy_dest[i] = copy_src[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			copy_dest[i] = copy_src[i];
			i++;
		}
	}
	return (dest);
}

// #include <string.h>
// int main ()
// {
// 	void *test = NULL;
// 	char	*test2 = "Hello";
// 	char	test3[6] = "Hiiii";
// 	if (ft_memmove(test3, test, 2) == NULL)
// 		printf("Does mine work?");
// 	else
// 		printf("Oops?");
// 	// if (memmove(test, test2, 2) == NULL)
// 	// 	printf("Weird...");
// }