/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simultaneous_rotation_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:42:47 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/13 17:47:36 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_rot(t_stack **a, t_stack **b, t_stack *cheap_node)
{
	while (*b != cheap_node->target && *a != cheap_node)
		rr(a, b);
	assign_index(*a);
	assign_index(*b);
}

void	rev_double_rot(t_stack **a, t_stack **b, t_stack *cheap_node)
{
	while (*b != cheap_node->target && *a != cheap_node)
		rrr(a, b);
	assign_index(*a);
	assign_index(*b);
}
