/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:05:54 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/13 17:45:52 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	void			*content;
	unsigned int	index;
	int				cost;
	bool			over_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

// Stack manipulation (adapted from libft lst functions)
t_stack	*ps_stacktnew(void *content);
int		ps_stacksize(t_stack *lst);
void	ps_stackadd_top(t_stack **lst, t_stack *new);
void	ps_stackadd_bottom(t_stack **lst, t_stack *new);

// Operations
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// Parsing
void	parse_input(char **strings, t_stack **a, bool was_malloced);

// Algorithm Utils
bool	is_sorted(t_stack *a);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
void	assign_index(t_stack *stack);

// Simultaneous Rotation Utils
void	double_rot(t_stack **a, t_stack **b, t_stack *cheap_node);
void	rev_double_rot(t_stack **a, t_stack **b, t_stack *cheap_node);

// Node Transfer Utils
void	find_shift_cost(t_stack *a, t_stack *b);
void	mark_cheapest(t_stack *a);
void	shift_to_top(t_stack **stack, t_stack *top_node, char name);
void	final_shift(t_stack **a);

// Sorts
void	simple_sort(t_stack **a);
void	turk_sort(t_stack **a, t_stack **b);

// Error Handling
void	clear_stack(t_stack **stack);
void	handle_error(t_stack **a, t_stack **b);

#endif
