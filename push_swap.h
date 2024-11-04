/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:05:54 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/04 13:04:08 by nmonzon          ###   ########.fr       */
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

#endif