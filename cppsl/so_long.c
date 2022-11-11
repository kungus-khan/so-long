/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 03:08:37 by aikram            #+#    #+#             */
/*   Updated: 2022/10/23 21:20:07 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_mkr(t_game *src)
{
	src->mlx_win = mlx_new_window(src->mlx, src->sz_x * 64,
			src->sz_y * 64, "so_long");
}

void	validity_acidity(t_game *src)
{
	no_greedy(src);
	fnd_plr_ext(src);
	mp_val(src, src->p[0], src->p[1]);
	if (src->col != src->cle || !src->col || !src->ext)
	{
		if (src->col != src->cle || !src->col)
			ft_printf("Error\ncollectibles blocked!");
		if (!src->ext)
			ft_printf("Error\nexit blocked!");
		fr_gg(src);
	}
}

int	mse_evt(t_game *src)
{
	cls_win(src);
	return (0);
}

void	chkr(t_game *src)
{
	src->mvs = 0;
	src->ext = 0;
	src->col = 0;
	src->cle = 0;
	src->plr = 0;
	src->m_ext = 0;
	mp_chkr(src);
	col_cnt(src);
	chr_chk(src);
	hash_browns(src);
	validity_acidity(src);
}

int	main(int ac, char **av)
{
	t_game	src;

	if (ac == 2)
	{
		src.mvs = 0;
		berfect(av[1]);
		src.map = mprd(&src, av[1]);
		src.mp_chk = ft_split(src.map, '\n');
		chkr(&src);
		src.mlx = mlx_init();
		if (!src.mlx)
			return (0);
		win_mkr(&src);
		map_mkr(&src);
		mlx_key_hook(src.mlx_win, key_hk, &src);
		mlx_hook(src.mlx_win, 17, 0, mse_evt, &src);
		mlx_loop(src.mlx);
		free(src.mp_chk);
		free(src.map);
	}
	else
		ft_printf("Error\nincorrect amount of args");
}
