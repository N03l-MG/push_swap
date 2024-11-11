/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:01:37 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/11 14:52:28 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	execute_instructions(t_stack **a, t_stack **b);
static void	execute_instruction(t_stack **a, t_stack **b, char *instruction);
static int	ft_strcmp(char *s1, char *s2);

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && (!argv[1] || !ft_strcmp(argv[1], ""))))
		return (1);
	if (argc == 2)
		parse_input(ft_split(argv[1], ' '), &a, true);
	else
		parse_input(argv + 1, &a, false);
	execute_instructions(&a, &b);
	if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_stack(&a);
	return (0);
}

static void	execute_instructions(t_stack **a, t_stack **b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction != NULL)
	{
		execute_instruction(a, b, instruction);
		free(instruction);
		instruction = get_next_line(0);
	}
}

static void	execute_instruction(t_stack **a, t_stack **b, char *instruction)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rrr(a, b);
	else
		handle_error(a, b);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		ret = s1[i] - s2[i];
		if (ret != 0)
			break ;
		i++;
	}
	if (s1[i] == '\0' || s2[i] == '\0')
		ret = s1[i] - s2[i];
	return (ret);
}
