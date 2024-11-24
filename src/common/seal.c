/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:44:05 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/13 17:47:12 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Simultaneous backward rotations
void	rrr(t_stack **a, t_stack **b)
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
	ps_stackadd_bottom(a, current);
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
	ft_fprintf(1, "rrr\n");
}
