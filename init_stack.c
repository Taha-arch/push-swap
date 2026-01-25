/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-atou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 02:20:31 by tel-atou          #+#    #+#             */
/*   Updated: 2025/12/17 03:05:12 by tel-atou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	long	res;
	int	sign;
	int	i;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
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

t_stack	*find_last(t_stack *a)
{
	t_stack	*last;

	if (a == NULL)
		return (NULL);
	last = a;
	while (last->next != NULL)
	{
		last = last->next;	
	}
	return (last);
}

void	add_node(t_stack **a, int number)
{
	t_stack	*this_node;
	t_stack	*last_node;


	if (a == NULL)
		return ;
	this_node = malloc(sizeof(t_stack));
	if (!this_node)
		return ;
	if (*a == NULL)
	{
		this_node->prev = NULL;
		*a = this_node;
	}
	else
	{
		last_node = find_last(*a);
		this_node->prev = last_node;
		last_node->next = this_node;
	}
	this_node->next = NULL;
	this_node->number = number;

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

void	print_error(t_stack **a, char **av, bool ac_2)
{
	free_list(a);
	if (ac_2)
		free_av(av);
	write(2, "Error\n", 6);
	exit(1);
}

int	is_duplicated(t_stack *a, long number)
{
	while (a != NULL)
	{
		if (a->number == number)
			return (1);
		a = a->next;
	}
	return (0);
}

void	init_stack(t_stack **a, char **av, bool ac_2)
{
	int	i;
	long	number;

	if (!av)
		print_error(a, av,  ac_2);
	i = 0;
	while (av[i])
	{
		if (is_digit(av[i]) == 1)
		{
			print_error(a, av, ac_2);
		}
		number = ft_atoi(av[i]);
		if (number < INT_MIN || number > INT_MAX)
			print_error(a, av, ac_2);
		if (is_duplicated(*a, number))
			print_error(a, av, ac_2);
		add_node(a, (int)number);
		i++;
	}
}
