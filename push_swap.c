#include "push_swap.h"

void push_swap(t_list **a, t_list **b);

int	main(char *argv[], int argc)
{
	t_list *a;
	t_list *b;

	push_swap(a, b);
}

void push_swap(t_list **a, t_list **b)
{
	bool is_sorted = false;

	while (!is_sorted)
	{
		// sorting algorithm using operations
	}
}

t_list ps_quicksort(t_list **a, t_list **b)
{
	int pivot = find_pivot(a, ft_lstsize(a));
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
	t_list *current = *a;
	int value;

	while (current)
	{
		value = *((int *)current->content);
		if (value < pivot)
			pb(a, b);
		else
			current = current->next;
	}
}
