#include "push_swap.h"

// Simultaneous backward rotations
void	rrr(t_stack **a, t_stack **b, int *ops)
{
	t_stack	*previous;
	t_stack	*current;

	previous = NULL;
	current = *a;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	if (previous)
		previous->next = NULL;
	ft_lstadd_front(a, current);
	previous = NULL;
	current = *b;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	if (previous)
		previous->next = NULL;
	ft_lstadd_front(b, current);
	ft_printf("rrr\n");
	(*ops)++;
}
