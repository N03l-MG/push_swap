/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:37:26 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/04 11:15:25 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*last;

	last = NULL;
	if (!lst)
		last = lst;
	else
	{
		while (lst)
		{
			last = lst;
			lst = lst->next;
		}
	}
	return (last);
}
