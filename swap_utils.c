/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-atou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:10:05 by tel-atou          #+#    #+#             */
/*   Updated: 2025/12/24 00:08:06 by tel-atou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		count;
	t_stack	*tmp;

	if (stack == NULL)
		return (0);
	count = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	if (a == NULL)
		return (1);
	tmp = a;
	while (tmp->next != NULL)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	assign_index(t_stack *a)
{
	int		index;
	t_stack	*tmp;
	t_stack	*head;

	if (a == NULL)
		return ;
	head = a;
	while (head != NULL)
	{
		tmp = a;
		index = 0;
		while (tmp != NULL)
		{
			if (head->number > tmp->number)
				index++;
			tmp = tmp->next;
		}
		head->index = index;
		head = head->next;
	}
}

t_stack	*find_max(t_stack *b)
{
	t_stack	*max;

	if (b == NULL)
		return (NULL);
	max = b;
	while (b != NULL)
	{
		if (b->number > max->number)
			max = b;
		b = b->next;
	}
	return (max);
}

int	get_position(t_stack *stack, t_stack *node)
{
	int		pos;
	t_stack	*tmp;

	if (!stack || !node)
		return (-1);
	pos = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp == node)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}
