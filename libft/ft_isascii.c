/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:42:31 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 12:23:34 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
No need for casting since manual states:
These functions check whether c...
...which must have the value of an unsigned char
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
