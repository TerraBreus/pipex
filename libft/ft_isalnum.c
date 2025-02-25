/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:31:51 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 12:23:26 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
No need for casting since manual states:
These functions check whether c...
...which must have the value of an unsigned char
*/

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

// int main()
// {
// 	char	test1;

// 	test1 = 'A';
// 	printf("%d", ft_isalnum(test1));
// 	return (0);
// }