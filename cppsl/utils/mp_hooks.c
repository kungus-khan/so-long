/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:40:17 by aikram            #+#    #+#             */
/*   Updated: 2022/10/23 21:06:44 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	pos_col(t_game *src, int x, int y, int flg)
{
	if (flg == 1)
		ft_printf("Moves: %d\n", ++src->mvs);
	if (flg == 2)
	{
		ft_printf("Moves: %d\n", ++src->mvs);
		ft_printf("Moves: %d\n", ++src->mvs);
	}
	if (src->mp_chk[y][x] == 'C')
	{
		src->mp_chk[y][x] = '0';
		src->cle--;
	}
	src->p[0] = x;
	src->p[1] = y;
}

void	chk_col_ext(t_game *src)
{
	if (src->cle <= 0 && src->mp_chk[src->p[1]][src->p[0]] == 'E')
	{
		ft_printf("winnie the you");
		cls_win(src);
	}
}

int	move(t_game *src, int x, int y)
{
	col_gen(src, src->mp_chk[src->p[1] + y][src->p[0] + x]);
	if (src->mp_chk[src->p[1] + y][src->p[0] + x] == '1')
		return (0);
	else if (src->mp_chk[src->p[1] + y][src->p[0] + x] == 'E'
		&& src->cle > 0)
		regice(src, x, y, 0);
	else if (src->mp_chk[src->p[1]][src->p[0]] == 'E'
		&& src->cle > 0)
		regice(src, x, y, 2);
	else
		regice(src, x, y, 1);
	return (0);
}

int	key_hk(int keycode, t_game *src)
{
	if (keycode == 13)
		move(src, 0, -1);
	else if (keycode == 0)
		move(src, -1, 0);
	else if (keycode == 1)
		move(src, 0, 1);
	else if (keycode == 2)
		move(src, 1, 0);
	else if (keycode == 53)
		cls_win(src);
	return (0);
}

void	regice(t_game *src, int x, int y, int g)
{
	if (!g)
	{
		drw_img(src, FLR, src->p[0], src->p[1]);
		drw_img(src, FLR, src->p[0] + x, src->p[1] + y);
		chronos(src, x, y);
		pos_col(src, src->p[0] + x, src->p[1] + y, 1);
		src->m_ext = 1;
	}
	else
	{
		if (g == 1)
			drw_img(src, FLR, src->p[0], src->p[1]);
		else
			drw_img(src, EXT, src->p[0], src->p[1]);
		drw_img(src, PLL, src->p[0] + x, src->p[1] + y);
		pos_col(src, src->p[0] + x, src->p[1] + y, 1);
		chk_col_ext(src);
	}
}
