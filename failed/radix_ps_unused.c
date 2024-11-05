/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:42:59 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/05 13:54:59 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	absolute(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static int	calc_max_bits(t_stack *a)
{
	int	maximum;
	int	result;
	int	current_value;

	maximum = 0;
	result = 0;
	while (a)
	{
		current_value = *(int *)(a->content);
		if (absolute(current_value) > maximum)
			maximum = absolute(current_value);
		a = a->next;
	}
	while ((maximum >> result) != 0)
		result++;
	return (result);
}

void	radix_sort(t_stack **a, t_stack **b, int *ops)
{
	int	size;
	int	bit;
	int	max_bits;
	int	i;
	int	top;

	size = ft_lstsize(*a);
	bit = 0;
	max_bits = calc_max_bits(*a);
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			top = *(int *)((*a)->content);
			if ((top >> bit) & 1)
				ra(a, ops);
			else
				pb(a, b, ops);
			i++;
		}
		while (*b)
			pa(a, b, ops);
		bit++;
	}
}
