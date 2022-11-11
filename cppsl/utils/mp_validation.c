/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:25:32 by aikram            #+#    #+#             */
/*   Updated: 2022/10/12 04:04:14 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_chk(t_game *src, int x, int y)
{
	if (src->valid[y][x] == 1)
		return (0);
	if (src->mp_chk[y][x] == '1')
		return (0);
	return (1);
}

void	mp_val(t_game *src, int x, int y)
{
	src->valid[y][x] = 1;
	if (src->mp_chk[y][x] == 'C')
		src->col++;
	if (src->mp_chk[y][x] == 'E')
		src->ext++;
	if (valid_chk(src, x, y - 1))
		mp_val(src, x, y - 1);
	if (valid_chk(src, x + 1, y))
		mp_val(src, x + 1, y);
	if (valid_chk(src, x, y + 1))
		mp_val(src, x, y + 1);
	if (valid_chk(src, x - 1, y))
		mp_val(src, x - 1, y);
}
