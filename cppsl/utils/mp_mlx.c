/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 03:57:30 by aikram            #+#    #+#             */
/*   Updated: 2022/10/23 21:08:47 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	drw_img(t_game *src, char *img, int x, int y)
{
	int	sz;

	sz = 64;
	x = x * sz;
	y = y * sz;
	src->img = mlx_xpm_file_to_image(src->mlx, img, &sz, &sz);
	mlx_put_image_to_window(src->mlx, src->mlx_win, src->img, x, y);
	mlx_destroy_image(src->mlx, src->img);
}

void	img_sel(t_game *src, char c, int x, int y)
{
	colagen(src, c);
	if (c == '1')
		drw_img(src, WALL, x, y);
	else if (c == 'P')
		drw_img(src, PLL, x, y);
	else if (c == '0')
		drw_img(src, FLR, x, y);
	else if (c == 'C' && !src->c)
		drw_img(src, COL, x, y);
	else if (c == 'C' && src->c)
		drw_img(src, CL1, x, y);
	else if (c == 'E')
		drw_img(src, EXT, x, y);
}

void	map_mkr(t_game *src)
{
	int	x;
	int	y;

	y = -1;
	while (src->mp_chk[++y])
	{
		x = -1;
		src->c = 0;
		while (src->mp_chk[y][++x])
			img_sel(src, src->mp_chk[y][x], x, y);
	}
}

void	col_gen(t_game *src, char c)
{
	if (c == 'C')
	{
		if (!src->c)
			src->c = 1;
		else if (src->c == 1)
			src->c = 2;
		else if (src->c == 2)
			src->c = 3;
		else if (src->c == 3)
			src->c = 4;
		else if (src->c == 4)
			src->c = 5;
		else
			src->c = 0;
	}
}

void	colagen(t_game *src, char c)
{
	if (c == 'C')
	{
		if (!src->c)
			src->c = 1;
		else if (src->c == 1)
			src->c = 0;
	}
}
