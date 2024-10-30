#include "push_swap.h"

// Swaps first two in A
void sa(t_list **a)
{
	t_list *first;
	t_list *second;

	if (a && *a && (*a)->next)
	{
		first = *a;
		second = (*a)->next;
		first->next = second->next;
		second->next = first;
		*a = second;
	}
	ft_printf("sa\n");
}

// Swaps first two in B
void sb(t_list **b)
{
	t_list *first;
	t_list *second;

	if (b && *b && (*b)->next)
	{
		first = *b;
		second = (*b)->next;
		first->next = second->next;
		second->next = first;
		*b = second;
	}
	ft_printf("sb\n");
}

// Simultaneous swaps
void ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}

// Pushes first element from B to A
void pa(t_list **a, t_list **b)
{
	t_list *first;

	first = *b;
	*b = (*b)->next;
	first->next = *a;
	*a = first;
	ft_printf("pa\n");
}

// Pushes first element from A to B
void pb(t_list **a, t_list **b)
{
	t_list *first;

	first = *a;
	*a = (*a)->next;
	first->next = *b;
	*b = first;
	ft_printf("pb\n");
}

// Rotates A forward
void ra(t_list **a)
{
	t_list *first;

	if (a && *a && (*a)->next)
	{
		first = *a;
		*a = first->next;
		first->next = NULL;
		ft_lstadd_back(a, first);
		ft_printf("ra\n");
	}
}

// Rotates B forward
void rb(t_list **b)
{
	t_list *first;

	if (b && *b && (*b)->next)
	{
		first = *b;
		*b = first->next;
		first->next = NULL;
		ft_lstadd_back(b, first);
	}
	ft_printf("rb\n");
}

// Simultaneous forward rotations
void rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

// Rotates A backward
void rra(t_list **a)
{
	t_list *previous;
	t_list *current;

	if (a && *a && (*a)->next)
	{
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
	}
	ft_printf("rra\n");
}

// Rotates B backward
void rrb(t_list **b)
{
	t_list *previous;
	t_list *current;

	if (b && *b && (*b)->next)
	{
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
	}
	ft_printf("rrb\n");
}

// Simultaneous backward rotations
void rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
