/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:50:24 by ksansom           #+#    #+#             */
/*   Updated: 2024/01/26 12:12:37 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);

/*void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);*/

void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);

int		ft_printf(const char *format, ...);
int		ft_search_args(va_list arg, char c);

int		ft_print_char(char c);
int		ft_print_str(const char *str);
void	ft_putnbr(int n);
void	ft_putunsigned(unsigned int nb);
int		ft_print_int(int n);

int		ft_print_pointer(const void *ptr);
int		ft_print_pval(const void *ptr);
int		ft_print_unsigned_int(unsigned int nb);
int		ft_print_hex_up(unsigned int nb);
int		ft_print_hex_low(unsigned int nb);

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strcpy(char *dest, const char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strnchr(char *str, int c, int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_tolower(int c);
int		ft_toupper(int c);

/*ft_fprintf*/
int		ft_fprintf(int fd, const char *format, ...);
int		ft_search_args_fd(int fd, va_list arg, char c);
int		ft_print_pointer_fd(int fd, const void *ptr);
int		ft_print_pval_fd(int fd, const void *ptr);
int		ft_print_unsigned_int_fd(int fd, unsigned int nb);
int		ft_print_hex_up_fd(int fd, unsigned int nb);
int		ft_print_hex_low_fd(int fd, unsigned int nb);
void	ft_putunsigned_fd(int fd, unsigned int nb);
int		ft_print_int_fd(int fd, int n);
void	ft_putnbr_fd(int fd, int n);
int		ft_print_str_fd(int fd, const char *str);
int		ft_print_char_fd(int fd, char c);
#endif
