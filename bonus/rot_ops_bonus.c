/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:16 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/06 13:54:14 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Rotates A forward
void	ra(t_stack **a)
{
	t_stack	*first;

	if (a && *a && (*a)->next)
	{
		first = *a;
		*a = first->next;
		first->next = NULL;
		ft_lstadd_back(a, first);
	}
}

// Rotates B forward
void	rb(t_stack **b)
{
	t_stack	*first;

	if (b && *b && (*b)->next)
	{
		first = *b;
		*b = first->next;
		first->next = NULL;
		ft_lstadd_back(b, first);
	}
}

// Simultaneous forward rotations
void	rr(t_stack **a, t_stack **b)
{
	t_stack	*a_first;
	t_stack	*b_first;

	if ((a && *a && (*a)->next) && (b && *b && (*b)->next))
	{
		a_first = *a;
		*a = a_first->next;
		a_first->next = NULL;
		ft_lstadd_back(a, a_first);
		b_first = *b;
		*b = b_first->next;
		b_first->next = NULL;
		ft_lstadd_back(b, b_first);
	}
}

// Rotates A backward
void	rra(t_stack **a)
{
	t_stack	*previous;
	t_stack	*current;

	if (a && *a && (*a)->next)
	{
		previous = NULL;
		current = *a;
		while (current->next)
		{
			previous = current;
			current = current->next;
		}
		if (previous)
			previous->next = NULL;
		ft_lstadd_front(a, current);
	}
}

// Rotates B backward
void	rrb(t_stack **b)
{
	t_stack	*previous;
	t_stack	*current;

	if (b && *b && (*b)->next)
	{
		previous = NULL;
		current = *b;
		while (current->next)
		{
			previous = current;
			current = current->next;
		}
		if (previous)
			previous->next = NULL;
		ft_lstadd_front(b, current);
	}
}
