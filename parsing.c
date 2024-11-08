/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:05:45 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/08 18:50:27 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_valid_number(const char *str);
static void	free_strings(char **strings, bool was_malloced);

// Read user input and populate stack A
void	parse_input(char **strings, t_stack **a, bool was_malloced)
{
	int		value;
	int		i;
	t_stack	*new;

	i = 0;
	while (strings[i] != NULL)
	{
		if (!is_valid_number(strings[i]))
		{
			free_strings(strings, was_malloced);
			handle_error(a, NULL);
		}
		value = ft_atoi(strings[i]);
		new = ft_lstnew(malloc(sizeof(int)));
		if (!new)
		{
			free_strings(strings, was_malloced);
			handle_error(a, NULL);
		}
		*((int *)new->content) = value;
		ft_lstadd_back(a, new);
		i++;
	}
	free_strings(strings, was_malloced);
}

static bool	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (i > 0);
}

static void	free_strings(char **strings, bool was_malloced)
{
	int	i;

	i = 0;
	if (was_malloced)
	{
		while (strings[i])
		{
			free(strings[i]);
			i++;
		}
		free(strings);
	}
	else
		return ;
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
	ft_printf("Error\n");
	exit(1);
}
