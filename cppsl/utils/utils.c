/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 03:10:44 by aikram            #+#    #+#             */
/*   Updated: 2022/10/23 21:09:50 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	berfect(char *ber)
{
	unsigned int	i;

	i = ft_strlen(ber);
	if (!ft_strncmp(".ber", &ber[i - 4], 4) && i > 4)
		return (0);
	ft_printf("Error\nmap not in .ber format");
	exit (1);
}

char	*mprd(t_game *src, char *mp)
{
	src->sz_y = 0;
	src->tmp = 0;
	src->fd = open(mp, O_RDONLY);
	src->tmp = get_next_line(src->fd);
	src->map = malloc(1);
	*src->map = '\0';
	while (src->tmp)
	{
		src->map = ft_strjoin(src->map, src->tmp);
		src->tmp = get_next_line(src->fd);
		src->sz_y++;
	}
	return (src->map);
}
