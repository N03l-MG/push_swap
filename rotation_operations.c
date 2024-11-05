/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:16 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/05 16:00:14 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotates A forward
void	ra(t_stack **a, int *ops)
{
	t_stack	*first;

	if (a && *a && (*a)->next)
	{
		first = *a;
		*a = first->next;
		first->next = NULL;
		ft_lstadd_back(a, first);
		ft_printf("ra\n");
		(*ops)++;
	}
}

// Rotates B forward
void	rb(t_stack **b, int *ops)
{
	t_stack	*first;

	if (b && *b && (*b)->next)
	{
		first = *b;
		*b = first->next;
		first->next = NULL;
		ft_lstadd_back(b, first);
		ft_printf("rb\n");
		(*ops)++;
	}
}

// Simultaneous forward rotations
void	rr(t_stack **a, t_stack **b, int *ops)
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
		ft_printf("rr\n");
		(*ops)++;
	}
}

// Rotates A backward
void	rra(t_stack **a, int *ops)
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
		ft_printf("rra\n");
		(*ops)++;
	}
}

// Rotates B backward
void	rrb(t_stack **b, int *ops)
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
		ft_printf("rrb\n");
		(*ops)++;
	}
}

// Simultaneous backward rotations
void rrr(t_stack **a, t_stack **b, int *ops)
{
	t_stack	*previous;
	t_stack	*current;

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
	ft_printf("rrr\n");
	(*ops)++;
}
