/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_ps_unused.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:05:45 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/05 15:13:11 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Simple sort to determine ranks
static int	*bubble(int *values, int length)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (values[i] > values[j])
			{
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (values);
}

// Assigns ranks after parsing the input
static void	assign_ranks(t_stack *a)
{
	int		length;
	t_stack	*temp;
	int		*values;
	int		i;
	int		rank;

	temp = a;
	i = 0;
	rank = 0;
	length = ft_lstsize(temp);
	values = (int *)malloc(sizeof(int) * length);
	if (!values)
		return ;
	while (i < length)
	{
		values[i++] = *((int *)temp->content);
		temp = temp->next;
	}
	bubble(values, length);
	temp = a;
	while (temp)
	{
		rank = 0;
		while (rank < length && values[rank] != *((int *)temp->content))
			rank++;
		temp->index = rank;
		temp = temp->next;
	}
	free(values);
}

// Uses smart rotation to shift the next rank to the top of A
static void	shift_to_top(t_stack **a, int rank, int *ops)
{
	t_stack	*current;
	int		position;
	int		len;

	position = 0;
	current = *a;
	while (current)
	{
		if (current->index == rank)
			break ;
		current = current->next;
		position++;
	}
	current = *a;
	len = ft_lstsize(current);
	if (position <= len / 2)
	{
		for (int i = 0; i < position; i++)
			ra(a, ops);
	}
	else
	{
		for (int i = 0; i < len - position; i++)
			rra(a, ops);
	}
}

// Checks if the stack is sorted
static bool	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (*((int *)a->content) > *((int *)a->next->content))
			return (false);
		a = a->next;
	}
	return (true);
}

// Main algorithm function
void	push_swap_sort(t_stack **a, t_stack **b, int *ops)
{
	int	next_rank;

	next_rank = 0;
	assign_ranks(*a);
	if (is_sorted(*a))
		return ;
	while (*a)
	{
		shift_to_top(a, next_rank, ops);
		pb(a, b, ops);
		next_rank++;
	}
	while (*b)
		pa(a, b, ops);
}
