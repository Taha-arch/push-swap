/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-atou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 02:13:20 by tel-atou          #+#    #+#             */
/*   Updated: 2026/02/27 02:17:04 by tel-atou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*big;

	big = find_max(*a);
	if (big == *a)
	{
		ra(a);
		if ((*a)->number > (*a)->next->number)
			sa(a);
	}
	else if (big == (*a)->next)
	{
		rra(a);
		if ((*a)->number > (*a)->next->number)
			sa(a);
	}
	else
	{
		if ((*a)->number > (*a)->next->number)
			sa(a);
	}
}

void	sort_two(t_stack **a)
{
	if ((*a)->number > (*a)->next->number)
		sa(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int		size;

	size = stack_size(*a);
	while (size > 3)
	{
		min = find_min(*a);
		bring_to_top(a, min, 'a');
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(b, a);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;

	if (stack == NULL)
		return (NULL);
	min = stack;
	while (stack != NULL)
	{
		if (stack->index < min->index)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	bring_to_top(t_stack **stack, t_stack *target, char name)
{
	int	pos;
	int	size;

	pos = get_position(*stack, target);
	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while (*stack != target)
		{
			if (name == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while (*stack != target)
		{
			if (name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}
