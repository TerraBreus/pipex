/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:27:59 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 15:55:44 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
From the manual.
The standards require that the argument c 
is representable in the type unsigned char.
If the argument c is of type char,
it must be cast to unsigned char. (before calling the function).
Casting, therefore, is unnecessary.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
