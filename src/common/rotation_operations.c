/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:16 by kixik             #+#    #+#             */
/*   Updated: 2024/11/13 17:46:54 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotates A forward
void	ra(t_stack **a)
{
	t_stack	*first;

	if (a && *a && (*a)->next)
	{
		first = *a;
		*a = first->next;
		first->next = NULL;
		ps_stackadd_top(a, first);
		ft_fprintf(1, "ra\n");
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
		ps_stackadd_top(b, first);
		ft_fprintf(1, "rb\n");
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
		ps_stackadd_top(a, a_first);
		b_first = *b;
		*b = b_first->next;
		b_first->next = NULL;
		ps_stackadd_top(b, b_first);
		ft_fprintf(1, "rr\n");
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
		ps_stackadd_bottom(a, current);
		ft_fprintf(1, "rra\n");
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
		ps_stackadd_bottom(b, current);
		ft_fprintf(1, "rrb\n");
	}
}
