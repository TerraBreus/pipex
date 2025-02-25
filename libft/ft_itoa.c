/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:47:10 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 15:54:43 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

/*
Small rerouting of code
with ft_itoa and ft_act_itoa
(act stands for actual since it converts)
due to complications with norminette.
*/

static int	ft_get_decimals(size_t amm_decimals)
{
	int	decimals;

	decimals = 1;
	if (amm_decimals == 0)
		return (0);
	if (amm_decimals == 1)
		return (decimals);
	while (amm_decimals - 1 > 0)
	{
		decimals *= 10;
		amm_decimals--;
	}
	return (decimals);
}

static size_t	ft_get_amm_decimals(int n)
{
	size_t	amm_decimals;

	amm_decimals = 0;
	while (n)
	{
		amm_decimals++;
		n /= 10;
	}
	return (amm_decimals);
}

static char	*ft_act_itoa(int n, size_t amm_decimals, size_t is_neg)
{
	char	*n_str;
	int		decimals;

	decimals = ft_get_decimals(amm_decimals);
	n_str = (char *)malloc(amm_decimals + is_neg + 1);
	if (n_str == NULL)
		return (NULL);
	n_str[amm_decimals + is_neg] = '\0';
	if (is_neg)
	{
		n_str[0] = '-';
		n *= -1;
	}
	while (n)
	{
		n_str[amm_decimals + is_neg - 1] = (n % 10) + '0';
		n /= 10;
		amm_decimals--;
	}
	return (n_str);
}

char	*ft_itoa(int n)
{
	size_t	amm_decimals;
	size_t	is_neg;

	is_neg = 0;
	if (n == 0)
		return (ft_strdup("0"));
	amm_decimals = ft_get_amm_decimals(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n > 0)
		return (ft_act_itoa(n, amm_decimals, is_neg));
	else
	{
		is_neg = 1;
		return (ft_act_itoa(n, amm_decimals, is_neg));
	}
}
