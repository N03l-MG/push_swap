#include "push_swap.h"

static void	parse_input(const char *input, t_list **a);
static void push_swap(t_list **a, t_list **b);
static bool is_sorted(t_list *a);
static void ps_quicksort(t_list **a, t_list **b);
static int find_pivot(t_list *list, int length);
static int *bubble(int *values, int length);
static void divide(t_list **a, t_list **b, int pivot);
static void print_list(t_list *list);

	 int main(int argc, char *argv[])
{
	t_list *a = NULL;
	t_list *b = NULL;
	const char *input;
	if (argc < 2)
		return (1);
	input = argv[1];
	parse_input(input, &a);
	ps_quicksort(&a, &b);
	while (a)
	{
		ft_printf("%d ", *((int *)a->content));
		a = a->next;
	}
	ft_printf("\n");
	return (0);
}

static void	parse_input(const char *input, t_list **a)
{
	int value;
	char **strings;
	int i = 0;
	int j = 0;
	t_list *new;

	strings = ft_split(input, ' ');
	while (strings[i] != NULL)
	{
		value = ft_atoi(strings[i]);
		new = ft_lstnew(malloc(sizeof(int)));
		if (!new)
		{
			for (int j = 0; j < i; j++)
                free(strings[j]);
            free(strings);
			return;
		}
		*((int *)new->content) = value;
		ft_lstadd_back(a, new);
		ft_printf("input %d\n", *((int *)new->content));
		free(strings[i]);
		i++;
	}
	free(strings);
}

static bool is_sorted(t_list *a)
{
	ft_printf("sort check\n");
	while (a && a->next)
	{
		if (*((int *)a->content) > *((int *)a->next->content))
			return false;
		a = a->next;
	}
	return true;
}

static void ps_quicksort(t_list **a, t_list **b)
{
	ft_printf("quicksort recurr\n");
	if (is_sorted(*a))
		return;
	if (!a || !*a || !(*a)->next)
		return;
	int length = ft_lstsize(*a);
	int pivot = find_pivot(*a, length);

	divide(a, b, pivot);
	//sleep(1);
	ps_quicksort(a, b);
	ps_quicksort(b, a);

	while (*b)
		pa(a, b);
}

static int find_pivot(t_list *list, int length)
{
	int *values = malloc(length * sizeof(int));
	int i = 0;
	t_list *current = list;
	int pivot = 0;

	while (current && i < length)
	{
		values[i] = *((int *)current->content);
		current = current->next;
		i++;
	}
	values = bubble(values, length);
	pivot = values[length / 2];
	free(values);
	ft_printf("pivot: %d\n", pivot);
	return pivot;
}

static int *bubble(int *values, int length)
{
	ft_printf("bubble\n");
	int i = 0;
	int j = 0;
	int temp = 0;

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
	return (values);
}

static void divide(t_list **a, t_list **b, int pivot)
{
	ft_printf("ra\n");
	int size;
	int i;
	int rotations = 0;

	i = 0;
	size = ft_lstsize(*a);
	while (i < size)
	{
		ft_printf("%d", *((int *)(*a)->content));
		if (*((int *)(*a)->content) < pivot)
		{
			pb(a, b);
			rotations = 0;
		}
		else
		{
			ra(a);
			print_list(*a);
			rotations++;
			if (rotations >= size)
				break ;
		}
		i++;
	}
}

static void print_list(t_list *list)
{
	while (list)
	{
		ft_printf("list item: %d\n", *((int *)list->content));
		list = list->next;
	}
}
