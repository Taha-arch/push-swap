/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-atou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 01:06:02 by tel-atou          #+#    #+#             */
/*   Updated: 2025/12/17 01:06:11 by tel-atou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (ac < 2)
        return (0);
    if (ac == 2 && av[1][0] == '\0')
        return (write(2, "Error\n", 6));
    else if (ac == 2)
    {
        av = ft_split(av[1]);
        init_stack(&a, av, ac == 2);
    }
    else
        init_stack(&a, av + 1, ac == 2);
    if (is_sorted(a))
    {
        free_list(&a);
        return (0);
    }
    assign_index(a);
    int size = stack_size(a);
    if (size == 2)
        sort_two(&a);
    else if (size == 3)
        sort_three(&a);
    else if (size <= 5)
        sort_five(&a, &b);
    else
        push_swap(&a, &b);

    free_list(&a);
    free_list(&b);
    return (0);
}
