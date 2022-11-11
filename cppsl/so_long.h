/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:07:44 by aikram            #+#    #+#             */
/*   Updated: 2022/10/23 22:17:57 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include "utils/get_printf.h"

# define WALL "./img/wall_e.xpm"
# define PLL "./img/dum_guy.xpm"
# define FLR "./img/floor2.xpm"
# define COL "./img/b.xpm"
# define CL1 "./img/b_c.xpm"
# define EXT "./img/door_c2.xpm"
# define EXX "./img/dumm.xpm"
# define EX1 "./img/usmen.xpm"
# define EX2 "./img/k1.xpm"
# define EX3 "./img/sam.xpm"
# define EX4 "./img/usme.xpm"
# define EX5 "./img/ussr.xpm"

typedef struct s_game
{
	int		fd;
	int		lne_len;
	int		ttl_lne;
	int		mvs;
	int		sz_x;
	int		sz_y;
	int		ext;
	int		col;
	int		plr;
	int		cle;
	int		m_ext;
	int		c;
	int		i[3];
	int		p[2];
	int		e[2];
	int		valid[256][256];
	char	*tmp;

	char	**mp_chk;
	char	*map;
	char	*mlx;
	int		*mlx_win;
	void	*img;
}	t_game;

void	validity_acidity(t_game *src);
void	win_mkr(t_game *src);
void	chkr(t_game *src);
int		mse_evt(t_game *src);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_spit(char const *s, char c, char **strr, int *i);
char	**ft_split(char const *s, char c);
int		linez(char *str);

void	fr_mlt(char **s);
void	fr_gg(t_game *src);
void	nul(char *map);
void	cls_win(t_game *src);

void	mp_rec(t_game *src);
void	wall_e(t_game *src);
void	mp_chkr(t_game *src);

int		berfect(char *ber);
char	*mprd(t_game *src, char *mp);

void	col_cnt(t_game *src);
void	chr_chk(t_game *src);
void	hash_browns(t_game *src);
void	no_greedy(t_game *src);
void	fnd_plr_ext(t_game *src);

int		valid_chk(t_game *src, int x, int y);
void	mp_val(t_game *src, int x, int y);

void	map_mkr(t_game *src);
void	img_sel(t_game *src, char c, int x, int y);
void	drw_img(t_game *src, char *img, int x, int y);
void	col_gen(t_game *src, char c);
void	colagen(t_game *src, char c);
void	chronos(t_game *src, int x, int y);

int		key_hk(int keycode, t_game *src);
int		move(t_game *src, int x, int y);
void	pos_col(t_game *src, int x, int y, int flg);
void	chk_col_ext(t_game *src);
void	regice(t_game *src, int x, int y, int g);

#endif