/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:05:59 by kixik             #+#    #+#             */
/*   Updated: 2024/11/13 17:46:28 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_fprintf(1, "sa\n");
	}
}

// Swaps first two in B (UNUSED)
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
		ft_fprintf(1, "sb\n");
	}
}

// Swaps first two in A and B simultaneously (UNUSED)
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
		ft_fprintf(1, "ss\n");
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
		ft_fprintf(1, "pa\n");
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
		ft_fprintf(1, "pb\n");
	}
}
