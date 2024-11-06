/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanical_turk_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:54:53 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/06 16:03:04 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_target(t_stack *a, t_stack *b);
static void	find_shift_cost(t_stack *a, t_stack *b);
static void	mark_cheapest(t_stack *a);
static void	push_setup(t_stack **src, t_stack **dst, int *ops);
static void shift_to_top(t_stack **stack, t_stack *top_node, char name, int *ops);
static void	find_return_target(t_stack *a, t_stack *b);
static void	final_shift(t_stack **a, int *ops);

void	turk_sort(t_stack **a, t_stack **b, int *ops)
{
	int	a_size;

	a_size = ft_lstsize(*a);
	if (a_size-- > 3 && !is_sorted(*a))
		pb(a, b, ops);
	if (a_size-- > 3 && !is_sorted(*a))
		pb(a, b, ops);
	while (a_size-- > 3 && !is_sorted(*a))
	{
		assign_index(*a);
		assign_index(*b);
		find_target(*a, *b);
		find_shift_cost(*a, *b);
		mark_cheapest(*a);
		push_setup(a, b, ops);
		pb(a, b, ops);
	}
	simple_sort(a, ops);
	while (*b)
	{
		assign_index(*a);
		assign_index(*b);
		find_return_target(*a, *b);
		shift_to_top(a, (*b)->target, 'a', ops);
		pa(a, b, ops);
	}
	assign_index(*a);
	final_shift(a, ops);
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
			if (*((int *)b_node->content) < *(int *)a->content && *((int *)b_node->content) > target_index)
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

static void	find_shift_cost(t_stack *a, t_stack *b)
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

static void	mark_cheapest(t_stack *a)
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

static void push_setup(t_stack **a, t_stack **b, int *ops)
{
	t_stack *cheapest_node;
	int a_size;

	a_size = ft_lstsize(*a);
	cheapest_node = *a;
	while (cheapest_node && !cheapest_node->cheapest)
		cheapest_node = cheapest_node->next;
	if (cheapest_node->over_median && cheapest_node->target->over_median)
		double_rot(a, b, cheapest_node, ops);
	else if (!(cheapest_node->over_median) && !(cheapest_node->target->over_median))
		rev_double_rot(a, b, cheapest_node, ops);
	shift_to_top(a, cheapest_node, 'a', ops);
	shift_to_top(b, cheapest_node->target, 'b', ops);
}

static void shift_to_top(t_stack **stack, t_stack *top_node, char name, int *ops)
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

static void find_return_target(t_stack *a, t_stack *b)
{
	t_stack *a_node;
	t_stack *target_node;
	int target_index;

	while (b)
	{
		target_index = INT_MAX;
		a_node = a;
		while (a_node)
		{
			if (*((int *)a_node->content) > *(int *)b->content && *((int *)a_node->content) < target_index)
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

static void	final_shift(t_stack **a, int *ops)
{
	while ((*a)->content != find_min(*a)->content)
	{
		if(find_min(*a)->over_median)
			ra(a, ops);
		else
			rra(a, ops);
	}
}
