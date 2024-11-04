/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:05:45 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/04 15:55:22 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_input(const char *input, t_stack **a);
static void	assign_ranks(t_stack *a);
static int	*bubble(int *values, int length);
static void	shift_to_top(t_stack **a, int rank, int *ops);
static bool	is_sorted(t_stack *a);
static void	push_swap_sort(t_stack **a, t_stack **b, int *ops);
static void	print_stacks(t_stack *a, t_stack *b);

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	const char	*input;
	int			ops;

	a = NULL;
	b = NULL;
	ops = 0;
	if (argc < 2)
		return (1);
	input = argv[1];
	parse_input(input, &a);
	push_swap_sort(&a, &b, &ops);
	ft_printf("Output:\n");
	while (a)
	{
		ft_printf("%d ", *((int *)a->content));
		a = a->next;
	}
	ft_printf("\nTotal: %d\n", ops);
	return (0);
}

// Read user input and populate stack A
static void	parse_input(const char *input, t_stack **a)
{
	int		value;
	char	**strings;
	int		i;
	int		j;
	t_stack	*new;

	i = 0;
	j = 0;
	strings = ft_split(input, ' ');
	ft_printf("Input:\n");
	while (strings[i] != NULL)
	{
		value = ft_atoi(strings[i]);
		new = ft_lstnew(malloc(sizeof(int)));
		if (!new)
		{
			while (j < i)
				free(strings[j]);
			free(strings);
			return ;
		}
		*((int *)new->content) = value;
		ft_lstadd_back(a, new);
		ft_printf("%d ", *((int *)new->content));
		free(strings[i]);
		i++;
	}
	ft_printf("\n");
	free(strings);
}

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
	values = malloc(sizeof(int) * length);
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
		temp->rank = rank;
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
		if (current->rank == rank)
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
static void	push_swap_sort(t_stack **a, t_stack **b, int *ops)
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
		//print_stacks(*a, *b);
	}
	while (*b)
		pa(a, b, ops);
	//print_stacks(*a, *b);
}

// static void print_stacks(t_stack *a, t_stack *b)
// {
// 	ft_printf("__________");
// 	while (a)
// 	{
// 		ft_printf("  %d    %d  ", *((int *)a->content), *((int *)b->content));
// 		a = a->next;
// 		b = b->next;
// 	}
// 	ft_printf("__A____B__");
// }
