/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:37:15 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/04 11:15:25 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*temp;

	while (*lst)
	{
		del((*lst)->content);
		temp = (*lst)->next;
		free (*lst);
		*lst = temp;
	}
	*lst = NULL;
}
