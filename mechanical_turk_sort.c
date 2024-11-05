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

static int	find_max(t_stack *stack);

void	simple_sort(t_stack **a, int ops)
{
	t_stack	*maximum;

	maximum = find_max(a);
	if (maximum == *a)
		ra(a, ops);
	else if ((*a)->next == maximum)
		rra(a, ops);
	if ((*a)->content > (*a)->next->content)
		sa(a, ops);
}

static int	find_max(t_stack *stack)
{
	int	current_value;
	int	maximum;

	current_value = 0;
	maximum = 0;
	while (stack)
	{
		current_value = *(int *)(stack->content);
		if (current_value > maximum)
			maximum = current_value;
		stack = stack->next;
	}
	return (maximum);
}

void	mt_sort(t_stack **a, t_stack **b, int *ops)
{
	initial_b_push(a, b, ops);
	find_target(a, b);
	find_shift_cost(a, b);
	mark_cheapest(a);

}

static void	initial_b_push(t_stack **a, t_stack **b, int *ops)
{
	if (ft_lstsize(a) > 4)
	{
		while (ft_lstsize(b) < 2)
			pb(a, b, ops);
	}
	else
		pb(a, b, ops);
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
			if (b_node->content < a->content && b_node->content > target_index)
			{
				target_index = b_node->content;
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
		if (a->target <= a_size / 2)
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

static void	move_to_target(t_stack **a, t_stack **b, int *ops)
{
	t_stack	*cheapest_node;
	int a_size;

	a_size = ft_lstsize(a);
	while (*a)
	{
		if ((*a)->cheapest)
		{
			cheapest_node = *a;
			break ;
		}
		*a = (*a)->next;
	}
	if (cheapest_node >= a_size / 2 && cheapest_node->target >= a_size / 2)
		rr(a, b, ops);
	else if (!(cheapest_node >= a_size / 2) && !(cheapest_node->target >= a_size / 2))
		rrr(a, b, ops);
	shift_to_top(a, ops);
}

static void	shift_to_top(t_stack **a, int *ops) // WORK IN PROGRESS
{
	
	if (position <= len / 2)
	{
		for (int i = 0; i < position; i++)
			ra(a, ops);
	}
	else
	{
		for (int i = 0; i < len - position; i++)
			rra(a, ops);
	}
}
