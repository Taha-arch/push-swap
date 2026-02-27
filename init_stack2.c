/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-atou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 02:11:48 by tel-atou          #+#    #+#             */
/*   Updated: 2026/02/27 02:12:44 by tel-atou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > (INT_MAX - (str[i] - '0')) / 10)
			return ((long)INT_MAX + 1);
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

int	is_digit(char *number)
{
	int	i;

	i = 0;
	if (!number || number[0] == '\0')
		return (1);
	if (number[i] == '+' || number[i] == '-')
		i++;
	if (number[i] == '\0')
		return (1);
	while (number[i])
	{
		if (!(number[i] >= '0' && number[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	free_list(t_stack **a)
{
	t_stack	*tmp;

	while (*a != NULL)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

void	free_av(char **av)
{
	int	i;

	if (av == NULL)
		return ;
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
