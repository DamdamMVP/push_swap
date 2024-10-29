/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:36:07 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/26 19:45:03 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "ft_printf.h"

// Struct definition for linked list
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// ====================     FT_PRINTF    ====================

int				ft_printf(const char *format, ...);
int				ft_handle_s(va_list args);
int				ft_handle_c(va_list args);
int				ft_handle_p(va_list args);
int				ft_handle_d(va_list args);
int				ft_handle_i(va_list args);
int				ft_handle_u(va_list args);
int				ft_handle_x(va_list args);
int				ft_handle_xcaps(va_list args);
int				ft_handle_percent(va_list args);

// ==================== Character checks ====================

// Check if character is alphabetic
int				ft_isalpha(int c);
// Check if character is a digit
int				ft_isdigit(int c);
// Check if character is alphanumeric
int				ft_isalnum(int c);
// Check if character is in ASCII set
int				ft_isascii(int c);
// Check if character is printable
int				ft_isprint(int c);

// ==================== String operations ====================

// Get length of the string
int				ft_strlen(const char *s);
// Copy and truncate string
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
// Append string with truncation
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
// Find character in string (from start)
char			*ft_strchr(const char *s, int c);
// Find character in string (from end)
char			*ft_strrchr(const char *s, int c);
// Find substring in string
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
// Compare strings with length
int				ft_strncmp(const char *s1, const char *s2, int n);
// Extract substring
char			*ft_substr(char const *s, unsigned int start, size_t len);
// Join two strings
char			*ft_strjoin(char const *s1, char const *s2);
// Trim characters from start and end of string
char			*ft_strtrim(char const *s1, char const *set);
// Split string by character
char			**ft_split(char const *s, char c);
// Apply function to each character in string
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// Iterate and apply function to string characters
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
// Duplicate string
char			*ft_strdup(const char *s);

// ==================== Memory operations ====================

// Set memory with specific character
void			*ft_memset(void *s, int c, int n);
// Set memory with zeros
void			ft_bzero(void *s, int n);
// Copy memory
void			*ft_memcpy(void *dest, const void *src, int n);
// Move memory (handles overlap)
void			*ft_memmove(void *dest, const void *src, int n);
// Find character in memory
void			*ft_memchr(const void *s, int c, int n);
// Compare memory regions
int				ft_memcmp(const void *s1, const void *s2, int n);
// Allocate zero-initialized memory
void			*ft_calloc(int n, int size);

// ==================== Number and conversion functions ====================

// Convert string to integer
int				ft_atoi(const char *str);
// Convert string to long
long			ft_atol(const char *str);
// Convert character to uppercase
int				ft_toupper(int c);
// Convert character to lowercase
int				ft_tolower(int c);
// Convert integer to string
char			*ft_itoa(int n);
// Convert unsigned int to string
char			*ft_utoa(unsigned int n);
// Convert unsigned long to base16
char			*ft_tobase16(unsigned long nbr);

// ==================== Output functions ====================

// Output character to file descriptor
void			ft_putchar_fd(char c, int fd);
// Output string to file descriptor
void			ft_putstr_fd(char *s, int fd);
// Output string with newline to file descriptor
void			ft_putendl_fd(char *s, int fd);
// Output number to file descriptor
void			ft_putnbr_fd(int n, int fd);
// Get next line
char			*ft_get_next_line(int fd);

// ==================== Linked list functions ====================

// Create new linked list element
t_list			*ft_lstnew(void *content);
// Add element to front of linked list
void			ft_lstadd_front(t_list **lst, t_list *new);
// Get size of linked list
int				ft_lstsize(t_list *lst);
// Get last element of linked list
t_list			*ft_lstlast(t_list *lst);
// Add element to end of linked list
void			ft_lstadd_back(t_list **lst, t_list *new);
// Delete one linked list element
void			ft_lstdelone(t_list *lst, void (*del)(void *));
// Clear entire linked list
void			ft_lstclear(t_list **lst, void (*del)(void *));
// Iterate and apply function to linked list elements
void			ft_lstiter(t_list *lst, void (*f)(void *));
// Create new linked list by applying function to each element
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
