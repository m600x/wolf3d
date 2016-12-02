/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:18:46 by alao              #+#    #+#             */
/*   Updated: 2016/12/02 13:35:17 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** TEST PRINT
*/

static void			test(t_wolf *w, int x, int y)
{
	while (y < w->map_y)
	{
		(y < 9) ? ft_putstr(" ") : (0);
		ft_putnbr(y + 1);
		ft_putstr(" ");
		x = 0;
		while (x < w->map_x)
		{
			if (x == (int)w->p.pos_x && y == (int)w->p.pos_y)
				ft_putstr("P ");
			else
			{
				(w->map[y][x].wall == 0) ? ft_putstr("  ") : (0);
				(w->map[y][x].wall == 1) ? ft_putstr("# ") : (0);
				(w->map[y][x].wall == 2) ? ft_putstr("P ") : (0);
				(w->map[y][x].wall == 3) ? ft_putstr("H ") : (0);
				(w->map[y][x].wall == 4) ? ft_putstr("E ") : (0);
			}
			x++;
		}
		ft_putendl("");
		y++;
	}
}

/*
** INIT: Textures loader.
*/

static void			wolf_textures(t_wolf *w, int x, int y)
{
	w->mlx.t_sky = NULL;
	w->mlx.t_wall = NULL;
	w->mlx.t_gnd = NULL;
	w->mlx.t_heroin = mlx_xpm_file_to_image(w->mlx.mlx, SPRITE_HEROIN, &x, &y);
	w->mlx.t_tp = mlx_xpm_file_to_image(w->mlx.mlx, SPRITE_TP, &x, &y);
	w->mlx.g_footer = mlx_xpm_file_to_image(w->mlx.mlx, IMG_GUI_FOOT, &x, &y);
	w->mlx.t_sky = mlx_xpm_file_to_image(w->mlx.mlx, LV1_SKY, &x, &y);
	w->mlx.t_wall = mlx_xpm_file_to_image(w->mlx.mlx, LV1_WALL, &x, &y);
	w->mlx.t_gnd = mlx_xpm_file_to_image(w->mlx.mlx, LV1_GND, &x, &y);
}

/*
** INIT : Default value
*/

static void			init_variable(t_wolf *w)
{
	w->p.pos_x = (double)w->map_x / 2;
	w->p.pos_y = (double)w->map_y / 2;
	w->p.dir_x = 0;
	w->p.dir_y = -1;
	w->p.pln_x = 0.66;
	w->p.pln_y = 0.0;
	w->p.spd = WOLF_SPD;
	w->p.rot = WOLF_ROT;
	w->e.stime = time(0);
	w->e.offtime = w->e.stime;
	w->e.gui_head = 'm';
	w->e.textured = 1;
	w->p.step = 0;
	w->p.junkie = 0;
	w->s = NULL;
}

/*
** INIT : Search for the player as in the map it's marked number 2. If none,
**        is found, the default center map is used.
*/

static int			init_player(t_wolf *w, int x, int y, int tag)
{
	while (y < w->map_y && tag)
	{
		x = 0;
		while (x < w->map_x && tag)
		{
			if (w->map[y][x].wall == 2)
			{
				w->map[y][x].wall = 0;
				w->p.pos_x = x + 0.5;
				w->p.pos_y = y + 0.5;
				tag = 0;
			}
			x++;
		}
		y++;
	}
	return (tag ? 1 : 0);
}

/*
** Dora init.
*/

void				wolf_init(t_wolf *w, int first)
{
	if (first)
	{
		w->level = 1;
		w->p.heroin = 0;
		wolf_textures(w, 0, 0);
	}
	init_variable(w);
	init_player(w, 0, 0, 1);
	test(w, 0, 0);
}
