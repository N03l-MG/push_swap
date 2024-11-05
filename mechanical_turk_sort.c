/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanical_turk_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:54:53 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/05 17:23:59 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_index(t_stack *stack);
static void	find_target(t_stack *a, t_stack *b);
static void	find_shift_cost(t_stack *a, t_stack *b);
static void	mark_cheapest(t_stack *a);
static void	push_setup(t_stack **src, t_stack **dst, int *ops);
static void	shift_to_top(t_stack **a, int index, int len, int *ops);
static void	find_return_target(t_stack *a, t_stack *b);

void	turk_sort(t_stack **a, t_stack **b, int *ops)
{
	int	a_size;

	a_size = ft_lstsize(*a);
	if (a_size-- > 3)
		pb(a, b, ops);
	if (a_size-- > 3)
		pb(a, b, ops);
	while (a_size-- > 3)
	{
		assign_index(a);
		assign_index(b);
		find_target(*a, *b);
		find_shift_cost(*a, *b);
		mark_cheapest(*a);
		push_setup(a, b, ops);
		pb(a, b, ops);
	}
	simple_sort(a, ops);
	while (*b)
	{
		find_return_target(*a, *b);
		push_setup(a, b, ops);
		pa(a, b, ops);
	}
}

static void	assign_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if(i <= median)
			stack->over_median = true;
		else
			stack->over_median = false;
		stack = stack->next;
		i++;
	}
}

static void	find_target(t_stack *a, t_stack *b)
{
	t_stack	*b_node;
	t_stack	*target_node;
	int		target_index;

	while (a)
	{
		target_index = -1;
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
		if (target_index == -1)
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
		if (a->index <= a_size / 2)
			a->cost = a_size - a->index;
		if (a->target->index <= a_size / 2)
			a->cost += a->target->index;
		else
			a->cost += (b_size - a->target->index);
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

static void push_setup(t_stack **src, t_stack **dst, int *ops)
{
	t_stack *cheapest_node;
	int src_size;

	src_size = ft_lstsize(*src);
	cheapest_node = *src;
	while (cheapest_node && !cheapest_node->cheapest)
		cheapest_node = cheapest_node->next;
	if (cheapest_node->index >= src_size / 2 && cheapest_node->target->index >= src_size / 2)
		rr(src, dst, ops);
	else if (cheapest_node->index < src_size / 2 && cheapest_node->target->index < src_size / 2)
		rrr(src, dst, ops);
	shift_to_top(src, cheapest_node->index, src_size, ops);
}

static void shift_to_top(t_stack **a, int index, int len, int *ops)
{
	int i;

	if (index <= len / 2)
	{
		i = 0;
		while (i++ < index)
			ra(a, ops);
	}
	else
	{
		i = 0;
		while (i++ < len - index)
			rra(a, ops);
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
