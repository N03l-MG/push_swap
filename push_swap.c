/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:05:45 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/05 15:20:50 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_input(const char *input, t_stack **a);
static bool	is_sorted(t_stack *a);
static void	print_output(t_stack *a, int ops);

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	int			ops;

	a = NULL;
	b = NULL;
	ops = 0;
	if (argc < 2)
		return (1);
	parse_input(argv[1], &a);
	if (!is_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a, ops);
		else if (ft_lstsize == 3)
			simple_sort(&a, ops);
		else
			mt_sort(&a, &b, ops);
	}
	print_output(a, ops);
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

static void	print_output(t_stack *a, int ops)
{
	ft_printf("Output:\n");
	while (a)
	{
		ft_printf("%d ", *((int *)a->content));
		a = a->next;
	}
	ft_printf("\nTotal: %d\n", ops);
}
