/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:25:22 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 15:54:56 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include "libft.h"

static int	ft_get_digits(size_t n)
{
	int	digits;

	digits = 1;
	n /= 10;
	while (n)
	{
		digits *= 10;
		n /= 10;
	}
	return (digits);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		digits;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	digits = ft_get_digits(n);
	while (digits)
	{
		c = (n / digits) + '0';
		write(fd, &c, 1);
		n %= digits;
		digits /= 10;
	}
}
