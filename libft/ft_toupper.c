/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:22:00 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 15:55:51 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
From the manual.
The standards require that the argument c 
is representable in the type unsigned char.
If the argument c is of type char,
it must be cast to unsigned char. (before calling the function).
Casting, therefore, is unnecessary...
man ascii
a is equal to 97 
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
