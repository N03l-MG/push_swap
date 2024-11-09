/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:48:54 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/08 17:30:22 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h> // malloc and free
# include <unistd.h> // read and write
# include <limits.h> // MIN_INT and other constants
# include <stdarg.h> // Variadic functions
# include <stdint.h> // Useful numeric types 
# include <fcntl.h> // File descriptor read flags
# include <stdbool.h> // Boolean type and true/false
//# include <stdio.h> // For testing - disabled

// ! MODIFICATION: Stack list for push_swap (all lst functions updated too) !
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

// Standard libft Functions
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_toupper(int c);

// Bonus Linked List Functions
t_stack	*ft_lstnew(void *content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst, void (*del)(void *));
void	ft_lstclear(t_stack **lst, void (*del)(void *));

// ft_printf Implementation
int		ft_printf(const char *str, ...);
// get_next_line Implementation
char	*get_next_line(int fd);

#endif
