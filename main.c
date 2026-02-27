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

void	process_and_init(t_stack **a, char **av, int ac)
{
	char	**split;
	int		i;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i]);
		if (!split)
			print_error(a, NULL, false);
		init_stack(a, split, true);
		free_av(split);
		i++;
	}
}

char	**parse_args(int ac, char **av, t_stack **a)
{
	char	**split;

	if (ac == 2 && av[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (ac == 2)
	{
		split = ft_split(av[1]);
		init_stack(a, split, true);
		return (split);
	}
	process_and_init(a, av, ac);
	return (NULL);
}

void	do_sort(t_stack **a, t_stack **b)
{
	int	size;

	assign_index(*a);
	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		push_swap(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**split;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	split = parse_args(ac, av, &a);
	if (is_sorted(a))
	{
		free_list(&a);
		if (split)
			free_av(split);
		return (0);
	}
	do_sort(&a, &b);
	free_list(&a);
	free_list(&b);
	if (split)
		free_av(split);
	return (0);
}
