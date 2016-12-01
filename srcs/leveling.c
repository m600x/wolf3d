/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leveling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:37:22 by alao              #+#    #+#             */
/*   Updated: 2016/12/01 18:33:45 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
	(w->level == 2) ? sky = LV1_SKY : (0);
	(w->level == 2) ? wall = LV1_WALL : (0);
	(w->level == 2) ? gnd = LV1_GND : (0);
	(w->level == 3) ? sky = LV1_SKY : (0);
	(w->level == 3) ? wall = LV1_WALL : (0);
	(w->level == 3) ? gnd = LV1_GND : (0);
	(w->level == 4) ? sky = LV1_SKY : (0);
	(w->level == 4) ? wall = LV1_WALL : (0);
	(w->level == 4) ? gnd = LV1_GND : (0);
	(w->level == 5) ? sky = LV1_SKY : (0);
	(w->level == 5) ? wall = LV1_WALL : (0);
	(w->level == 5) ? gnd = LV1_GND : (0);
	w->mlx.t_sky = mlx_xpm_file_to_image(w->mlx.mlx, sky, &x, &y);
	w->mlx.t_wall = mlx_xpm_file_to_image(w->mlx.mlx, wall, &x, &y);
	w->mlx.t_gnd = mlx_xpm_file_to_image(w->mlx.mlx, gnd, &x, &y);
}

/*
** LEVEL : Free the previous map.
*/

static void		wolf_free_map(t_wolf *w)
{
/*	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < w->map_y)
	{
		x = 0;
		while(x < w->map_x)
		{
			free(&w->map[y][x]);
			x++;
		}
		free(&w->map[y]);
		y++;
	}*/
	w->map = NULL;
	w->map_x = 0;
	w->map_y = 0;
}

/*
** LEVEL : If the player walk on a number 4 on the map that correspond for a
**         teleporter, the next level is loaded and the corresponding texture
**         too. Default value are restored.
*/

void			wolf_leveling(t_wolf *w)
{
	w->level++;
	w->level == 2 ? w->choice = XPM_MAP_2 : (0);
	w->level == 3 ? w->choice = XPM_MAP_3 : (0);
	w->level == 4 ? w->choice = XPM_MAP_4 : (0);
	w->level == 5 ? w->choice = XPM_MAP_5 : (0);
	w->level == 6 ? wolf_exit(w) : (0);
	wolf_free_map(w);
	wolf_parser(w);
	wolf_init(w, 0);
	wolf_reload_world(w, 0, 0);

}
