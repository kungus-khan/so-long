/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 05:44:32 by aikram            #+#    #+#             */
/*   Updated: 2022/10/23 21:02:18 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fr_mlt(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	fr_gg(t_game *src)
{
	fr_mlt(src->mp_chk);
	free(src->map);
	exit(1);
}

void	nul(char *map)
{
	if (!map)
	{
		ft_printf("Error\ninvalid folder!");
		exit(1);
	}
}

void	cls_win(t_game *src)
{
	mlx_clear_window(src->mlx, src->mlx_win);
	mlx_destroy_window(src->mlx, src->mlx_win);
	exit(0);
}
