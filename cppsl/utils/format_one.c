/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:13:50 by aikram            #+#    #+#             */
/*   Updated: 2022/10/23 21:06:22 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_printf.h"

int	character(int c)
{
	ft_printf("%c", c);
	return (1);
}

int	string(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	pointer(unsigned long long ptr)
{
	char	*a;
	int		i;

	a = "0123456789abcdef";
	i = 1;
	if (ptr > 15)
	{
		i += pointer(ptr / 16);
		pointer(ptr % 16);
	}
	else
		putchr(a[ptr]);
	return (i);
}
