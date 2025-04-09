/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:54:53 by kixik             #+#    #+#             */
/*   Updated: 2024/11/13 17:48:15 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_a_nodes(t_stack **a, t_stack **b);
static void	find_target(t_stack *a, t_stack *b);
static void	push_setup(t_stack **a, t_stack **b);
static void	find_return_target(t_stack *a, t_stack *b);

void	turk_sort(t_stack **a, t_stack **b)
{
	if (ps_stacksize(*a) > 3 && !is_sorted(*a))
		pb(a, b);
	if (ps_stacksize(*a) > 3 && !is_sorted(*a))
		pb(a, b);
	while (ps_stacksize(*a) > 3 && !is_sorted(*a))
	{
		assign_index(*a);
		assign_index(*b);
		process_a_nodes(a, b);
		pb(a, b);
	}
	simple_sort(a);
	while (*b)
	{
		assign_index(*a);
		assign_index(*b);
		find_return_target(*a, *b);
		shift_to_top(a, (*b)->target, 'a');
		pa(a, b);
	}
	assign_index(*a);
	final_shift(a);
}

static void	process_a_nodes(t_stack **a, t_stack **b)
{
	find_target(*a, *b);
	find_shift_cost(*a, *b);
	mark_cheapest(*a);
	push_setup(a, b);
}

static void	find_target(t_stack *a, t_stack *b)
{
	t_stack	*b_node;
	t_stack	*target_node;
	int		target_index;

	while (a)
	{
		target_index = INT_MIN;
		b_node = b;
		while (b_node)
		{
			if (*((int *)b_node->content) < *(int *)a->content
				&& *((int *)b_node->content) > target_index)
			{
				target_index = *((int *)b_node->content);
				target_node = b_node;
			}
			b_node = b_node->next;
		}
		if (target_index == INT_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

static void	push_setup(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = *a;
	while (cheapest_node && !cheapest_node->cheapest)
		cheapest_node = cheapest_node->next;
	if (cheapest_node->over_median && cheapest_node->target->over_median)
		double_rot(a, b, cheapest_node);
	else if (!(cheapest_node->over_median)
		&& !(cheapest_node->target->over_median))
		rev_double_rot(a, b, cheapest_node);
	shift_to_top(a, cheapest_node, 'a');
	shift_to_top(b, cheapest_node->target, 'b');
}

static void	find_return_target(t_stack *a, t_stack *b)
{
	t_stack	*a_node;
	t_stack	*target_node;
	int		target_index;

	while (b)
	{
		target_index = INT_MAX;
		a_node = a;
		while (a_node)
		{
			if (*((int *)a_node->content) > *(int *)b->content
				&& *((int *)a_node->content) < target_index)
			{
				target_index = *((int *)a_node->content);
				target_node = a_node;
			}
			a_node = a_node->next;
		}
		if (target_index == INT_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}
