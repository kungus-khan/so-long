/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:01:25 by aikram            #+#    #+#             */
/*   Updated: 2022/10/23 21:06:35 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	col_cnt(t_game *src)
{
	int	i;

	i = -1;
	while (src->map[++i])
		if (src->map[i] == 'C' )
			src->cle++;
}

void	chr_chk(t_game *src)
{
	int	i[2];

	i[0] = -1;
	i[1] = 0;
	while (src->map[++i[0]])
		if (src->map[i[0]] != '1' && src->map[i[0]] != '0'
			&& src->map[i[0]] != 'E' && src->map[i[0]] != 'P'
			&& src->map[i[0]] != 'C' && src->map[i[0]] != '\n')
					i[1] = 1;
	if (i[1])
	{
		ft_printf("Error\nLIKE THIS PROJECT WASN'T HARD ENOUGH!");
		fr_gg(src);
	}
}

void	hash_browns(t_game *src)
{
	int	i[2];

	i[0] = -1;
	while (++i[0] < 256)
	{
		i[1] = -1;
		while (++i[1] < 256)
			src->valid[i[0]][i[1]] = 0;
	}
}

void	no_greedy(t_game *src)
{
	int	i[3];

	i[0] = -1;
	i[1] = 0;
	while (src->map[++i[0]])
		if (src->map[i[0]] == 'E' || src->map[i[0]] == 'P')
			i[1]++;
	if (i[1] != 2)
	{
		ft_printf("Error\nincorrect amount of Pss or Ess");
		fr_gg(src);
	}
}

void	fnd_plr_ext(t_game *src)
{
	int	i[2];

	i[0] = -1;
	i[1] = -1;
	while (src->mp_chk[++i[0]])
	{
		i[1] = -1;
		while (src->mp_chk[i[0]][++i[1]])
		{
			if (src->mp_chk[i[0]][i[1]] == 'P')
			{
				src->p[0] = i[1];
				src->p[1] = i[0];
				src->plr++;
			}
			else if (src->mp_chk[i[0]][i[1]] == 'E')
			{
				src->e[0] = i[1];
				src->e[1] = i[0];
			}
		}
	}
}
