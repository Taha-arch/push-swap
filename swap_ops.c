/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-atou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 06:12:33 by tel-atou          #+#    #+#             */
/*   Updated: 2025/12/17 06:13:34 by tel-atou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swaping(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    t_stack *third;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;
    third = second->next;

    second->prev = NULL;
    second->next = first;

    first->prev = second;
    first->next = third;

    if (third)
        third->prev = first;
    *stack = second;
}

void    sa(t_stack **a)
{
    swaping(a);
    write(1, "sa\n", 3);
}

void    sb(t_stack **b)
{
    swaping(b);
    write(1, "sb\n", 3);

}

void    ss(t_stack **a, t_stack **b)
{
    swaping(a);
    swaping(b);
    write(1, "ss\n", 3);
}