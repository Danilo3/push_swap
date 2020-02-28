/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:09:23 by ayellin           #+#    #+#             */
/*   Updated: 2020/02/26 10:50:07 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <limits.h>

# ifdef __linux__
#  include <sys/types.h>
#  define LONG_LONG_MIN LLONG_MIN
#  define OPEN_MAX 1024
# endif

typedef unsigned char		t_uchar;
typedef	unsigned long long	t_ull;

# define FT_INT_MIN -2147483648l
# define FT_INT_MIN_STR "-2147483648"
# define FT_INT_MAX 2147483647
# define FT_LONG_LONG_MIN_STR "-9223372036854775808"
# define FT_CHAR_MAX 128
# define FT_NULL 0
# define FT_SIZE_T_MAX  18446744073709551615u
# define FT_NEAR_LLONG_MAX 922337203685477580ul
# define ULLONG_MAX_DIGITS 80
# define FT_LONG_LONG_MIN LONG_LONG_MIN

# define FT_true 1
# define FT_false 0

/*
 ** Part1:
*/

size_t			ft_strlen(const char *str);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strcpy(char *dst, const char *str);
char			*ft_strdup(const char *str);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *s1, const char *s2, size_t size);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *hs, const char *needle, size_t len);

/*
 ** Part 2
*/

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

/*
 **	List:
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *n);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t			ft_lstlen(t_list *lst);

/*
 ** String:
*/

char			*ft_strrev(char *str);
int				ft_isspace(char ch);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_str_startswith(const char *str, const char *start);
void			ft_itostr(int value, char *str);
size_t			ft_strnlen(const char *s, size_t max);
ssize_t			ft_strchri(const char *s, char c);
void			ft_str_shift_left(char *str, size_t from);
char			*ft_strjoinf(char *s1, char *s2, int flag);
char			*ft_strsubf(char **ps, size_t start, size_t len);
ssize_t			ft_strcspn(const char *s, const char *charset);
ssize_t			ft_str_func_not_find(const char *s, int (*f)(char ch));
ssize_t			ft_str_find(const char *s, int (*f)(char ch));

/*
 **	Memory:
*/

void			*ft_memrcpy(void *dst, const void *src, size_t len);

/*
 ** Math expansion:
*/

unsigned		ft_sqrt(unsigned x);
int				ft_ispsqrt(unsigned x);
int				ft_count_digits(int n);
int				ft_power(int base, int n);
int				ft_min(int a, int b);
int				ft_max(int a, int b);

/*
 ** Matrix expansion:
*/

char			**ft_alloc_sqmt(size_t n);
void			ft_print_sqmt(char **mt);
void			ft_free_sqmt(char **mt);
int				ft_free_mtrx(char **mtrx, size_t n);

/*
 ** Other
*/

void			ft_init_arr(char *arr, size_t size, int value);
int				ft_int_arr_cmp(int *a1, int *a2, size_t size);
void			ft_exit(void *mem, const char *msg);

/*
 ** convert functions
*/

char			*ft_lltoa(long long ll, char *str);
char			*ft_itoa_base(int value, char *buffer, int base, char a);
char			*ft_lltoa_base(long long ll, char *str, int base, char a);
char			*ft_uitoa_base(unsigned int v, char *buf, int b, char a);
char			*ft_ulltoa_base(t_ull ull, char *str, int base, char a);
long			ft_atol(const char *str);

/*
 ** Convert structs
*/

typedef struct	s_lldiv
{
	long long qout;
	long long rem;

}				t_lldiv;

typedef struct	s_ulldiv
{
	t_ull qout;
	t_ull rem;

}				t_ulldiv;

/*
 ** ft_printf
*/

int				ft_printf(const char *fmt, ...);

/*
 ** get_next_line
*/

# define BUFF_SIZE  100

int				get_next_line(const int fd, char **line);

/*
 ** Boolean type
*/

typedef enum	e_bool
{
	false,
	true
}				t_bool;

/*
 **		parse functions
*/

int				ft_parse_int_str(char **arg, int *next);

#endif
