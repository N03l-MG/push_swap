/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:48:54 by nmonzon           #+#    #+#             */
/*   Updated: 2024/11/05 16:58:30 by nmonzon          ###   ########.fr       */
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

// Linked List Node
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Stack list for push_swap
typedef struct s_stack
{
	void			*content;
	int				index;
	int				cost;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

// Standard libft Functions
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n); //had restrict
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize); //had restrict
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize); //had restrict
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

// Bonus Linked List Functions
t_stack	*ft_lstnew(void *content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst, void (*del)(void *));
void	ft_lstclear(t_stack **lst, void (*del)(void *));
void	ft_lstiter(t_stack *lst, void (*f)(void *));
t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *));

// ft_printf Implementation
int		ft_printf(const char *str, ...);
// get_next_line Implementation
char	*get_next_line(int fd);

#endif
