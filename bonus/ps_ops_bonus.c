/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:05:59 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/06 16:48:16 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Swaps first two in A
void	sa(t_stack **a)
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
	}
}

// Swaps first two in B
void	sb(t_stack **b)
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
	}
}

// Swaps first two in A and B simultaneously
void	ss(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if ((a && *a && (*a)->next) && (b && *b && (*b)->next))
	{
		first = *a;
		second = (*a)->next;
		first->next = second->next;
		second->next = first;
		*a = second;
		first = *b;
		second = (*b)->next;
		first->next = second->next;
		second->next = first;
		*b = second;
	}
}

// Pushes first element from B to A
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*first;

	if (b && *b)
	{
		first = *b;
		*b = (*b)->next;
		first->next = *a;
		*a = first;
	}
}

// Pushes first element from A to B
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*first;

	if (a && *a)
	{
		first = *a;
		*a = (*a)->next;
		first->next = *b;
		*b = first;
	}
}
