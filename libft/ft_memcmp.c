/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:28:17 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 10:13:34 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
Simple memory comparing.
Manual states that each byte (n)
is interpreted as an unsigned char.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_byte;
	const unsigned char	*s2_byte;

	s1_byte = s1;
	s2_byte = s2;
	i = 0;
	while (i < n)
	{
		if (s1_byte[i] != s2_byte[i])
			return (s1_byte[i] - s2_byte[i]);
		i++;
	}
	return (0);
}

// void	tester(int result)
// {
// 	if (result == 0)
//     printf("Arrays are equal.\n");
//     else
//         printf("Arrays are different, memcmp result: %d\n", result);
// }

// int	main()
// {
// 	char arr1[] = { 'a', 'b', 'c', 'd' };

// 	//Example 1: Similar strings
// 	tester(ft_memcmp(arr1, arr1, 4));

// 	//Example 2: Different strings.
// 	char arr2[] = { 'a', 'b', 'x', 'd' };
// 	tester(ft_memcmp(arr1, arr2, 4));
// 	// Example 3: Partial comparison
// 	tester(ft_memcmp(arr1, arr2, 2));
// 	return (0);
// }