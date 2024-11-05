#include "push_swap.h"

bool	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (*((int *)a->content) > *((int *)a->next->content))
			return (false);
		a = a->next;
	}
	return (true);
}

void	simple_sort(t_stack **a, int *ops)
{
	t_stack	*maximum;

	maximum = find_max(*a);
	if (maximum == *a)
		ra(a, ops);
	else if ((*a)->next == maximum)
		rra(a, ops);
	if ((*a)->content > (*a)->next->content)
		sa(a, ops);
}

t_stack *find_max(t_stack *stack)
{
    t_stack *maximum_node;

	if (!stack)
		return NULL;
	maximum_node = stack;
    while (stack)
    {
        if (*(int *)(stack->content) > *(int *)(maximum_node->content))
            maximum_node = stack;
        stack = stack->next;
    }
    return (maximum_node);
}

t_stack *find_min(t_stack *stack)
{
    t_stack *minimum_node = stack;

    while (stack)
    {
        if (*(int *)(stack->content) < *(int *)(minimum_node->content))
            minimum_node = stack;
        stack = stack->next;
    }
    return (minimum_node);
}
