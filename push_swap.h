/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-atou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 01:06:25 by tel-atou          #+#    #+#             */
/*   Updated: 2025/12/17 01:09:22 by tel-atou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdbool.h>

#include <stdio.h>


typedef struct s_stack {
	int	number;
	int	index;
	struct s_stack	*next;
	struct s_stack	*prev;
} t_stack;

char	**ft_split(char	*av);
void	init_stack(t_stack **a, char **av, bool ac_2);
t_stack	*find_last(t_stack *a);
void	add_node(t_stack **a, int number);
long	ft_atoi(char *str);
int	is_digit(char *number);
void	free_list(t_stack **a);
void	free_av(char **av);
void	print_error(t_stack **a, char **av, bool ac_2);

int	stack_size(t_stack *stack);
int	is_sorted(t_stack *a);
void	assign_index(t_stack *a);
t_stack	*find_max(t_stack *b);
int	get_position(t_stack *stack, t_stack *node);
void	sort_three(t_stack **a);
void	sort_two(t_stack **a);
t_stack	*find_min(t_stack *stack);
void	bring_to_top(t_stack **stack, t_stack *target, char name);
void	sort_five(t_stack **a, t_stack **b);
int	calculate_size_chunk(int size);
t_stack	*find_range(t_stack *stack, int min, int max);
void	chunking_b(t_stack **a, t_stack **b);
void	push_back_a(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b);

void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    pa(t_stack **b, t_stack **a);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);


#endif
