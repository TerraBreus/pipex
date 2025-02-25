/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:29:13 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 12:23:30 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
No need for casting since manual states:
These functions check whether c...
...which must have the value of an unsigned char
*/

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122)
		|| (c >= 65 && c <= 90))
	{
		return (1);
	}
	else
		return (0);
}

// int main()
// {
// 	char	test1;

// 	test1 = 123;
// 	printf("%d", ft_isalpha(test1));
// 	return (0);
// }