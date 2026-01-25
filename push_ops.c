/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-atou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 07:39:33 by tel-atou          #+#    #+#             */
/*   Updated: 2025/12/17 07:40:00 by tel-atou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pushing(t_stack **from, t_stack **to)
{
    t_stack *tmp;

    if (!from || !*from)
        return ;
    tmp = *from;
    *from = (*from)->next;

    if (*from)
        (*from)->prev = NULL;

    tmp->next = *to;
    if (*to)
        (*to)->prev = tmp;
    tmp->prev = NULL;
    *to = tmp;
}

void    pa(t_stack **b, t_stack **a)
{
    pushing(b, a);
    write(1, "pa\n", 3);
}

void    pb(t_stack **a, t_stack **b)
{
    pushing(a, b);
    write(1, "pb\n", 3);
}
