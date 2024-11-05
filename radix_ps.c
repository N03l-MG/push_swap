#include "push_swap.h"

int	calc_max_bits(t_stack *a)
{
	int	maximum;
	int	max_bits;
	int	value;

	maximum = 0;
	max_bits = 0;
	while (a)
	{
		value = *(int *)(a->content);
		if (value > maximum)
			maximum = value;
		a = a->next;
	}
	while ((maximum >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(int max_bits, t_stack **a, t_stack **b, int *ops)
{
	int	size;
	int	bit;
	int	i;
	int	top;

	size = ft_lstsize(*a);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			top = *(int *)((*a)->content);
			if ((top >> bit) & 1)
				ra(a, ops);
			else
				pb(a, b, ops);
			i++;
		}
		while (*b)
			pa(a, b, ops);
		bit++;
	}
}
