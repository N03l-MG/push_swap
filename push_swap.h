/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:05:54 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/06 16:17:39 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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

bool	is_sorted(t_stack *a);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
void	assign_index(t_stack *stack);
void	double_rot(t_stack **a, t_stack **b, t_stack *cheap_node, int *ops);
void	rev_double_rot(t_stack **a, t_stack **b, t_stack *cheap_node, int *ops);
void	simple_sort(t_stack **a, int *ops);
void	turk_sort(t_stack **a, t_stack **b, int *ops);

#endif