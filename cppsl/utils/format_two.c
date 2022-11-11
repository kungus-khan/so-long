/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:28:08 by aikram            #+#    #+#             */
/*   Updated: 2022/10/19 04:23:51 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_printf.h"

int	uns_hex_caphex(char c, unsigned int num)
{
	int	i;

	i = 0;
	if (c == 'X' || c == 'x')
		i = hex_caphex(c, num);
	else
		i = uns(num);
	return (i);
}

int	hex_caphex(char cap_or_not, unsigned int num)
{	
	char	*a;
	int		i;

	i = 1;
	if (cap_or_not == 'X')
		a = "0123456789ABCDEF";
	else
		a = "0123456789abcdef";
	if (num > 15)
		i += hex_caphex(cap_or_not, num / 16);
	num %= 16;
	putchr(a[num]);
	return (i);
}

int	uns(unsigned int unum)
{
	int	i;

	i = 1;
	if (unum > 9)
		i += uns(unum / 10);
	unum %= 10;
	putchr(unum + 48);
	return (i);
}

int	digit(int num)
{
	int	n;

	n = 0;
	ft_putnbr(num);
	if (num == -2147483648)
	{
		num = 214748364;
		n += 2;
	}
	if (num < 0)
	{
		num *= -1;
		n++;
	}
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		n++;
	}
	return (n);
}
