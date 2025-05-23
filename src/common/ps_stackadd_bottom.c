/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:37:12 by kixik             #+#    #+#             */
/*   Updated: 2024/11/04 11:15:25 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stackadd_bottom(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
