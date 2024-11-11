/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:49:47 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/08 18:53:46 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2);

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	int			ops;

	a = NULL;
	b = NULL;
	ops = 0;
	if (argc == 1 || (argc == 2 && (!argv[1] || !ft_strcmp(argv[1], ""))))
		return (1);
	if (argc == 2)
		parse_input(ft_split(argv[1], ' '), &a, true);
	else
		parse_input(argv + 1, &a, false);
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
