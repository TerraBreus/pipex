/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:13:32 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 10:46:38 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	length;

	length = ft_strlen((const char *)s);
	write(fd, s, length);
}

// int main()
// {
// 	ft_putstr_fd("Hello", 1);
// 	return (0);
// }