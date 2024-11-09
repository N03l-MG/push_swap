#include "checker.h"

static bool	is_valid_number(const char *str);
static void	free_strings(char **strings, bool was_malloced);

void	parse_input(char **strings, t_stack **a, bool was_malloced)
{
	int		value;
	int		i;
	t_stack	*new;

	i = 0;
	while (strings[i] != NULL)
	{
		if (!is_valid_number(strings[i]))
		{
			free_strings(strings, was_malloced);
			handle_error(a, NULL);
		}
		value = ft_atoi(strings[i]);
		new = ft_lstnew(malloc(sizeof(int)));
		if (!new)
		{
			free_strings(strings, was_malloced);
			handle_error(a, NULL);
		}
		*((int *)new->content) = value;
		ft_lstadd_back(a, new);
		i++;
	}
	free_strings(strings, was_malloced);
}

static bool	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (i > 0);
}

static void	free_strings(char **strings, bool was_malloced)
{
	int	i;

	i = 0;
	if (was_malloced)
	{
		while (strings[i])
		{
			free(strings[i]);
			i++;
		}
		free(strings);
	}
	else
		return ;
}
