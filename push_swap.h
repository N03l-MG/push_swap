/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:05:54 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/08 18:47:27 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// Operations
void	sa(t_stack **a, int *ops);
void	sb(t_stack **b, int *ops);
void	ss(t_stack **a, t_stack **b, int *ops);
void	pa(t_stack **a, t_stack **b, int *ops);
void	pb(t_stack **a, t_stack **b, int *ops);
void	ra(t_stack **a, int *ops);
void	rb(t_stack **b, int *ops);
void	rr(t_stack **a, t_stack **b, int *ops);
void	rra(t_stack **a, int *ops);
void	rrb(t_stack **b, int *ops);
void	rrr(t_stack **a, t_stack **b, int *ops);

// Parsing
void	parse_input(char **strings, t_stack **a, bool was_malloced);

// Algorithm Utils
bool	is_sorted(t_stack *a);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
void	assign_index(t_stack *stack);

// Simultaneous Rotation Utils
void	double_rot(t_stack **a, t_stack **b, t_stack *cheap_node, int *ops);
void	rev_double_rot(t_stack **a, t_stack **b, t_stack *cheap_node, int *ops);

// Node Transfer Utils
void	find_shift_cost(t_stack *a, t_stack *b);
void	mark_cheapest(t_stack *a);
void	shift_to_top(t_stack **stack, t_stack *top_node, char name, int *ops);
void	final_shift(t_stack **a, int *ops);

// Sorts
void	simple_sort(t_stack **a, int *ops);
void	turk_sort(t_stack **a, t_stack **b, int *ops);

// Error Handling
void	clear_stack(t_stack **stack);
void	handle_error(t_stack **a, t_stack **b);

#endif
