/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:44:05 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/07 17:44:07 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}
