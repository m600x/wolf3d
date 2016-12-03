/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leveling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:37:22 by alao              #+#    #+#             */
/*   Updated: 2016/12/03 11:56:15 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void			wolf_scoring(t_wolf *w)
{
	int				lv_score;

	lv_score = WOLF_DFL_SCR;
	lv_score -= w->p.step * 10;
	lv_score -= (w->e.stime - w->e.offtime) * 10;
	w->score += lv_score;
	ft_putstr("\nScore of the level ");
	ft_putnbr(w->level);
	ft_putstr(" : ");
	ft_putnbr(lv_score);
	ft_putstr(" / ");
	ft_putnbr(WOLF_DFL_SCR);
	ft_putstr(" points.");
}

/*
** LEVEL : Reload textures.
*/

static void			wolf_reload_world(t_wolf *w, int x, int y)
{
	char			*sky;
	char			*wall;
	char			*gnd;

	w->mlx.t_sky != NULL ? mlx_destroy_image(w->mlx.mlx, w->mlx.t_sky) : (0);
	w->mlx.t_wall != NULL ? mlx_destroy_image(w->mlx.mlx, w->mlx.t_wall) : (0);
	w->mlx.t_gnd != NULL ? mlx_destroy_image(w->mlx.mlx, w->mlx.t_gnd) : (0);
	(w->level == 1) ? sky = LV1_SKY : (0);
	(w->level == 1) ? wall = LV1_WALL : (0);
	(w->level == 1) ? gnd = LV1_GND : (0);
	(w->level == 2) ? sky = LV2_SKY : (0);
	(w->level == 2) ? wall = LV2_WALL : (0);
	(w->level == 2) ? gnd = LV2_GND : (0);
	(w->level == 3) ? sky = LV3_SKY : (0);
	(w->level == 3) ? wall = LV3_WALL : (0);
	(w->level == 3) ? gnd = LV3_GND : (0);
	(w->level == 4) ? sky = LV4_SKY : (0);
	(w->level == 4) ? wall = LV4_WALL : (0);
	(w->level == 4) ? gnd = LV4_GND : (0);
	(w->level == 5) ? sky = LV5_SKY : (0);
	(w->level == 5) ? wall = LV5_WALL : (0);
	(w->level == 5) ? gnd = LV5_GND : (0);
	w->mlx.t_sky = mlx_xpm_file_to_image(w->mlx.mlx, sky, &x, &y);
	w->mlx.t_wall = mlx_xpm_file_to_image(w->mlx.mlx, wall, &x, &y);
	w->mlx.t_gnd = mlx_xpm_file_to_image(w->mlx.mlx, gnd, &x, &y);
}

/*
** LEVEL : Free the previous map.
*/

static void			wolf_free_map(t_wolf *w)
{
	int				x;

	x = 0;
	while (x < w->map_y)
		free(w->map[x++]);
	free(w->map);
	w->map = NULL;
	w->map_x = 0;
	w->map_y = 0;
}

/*
** LEVEL : If the player walk on a number 4 on the map that correspond for a
**         teleporter, the next level is loaded and the corresponding texture
**         too. Default value are restored.
*/

void				wolf_leveling(t_wolf *w)
{
	wolf_scoring(w);
	w->level++;
	if (w->debug)
		w->choice = MAP_DEB;
	else
	{
		w->level == 2 ? w->choice = MAP_2 : (0);
		w->level == 3 ? w->choice = MAP_3 : (0);
		w->level == 4 ? w->choice = MAP_4 : (0);
		w->level == 5 ? w->choice = MAP_5 : (0);
	}
	if (w->level == 6)
	{
		ft_putstr("\nTotal score: ");
		ft_putnbr(w->score);
		ft_putstr(" points.");
		wolf_exit(w);
	}
	wolf_free_map(w);
	wolf_parser(w);
	wolf_init(w, 0);
	wolf_reload_world(w, 0, 0);
}
