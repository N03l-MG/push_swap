#include "push_swap.h"

int	main(char *argv[], int argc)
{
	t_list *a;
	t_list *b;
	// input parsing crap
	push_swap(a, b);
}

void push_swap(t_list **a, t_list **b)
{
	bool is_sorted = false;
	// loop that checks if sorted
	if (!is_sorted)
	{
		ps_quicksort(a, b);
	}
}

t_list *ps_quicksort(t_list **a, t_list **b)
{
	if (!a || !*a || !(*a)->next)
        return *a;
    int length = ft_lstsize(*a);
    int pivot = find_pivot(*a, length);

    divide(a, b, pivot);
    ps_quicksort(a, b);
    ps_quicksort(b, a);

    while (*b)
        pa(a, b);
    return *a;
}

int find_pivot(t_list *list, int length)
{
	int *values = malloc(length * sizeof(int));
	int i = 0;
	int j = 0;
	int temp = 0;
	t_list *current = list;
	int pivot = 0;

	while (current && i < length)
	{
		values[i] = *((int *)current->content);
		current = current->next;
		i++;
	}
	i = 0;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (values[i] > values[j])
			{
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
			j++;
		}
		i++;
	}
	pivot = values[length / 2];
	free(values);
	return pivot;
}

void divide(t_list **a, t_list **b, int pivot)
{
	int size;
	int i;

	i = 0;
	size = ft_lstsize(*a);
	while (i < size)
	{
		if (*((int *)(*a)->content) < pivot)
			pb(a, b);
		else
		{
			ra(a);
            if ((*a) && (*a)->next && *((int *)(*a)->content) > *((int *)(*a)->next->content))
                sa(a);
		}
		i++;
	}
}
