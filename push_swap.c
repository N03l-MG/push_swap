/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:05:45 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/06 13:55:34 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_input(const char **strings, t_stack **a);
static void	clear_stack(t_stack **stack);
//static void	print_output(t_stack *a, int ops);

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	int			ops;

	a = NULL;
	b = NULL;
	ops = 0;
	if (argc == 1 || (argc == 2 && !*argv))
		return (1);
	parse_input(ft_split(argv[1], ' '), &a);
	if (!is_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a, &ops);
		else if (ft_lstsize(a) == 3)
			simple_sort(&a, &ops);
		else
			turk_sort(&a, &b, &ops);
	}
	clear_stack(&a);
	return (0);
}

// Read user input and populate stack A
static void	parse_input(const char **strings, t_stack **a)
{
	int		value;
	int		i;
	int		j;
	t_stack	*new;

	i = 0;
	j = 0;
	while (strings[i] != NULL)
	{
		value = ft_atoi(strings[i]);
		new = ft_lstnew(malloc(sizeof(int)));
		if (!new)
		{
			clear_stack(a);
			while (strings[j])
				free(strings[j++]);
			free(strings);
			return ;
		}
		*((int *)new->content) = value;
		ft_lstadd_back(a, new);
		free(strings[i]);
		i++;
	}
	free(strings);
}

static void	clear_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->content);
		free(*stack);
		*stack = tmp;
	}
}

// static void	print_output(t_stack *a, int ops)
// {
// 	ft_printf("Output:\n");
// 	while (a)
// 	{
// 		ft_printf("%d ", *((int *)a->content));
// 		a = a->next;
// 	}
// 	ft_printf("\nTotal: %d\n", ops);
// }
