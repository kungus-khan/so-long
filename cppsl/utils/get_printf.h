/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:34:05 by aikram            #+#    #+#             */
/*   Updated: 2022/10/23 21:11:34 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_PRINTF_H
# define GET_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char*s1, char const *s2);
char	*ft_read(char *str, char *buf, int fd);
void	*ft_calloc(size_t count, size_t size);

int		ft_strnl(char *s);
int		ft_strlen(const char *s);

int		ft_printf(const char *st, ...);
int		formats(const char *st, va_list args);
int		putchr(char c);
int		character(int c);
int		string(char *str);
int		pointer(unsigned long long ptr);
int		uns_hex_caphex(char c, unsigned int num);
int		hex_caphex(char cap_or_not, unsigned int num);
int		uns(unsigned int num);
int		digit(int num);

char	*ft_strchr(const char *s, int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr(int n);

#endif
