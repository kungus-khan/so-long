/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:42:09 by aikram            #+#    #+#             */
/*   Updated: 2022/10/23 21:09:26 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mp_chkr(t_game *src)
{
	src->i[0] = ft_strlen(src->map) - (src->sz_y - 1);
	src->sz_x = src->i[0] / src->sz_y;
	mp_rec(src);
	wall_e(src);
}

void	mp_rec(t_game *src)
{
	double	triple;

	triple = ((double)src->i[0] / (double)src->sz_y) - (double)src->sz_x;
	if (triple)
	{
		ft_printf("Error\nthis isn't the art club! 🙄\n");
		fr_gg(src);
	}
}

void	wall_e(t_game *src)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = -1;
	k = 0;
	while (src->mp_chk[0][++j])
		if (src->mp_chk[0][j] != '1' || src->mp_chk[src->sz_y - 1][j] != '1')
			i = 1;
	while (++k < src->sz_y - 1)
		if (src->mp_chk[k][0] != '1' || src->mp_chk[k][j - 1] != '1')
			i = 1;
	if (i)
	{
		ft_printf("Error\n!!!WARNING! MAP IS NOT");
		ft_printf("SURROUNDED BY WALLS, ZOMBIES INCOMING!!!");
		fr_gg(src);
	}
}

void	chronos(t_game *src, int x, int y)
{
	if (!src->c)
		drw_img(src, EXX, src->p[0] + x, src->p[1] + y);
	else if (src->c == 1)
		drw_img(src, EX1, src->p[0] + x, src->p[1] + y);
	else if (src->c == 2)
		drw_img(src, EX2, src->p[0] + x, src->p[1] + y);
	else if (src->c == 3)
		drw_img(src, EX3, src->p[0] + x, src->p[1] + y);
	else if (src->c == 4)
		drw_img(src, EX4, src->p[0] + x, src->p[1] + y);
	else if (src->c == 5)
		drw_img(src, EX5, src->p[0] + x, src->p[1] + y);
}
