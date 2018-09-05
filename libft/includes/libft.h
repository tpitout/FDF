/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:57:07 by tpitout           #+#    #+#             */
/*   Updated: 2018/08/13 13:03:37 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# define BUFF_SIZE 100

# include <sys/stat.h>
# include <sys/types.h>

# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define WHITE		"\033[37m"
# define RESET		"\033[0m"
# define CLEAN		"\e[1;1H\e[5J"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memalloc(size_t size);
int					ft_strequ(const char *s1, const char *s2);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
size_t				ft_strlen(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				*ft_memccpy(void *str1, const void *str2, int c, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strjoin(const char *s1, const char *s2);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str, const char *sub);
char				*ft_strnstr(const char *str, const char *sub, size_t n);
void				*ft_memalloc(size_t n);
void				ft_memdel(void **ap);
char				*ft_strtrim(const char *str);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
size_t				ft_strlcat(char *dst, const char *src, size_t n);
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strrev(char *str);
char				*str_capitalizer(char *str);
char				*ft_lower(char *str);
char				*ft_upper(char *str);
char				*ft_strpbrk(const char *s, const char *charset);
size_t				ft_strspn(const char *s1, const char *s2);
char				*ft_strsep(char *str, int c);
char				*ft_strnset(char *str, int c, int n);
int					ft_isspace(int c);
int					ft_abs(int n);
int					get_line(const int fd, char *buf, char *strs[fd]);
int					get_next_line(const int fd, char **line);

#endif
