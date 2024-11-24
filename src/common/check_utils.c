/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:17:08 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/11 14:34:02 by nmonzon          ###   ########.fr       */
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

void	clear_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	handle_error(t_stack **a, t_stack **b)
{
	if (a && *a)
		clear_stack(a);
	if (b && *b)
		clear_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}
