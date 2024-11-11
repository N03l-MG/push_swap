/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:05:45 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/11 18:59:31 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_valid_number(const char *str);
static void	check_duplicate(t_stack **a, int value, char **strs, bool malloced);
static bool	has_duplicate(t_stack *stack, int value);
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
		check_duplicate(a, value, strings, was_malloced);
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

static void	check_duplicate(t_stack **a, int value, char **strs, bool malloced)
{
	if (has_duplicate(*a, value))
	{
		free_strings(strs, malloced);
		handle_error(a, NULL);
	}
}

static bool	is_valid_number(const char *str)
{
	int			i;
	long long	result;
	bool		is_negative;

	i = 0;
	result = 0;
	is_negative = false;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '\0')
			return (false);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		result = result * 10 + (str[i] - '0');
		if ((result > INT_MAX) || (-(result) < INT_MIN))
			return (false);
		i++;
	}
	return (i > 0);
}

static bool	has_duplicate(t_stack *stack, int value)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (*((int *)current->content) == value)
			return (true);
		current = current->next;
	}
	return (false);
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
