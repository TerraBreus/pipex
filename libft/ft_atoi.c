/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:15:16 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 15:54:11 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
Train of thought:
1. remove whitespace
2. check if nmbr negative
if yes, we make it neg later.
3. skip initial zeroes
4. go through string.
check how many digits2convert
5. 'for' loop with multplying sign. decimal
6. Make negative if needed.
NB: MAX_INT + 1 = MIN_INT
-2147483648 * -1 = 2147483648
2147483648 = 2147483647 + 1
2147483647 + 1 = -2147483648 
*/

static size_t	ft_get_length(const char *input)
{
	size_t	length;

	length = 0;
	if (*input >= '0' && *input <= '9')
	{
		length = 1;
		input++;
	}
	while (*input >= '0' && *input <= '9')
	{
		input++;
		length *= 10;
	}
	return (length);
}

static int	ft_calc_int(const char *str, size_t length, int conv_int)
{
	while (length)
	{
		conv_int += (*str - '0') * length;
		length /= 10;
		str++;
	}
	return (conv_int);
}

int	ft_atoi(const char *nptr)
{
	int			conv_int;
	int			is_minus;

	is_minus = 1;
	conv_int = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_minus *= -1;
		nptr++;
	}
	while (*nptr == '0')
		nptr++;
	conv_int = ft_calc_int(nptr, ft_get_length(nptr), conv_int);
	conv_int *= is_minus;
	return (conv_int);
}

// #include <unistd.h>

// int main()
// {
// 	printf("%d", ft_atoi("-2147483648"));
// }
