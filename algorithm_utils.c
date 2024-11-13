/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:57:42 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/13 17:50:30 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (*((int *)a->content) > *((int *)a->next->content))
			return (false);
		a = a->next;
	}
	return (true);
}

void	simple_sort(t_stack **a)
{
	t_stack	*maximum;

	maximum = find_max(*a);
	if (maximum == *a)
		ra(a);
	else if ((*a)->next == maximum)
		rra(a);
	if (*((int *)(*a)->content) > *((int *)(*a)->next->content))
		sa(a);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*maximum_node;

	if (!stack)
		return (NULL);
	maximum_node = stack;
	while (stack)
	{
		if (*(int *)(stack->content) > *(int *)(maximum_node->content))
			maximum_node = stack;
		stack = stack->next;
	}
	return (maximum_node);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*minimum_node;

	if (!stack)
		return (NULL);
	minimum_node = stack;
	while (stack)
	{
		if (*(int *)(stack->content) < *(int *)(minimum_node->content))
			minimum_node = stack;
		stack = stack->next;
	}
	return (minimum_node);
}

void	assign_index(t_stack *stack)
{
	unsigned int	i;
	unsigned int	median_index;

	i = 0;
	median_index = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->over_median = (i <= median_index);
		stack = stack->next;
		i++;
	}
}
