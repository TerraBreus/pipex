/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:31:58 by zivanov           #+#    #+#             */
/*   Updated: 2024/10/23 15:55:13 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
Overall train of thought:
1. Create an array of strings
for the ammount of substrings.
2. Iterate through string.
Skip delimiter, if none-delimiter
iterate untill delimiter found again.
3. Extract substring and put pointer in array of strings.
4. Repeat from step 2 untill iterated through entire string.

Overall Notes:
Heavy use of ft_substr.

ft_count_substr:
Pretend you are already in delimiter (inbetween_substr = 1)
1. Iterate through string.
2. When word is found (none-delimeter):
ammount++
3. continue iteration untill delimiter found.
4. Repeat from step 1 untill iteration done.

ft_extract_substr notes:
Point to int for indexing (*i)
done for correct scope of variable.
'i' is used to iterate through 
entire string in ft_split.
*/

static size_t	ft_count_substr(char const *s, char c)
{
	size_t	ammount;
	int		inbetween_substr;

	ammount = 0;
	inbetween_substr = 1;
	while (*s)
	{
		if (inbetween_substr && *s != c)
		{
			ammount++;
			inbetween_substr = 0;
		}
		if (*s == c)
			inbetween_substr = 1;
		s++;
	}
	return (ammount);
}

static void	ft_free(char **str_squared, size_t current_index)
{
	size_t	i;

	i = 0;
	while (i < current_index)
	{
		free(str_squared[i]);
		i++;
	}
	free(str_squared);
}

static char	*extract_substr(const char *s, char c, size_t *i)
{
	size_t	start;
	size_t	len;

	start = *i;
	while (s[*i] != c && s[*i] != '\0')
		(*i)++;
	len = *i - start;
	return (ft_substr(s, start, len));
}

static int	check_for_fail(char **str_squared, size_t current_index)
{
	if (str_squared[current_index] == NULL)
	{
		ft_free(str_squared, current_index);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str_squared;
	size_t	i;
	size_t	current_index;

	str_squared = (char **)malloc((ft_count_substr(s, c) + 1) * sizeof(char *));
	if (str_squared == NULL)
		return (NULL);
	i = 0;
	current_index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			str_squared[current_index] = extract_substr(s, c, &i);
			if (check_for_fail(str_squared, current_index))
				return (NULL);
			current_index++;
		}
		else
			i++;
	}
	str_squared[current_index] = NULL;
	return (str_squared);
}
