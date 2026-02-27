/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-atou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 01:23:45 by tel-atou          #+#    #+#             */
/*   Updated: 2025/12/17 01:55:31 by tel-atou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_separator(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	count_words(char *av)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (av[i])
	{
		while (av[i] && is_separator(av[i]))
			i++;
		if (av[i])
		{
			count++;
			while (av[i] && !is_separator(av[i]))
				i++;
		}
	}
	return (count);
}

char	*copy_word(int start, int end, char *av)
{
	int		i;
	char	*res;

	res = malloc(end - start + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
	{
		res[i++] = av[start++];
	}
	res[i] = '\0';
	return (res);
}

char	**ft_spliting(char *av, int start, char	**res)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		while (av[i] && is_separator(av[i]))
			i++;
		start = i;
		while (av[i] && !is_separator(av[i]))
			i++;
		if (start < i)
		{
			res[j++] = copy_word(start, i, av);
			if (!res[j - 1])
			{
				while (j > 0)
					free(res[--j]);
				free(res);
				return (NULL);
			}
		}
	}
	return (res);
}

char	**ft_split(char	*av)
{
	int		words;
	int		start;
	char	**res;

	words = count_words(av);
	if (!words)
		return (NULL);
	start = 0;
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res = ft_spliting(av, start, res);
	if (!res)
		return (NULL);
	res[words] = NULL;
	return (res);
}
