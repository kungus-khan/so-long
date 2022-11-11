/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:44:15 by aikram            #+#    #+#             */
/*   Updated: 2022/10/23 21:01:11 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_printf.h"

int	ft_printf(const char *st, ...)
{
	va_list	args;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	va_start(args, st);
	while (st[i[1]])
	{
		while (st[i[1]] == '%')
		{
			while (st[i[1] + 1] && !ft_strchr("%scupidXx", st[i[1] + 1]))
				i[1]++;
			if (st[i[1]++])
				i[0] += formats(&st[i[1]++], args);
		}
		if (st[i[1]])
			i[0] += putchr(st[i[1]++]);
	}
	va_end(args);
	return (i[0]);
}

int	formats(const char *st, va_list args)
{
	int	i;

	i = 1;
	if (*st == 'c')
		i = character(va_arg(args, int));
	else if (*st == 's')
		i = string(va_arg(args, char *));
	else if (*st == 'p')
	{
		write(1, "0x", 2);
		i = pointer(va_arg(args, unsigned long)) + 2;
	}
	else if (*st == 'd' || *st == 'i')
		i = digit(va_arg(args, int));
	else if (*st == 'u' || *st == 'x' || *st == 'X')
		i = uns_hex_caphex(*st, va_arg(args, unsigned int));
	else if (*st == '%')
		putchr('%');
	else
		i = 0;
	return (i);
}

int	putchr(char c)
{
	write(1, &c, 1);
	return (1);
}
