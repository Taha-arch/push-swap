/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-atou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 00:20:51 by tel-atou          #+#    #+#             */
/*   Updated: 2026/02/27 01:44:55 by tel-atou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_size_chunk(int size)
{
	if (size <= 100)
		return (size / 5);
	else
		return (size / 8 + 9);
}

t_stack	*find_range(t_stack *stack, int min, int max)
{
	while (stack != NULL)
	{
		if (stack->index >= min && stack->index < max)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	chunking_b(t_stack **a, t_stack **b)
{
	int		size;
	int		chunk_size;
	int		chunk_end;
	int		chunk_start;
	t_stack	*target;

	size = stack_size(*a);
	chunk_size = calculate_size_chunk(size);
	chunk_end = chunk_size;
	chunk_start = 0;
	while (*a)
	{
		target = find_range(*a, chunk_start, chunk_end);
		if (!target)
		{
			chunk_start = chunk_end;
			chunk_end += chunk_size;
			continue ;
		}
		bring_to_top(a, target, 'a');
		pb(a, b);
		handle_chunk_rotation(b, chunk_start, chunk_end);
	}
}

void	push_back_a_push_max(t_stack **a, t_stack **b)
{
	t_stack	*max;
	int		pos;

	while (*b)
	{
		max = find_max(*b);
		pos = get_position(*b, max);
		if (pos == 1)
			sb(b);
		else
			bring_to_top(b, max, 'b');
		pa(b, a);
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	chunking_b(a, b);
	push_back_a_push_max(a, b);
	bring_to_top(a, find_min(*a), 'a');
}
