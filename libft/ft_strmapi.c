/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:28:17 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 11:53:40 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
Applies the function f to each character of the string str.
(str is the string s modified by the function f)
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	length;
	char	*str;

	length = ft_strlen(s);
	str = malloc(length + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[length] = '\0';
	return (str);
}
