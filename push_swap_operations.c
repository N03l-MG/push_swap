/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:05:59 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/04 14:36:42 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swaps first two in A
void	sa(t_stack **a, int *ops)
{
	t_stack	*first;
	t_stack	*second;

	if (a && *a && (*a)->next)
	{
		first = *a;
		second = (*a)->next;
		first->next = second->next;
		second->next = first;
		*a = second;
		ft_printf("sa\n");
		(*ops)++;
	}
}

// Swaps first two in B
void	sb(t_stack **b, int *ops)
{
	t_stack	*first;
	t_stack	*second;

	if (b && *b && (*b)->next)
	{
		first = *b;
		second = (*b)->next;
		first->next = second->next;
		second->next = first;
		*b = second;
		ft_printf("sb\n");
		(*ops)++;
	}
}

// Pushes first element from B to A
void	pa(t_stack **a, t_stack **b, int *ops)
{
	t_stack	*first;

	if (b && *b)
	{
		first = *b;
		*b = (*b)->next;
		first->next = *a;
		*a = first;
		ft_printf("pa\n");
		(*ops)++;
	}
}

// Pushes first element from A to B
void	pb(t_stack **a, t_stack **b, int *ops)
{
	t_stack	*first;

	if (b && *b)
	{
		first = *a;
		*a = (*a)->next;
		first->next = *b;
		*b = first;
		ft_printf("pb\n");
		(*ops)++;
	}
}
