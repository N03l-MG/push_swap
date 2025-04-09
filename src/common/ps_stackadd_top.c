/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:37:08 by kixik             #+#    #+#             */
/*   Updated: 2024/11/04 11:15:25 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stackadd_top(t_stack **lst, t_stack *new)
{
	t_stack	*previous;
	t_stack	*current;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	previous = NULL;
	while (current)
	{
		previous = current;
		current = current->next;
	}
	previous->next = new;
}
