/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:01:55 by nmonzon           #+#    #+#             */
/*   Updated: 2024/10/28 11:31:31 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// First we count the ammout of times we encounter a delimiter without
// counting consecutive ones, to know how many elements our final array has.
// Then we malloc this new array of strings. Now we loop again and start copying
// strings into the array slots, malloc each one. If one fails we free the rest.
// Once fully populated, we fill the last one with NULL and return the array.

// counts ammount of splits, therefore elements and allocates memory to array
static char	**count_alloc(const char *s, char c)
{
	size_t	i;
	int		counter;
	char	**split_strings;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			counter++;
		i++;
	}
	split_strings = (char **)malloc(sizeof(char *) * (counter + 1));
	if (!split_strings)
		return (NULL);
	return (split_strings);
}

// allocates based on length of substring and copies into array
static char	*alloc_cpy(char const *start, size_t l)
{
	char	*current_string;

	current_string = (char *)malloc(l + 1);
	if (!current_string)
		return (NULL);
	ft_strlcpy(current_string, start, l + 1);
	current_string[l] = '\0';
	return (current_string);
}

// frees memory and returns null in case of failure
static char	**free_memory(char **split_strings, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(split_strings[i]);
		i++;
	}
	free(split_strings);
	return (NULL);
}

// cycle through string and calls the copy function after every substring
static char	**populate_array(char const *s, char c, char **split_strings)
{
	size_t		total_index;
	const char	*start;

	total_index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = s;
			while (*s && *s != c)
				s++;
			split_strings[total_index] = alloc_cpy(start, s - start);
			if (!split_strings[total_index])
				return (free_memory(split_strings, total_index));
			total_index++;
		}
	}
	split_strings[total_index] = NULL;
	return (split_strings);
}

// the real deal, calls every funtion and returns final array
char	**ft_split(char const *s, char c)
{
	char		**split_strings;

	if (!s)
		return (NULL);
	split_strings = count_alloc(s, c);
	if (!split_strings)
		return (NULL);
	return (populate_array(s, c, split_strings));
}
