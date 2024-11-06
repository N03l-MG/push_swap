/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_transfer_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:22:37 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/06 16:57:18 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_shift_cost(t_stack *a, t_stack *b)
{
	int	a_size;
	int	b_size;

	a_size = ft_lstsize(a);
	b_size = ft_lstsize(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->over_median))
			a->cost = a_size - (a->index);
		if (a->target->over_median)
			a->cost += a->target->index;
		else
			a->cost += b_size - (a->target->index);
		a = a->next;
	}
}

void	mark_cheapest(t_stack *a)
{
	int		cheapest_cost;
	t_stack	*cheapest_node;

	cheapest_cost = INT_MAX;
	while (a)
	{
		if (a->cost < cheapest_cost)
		{
			cheapest_cost = a->cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = true;
}

void	shift_to_top(t_stack **stack, t_stack *top_node, char name, int *ops)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->over_median)
				ra(stack, ops);
			else
				rra(stack, ops);
		}
		else if (name == 'b')
		{
			if (top_node->over_median)
				rb(stack, ops);
			else
				rrb(stack, ops);
		}
	}
}

void	final_shift(t_stack **a, int *ops)
{
	while ((*a)->content != find_min(*a)->content)
	{
		if (find_min(*a)->over_median)
			ra(a, ops);
		else
			rra(a, ops);
	}
}
