/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:49:47 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/13 17:59:22 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2 && ft_strlen(argv[1]) == 0)
		handle_error(&a, &b);
	if (argc == 2)
		parse_input(ft_split(argv[1], ' '), &a, true);
	else
		parse_input(argv + 1, &a, false);
	if (!is_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a);
		else if (ft_lstsize(a) == 3)
			simple_sort(&a);
		else
			turk_sort(&a, &b);
	}
	clear_stack(&a);
	return (0);
}
