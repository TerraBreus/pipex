/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:04:21 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 12:24:54 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
No need for casting since manual states:
These functions check whether c...
...which must have the value of an unsigned char

man ascii...
'0' is equal to 48
Practicing writing code in numerous
ways helps your understanding of it
*/

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
