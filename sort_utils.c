/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-atou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 00:20:51 by tel-atou          #+#    #+#             */
/*   Updated: 2025/12/24 00:27:00 by tel-atou         ###   ########.fr       */
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

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int	size;

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
	int	size = stack_size(*a);
	int	chunk_size = calculate_size_chunk(size);
	int	chunk_end = chunk_size;
	int	chunk_start = 0;

	while (*a)
	{
		t_stack	*target = find_range(*a, chunk_start, chunk_end);
		if (!target)
		{
			chunk_start = chunk_end;
			chunk_end += chunk_size;
			continue; 
		}
		bring_to_top(a, target, 'a');
		pb(a, b);

		if (*b && (*b)->next)
		{
			int	median = chunk_start + (chunk_end - chunk_start) / 2;
			if ((*b)->index < median)
				rb(b);
		}
	}
}

t_stack	*find_target_a(t_stack *a, int index_b)
{
	t_stack	*target;
	t_stack	*tmp;
	int	smallest_big;

	target = NULL;
	smallest_big = INT_MAX;
	tmp = a;

	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < smallest_big)
		{
			smallest_big = tmp->index;
			target = tmp;
		}
		tmp = tmp->next;
	}
	if (!target)
		target = find_min(a);
	return (target);
}

int	cheapest_cost(t_stack *a, t_stack *b, t_stack *b_node)
{
	int	cost;
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;
	t_stack	*target_a;

	cost = 0;
	size_a = stack_size(a);
	size_b = stack_size(b);

	pos_b = get_position(b, b_node);
	if (pos_b <= size_b / 2)
		cost += pos_b;
	else
		cost += (size_b - pos_b);
	target_a = find_target_a(a, b_node->index);
	pos_a = get_position(a, target_a);
	if (pos_a <= size_a / 2)
		cost += pos_a;
	else
		cost += (size_a - pos_a);

	cost += 1;
	return (cost);
}

void	execute_move(t_stack **a, t_stack **b, t_stack *cheapest)
{
	t_stack	*target_a;
	int	pos_b;
	int	pos_a;
	int	size_a;
	int	size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	target_a = find_target_a(*a, cheapest->index);

	pos_b = get_position(*b, cheapest);
	if (pos_b <= size_b / 2)
	{
		while (*b != cheapest)
			rb(b);
	}
	else
	{
		while (*b != cheapest)
			rrb(b);
	}

	pos_a = get_position(*a, target_a);
	if (pos_a <= size_a / 2)
	{
		while (*a != target_a)
			ra(a);
	}
	else
	{
		while (*a != target_a)
			rra(a);
	}
	pa(b, a);
}

void	push_back_a(t_stack **a, t_stack **b)
{
	t_stack *cheapest;
	t_stack	*tmp;
	int	min_cost;
	int	cost;

	while (*b)
	{
		tmp = *b;
		cheapest = *b;
		min_cost = cheapest_cost(*a, *b, *b);

		while (tmp)
		{
			cost = cheapest_cost(*a, *b, tmp);
			if (cost < min_cost)
			{
				min_cost = cost;
				cheapest = tmp;
			}
			tmp = tmp->next;
		}
		execute_move(a, b, cheapest);
	}
}

void	push_back_a_push_max(t_stack **a, t_stack **b)
{
	t_stack	*max;
	int	pos;

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
	if (size <= 100)
		push_back_a_push_max(a, b);
	else
		push_back_a(a, b);

	bring_to_top(a, find_min(*a), 'a');
}

