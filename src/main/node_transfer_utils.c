/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_transfer_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:22:37 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/13 17:49:28 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_node_cost(t_stack *node, int a_size, int b_size);

void	find_shift_cost(t_stack *a, t_stack *b)
{
	int	a_size;
	int	b_size;

	a_size = ps_stacksize(a);
	b_size = ps_stacksize(b);
	while (a)
	{
		a->cost = calculate_node_cost(a, a_size, b_size);
		a = a->next;
	}
}

static int	calculate_node_cost(t_stack *node, int a_size, int b_size)
{
	int	cost;

	cost = node->index;
	if (!node->over_median)
		cost = a_size - node->index;
	if (node->target->over_median)
		cost += node->target->index;
	else
		cost += b_size - node->target->index;
	return (cost);
}

void	mark_cheapest(t_stack *a)
{
	int		min_cost;
	t_stack	*cheapest_node;
	t_stack	*current;

	min_cost = INT_MAX;
	cheapest_node = NULL;
	current = a;
	while (current)
	{
		if (current->cost < min_cost)
		{
			min_cost = current->cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

void	shift_to_top(t_stack **stack, t_stack *top, char stack_id)
{
	while (*stack != top)
	{
		if (stack_id == 'a')
		{
			if (top->over_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_id == 'b')
		{
			if (top->over_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	final_shift(t_stack **a)
{
	while ((*a)->content != find_min(*a)->content)
	{
		if (find_min(*a)->over_median)
			ra(a);
		else
			rra(a);
	}
}
