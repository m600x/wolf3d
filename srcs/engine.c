/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 11:19:49 by alao              #+#    #+#             */
/*   Updated: 2016/12/01 18:11:45 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** ENGINE : Calculate the starting, ending and lengh of the wall. Also
**          retrieve the hitting point on the wall. If the textured is turned
**          off, it put the default color in the image or pass to the function
**          that get the color from the texture image.
*/

static void		wolf_calculator(t_wolf *w, int sided, int x)
{
	double		tmp;

	w->v.wside = sided;
	if (w->v.wside)
		tmp = (w->v.cmap_y - w->p.pos_y + (1 - w->v.step_y) / 2) / w->v.rdir_y;
	else
		tmp = (w->v.cmap_x - w->p.pos_x + (1 - w->v.step_x) / 2) / w->v.rdir_x;
	w->v.wplen = tmp;
	w->v.wlen = (int)(WIN_Y / w->v.wplen);
	w->v.wstart = -(w->v.wlen) / 2 + WIN_Y / 2;
	(w->v.wstart < 0) ? w->v.wstart = 0 : (0);
	w->v.wend = w->v.wlen / 2 + WIN_Y / 2;
	(w->v.wend >= WIN_Y) ? w->v.wend = WIN_Y - 1 : (0);
	(w->v.wside) ? (w->v.whit = w->p.pos_x + (tmp) * w->v.rdir_x) : (0);
	(!w->v.wside) ? (w->v.whit = w->p.pos_y + (tmp) * w->v.rdir_y) : (0);
	if (w->v.whit < (int)w->v.whit)
		w->v.whit = w->v.whit - (int)w->v.whit - 1;
	else
		w->v.whit = w->v.whit - (int)w->v.whit;
	if (w->e.textured)
		wolf_rendering(w, x, 0, 0);
	else
		while (w->v.wstart < w->v.wend)
			wolf_mlx_pixel(w, x, w->v.wstart++, w->v.wcolor);
}

/*
** ENGINE : Launch the ray till it touch a wall and return 0 or 1 depending if
**          a side wall is touched or a frontal one. Figuring out the
**          orientation of the wall for the color choice. Push T to see
**          untextured version with theses colors.
*/

static int		wolf_detect_wall(t_wolf *w, int rt)
{
	int			sens;

	while (42)
	{
		sens = (w->v.slen_x < w->v.slen_y) ? 1 : 0;
		w->v.slen_x += (sens) ? w->v.dlen_x : 0;
		w->v.cmap_x += (sens) ? w->v.step_x : 0;
		w->v.slen_y += (sens) ? 0 : w->v.dlen_y;
		w->v.cmap_y += (sens) ? 0 : w->v.step_y;
		rt = (sens) ? 0 : 1;
		(w->map[w->v.cmap_y][w->v.cmap_x].wall > 1) ? wolf_spriter(w) : (0);
		if (w->map[w->v.cmap_y][w->v.cmap_x].wall == 1)
		{
			(!rt && w->v.rdir_x > 0) ? w->v.wcolor = WOLF_WCE : (0);
			(!rt && w->v.rdir_x < 0) ? w->v.wcolor = WOLF_WCW : (0);
			(rt && w->v.rdir_y > 0) ? w->v.wcolor = WOLF_WCS : (0);
			(rt && w->v.rdir_y < 0) ? w->v.wcolor = WOLF_WCN : (0);
			return (rt);
		}
	}
	return (-1);
}

/*
** ENGINE : Calculate all the value for the raycasting.
*/

static void		wolf_commute_value(t_wolf *w, int x)
{
	w->v.cam_x = 2 * x / (double)WIN_X - 1;
	w->v.rdir_x = w->p.dir_x + w->p.pln_x * w->v.cam_x;
	w->v.rdir_y = w->p.dir_y + w->p.pln_y * w->v.cam_x;
	w->v.cmap_x = (int)w->p.pos_x;
	w->v.cmap_y = (int)w->p.pos_y;
	w->v.dlen_x = sqrt(1 + pow(w->v.rdir_y, 2) / pow(w->v.rdir_x, 2));
	w->v.dlen_y = sqrt(1 + pow(w->v.rdir_x, 2) / pow(w->v.rdir_y, 2));
	w->v.step_x = 1;
	w->v.step_y = 1;
	if (w->v.rdir_x < 0 && (w->v.step_x = -1))
		w->v.slen_x = (w->p.pos_x - w->v.cmap_x) * w->v.dlen_x;
	else
		w->v.slen_x = (w->v.cmap_x + 1.0 - w->p.pos_x) * w->v.dlen_x;
	if (w->v.rdir_y < 0 && (w->v.step_y = -1))
		w->v.slen_y = (w->p.pos_y - w->v.cmap_y) * w->v.dlen_y;
	else
		w->v.slen_y = (w->v.cmap_y + 1.0 - w->p.pos_y) * w->v.dlen_y;
}

/*
** ENGINE : If the textured option is off, a standard color is filled for the
**          sky and the ground. Half/Half.
*/

static void		wolf_skyground(t_wolf *w, int x, int y)
{
	w->v.cmap_x = -1;
	w->v.cmap_y = -1;
	while (y < WIN_Y / 2)
	{
		x = 0;
		while (x < WIN_X)
			wolf_mlx_pixel(w, x++, y, WOLF_SKY);
		y++;
	}
	y = WIN_Y / 2;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
			wolf_mlx_pixel(w, x++, y, WOLF_GND);
		y++;
	}
}

/*
** ENGINE : Start. Create an empty image and call for color if not textured.
**          Cycling for all vertical line of the screen by commuting the value
**          and launching a ray in the direction to see if it meet a wall or a
**          sprite. Then it calculate the height of the wall touched along with
**          the starting and ending point. Once the drawing is done for every
**          wall of the image, the function for sprite printing is called.
**          Once done, the image is finally put on screen and destroyed.
**          On screen GUI is called afterward.
*/

void			wolf_engine(t_wolf *w)
{
	int			x;
	int			rt;

	x = 0;
	w->mlx.img = mlx_new_image(w->mlx.mlx, WIN_X, WIN_Y);
	(!w->e.textured) ? wolf_skyground(w, 0, 0) : (0);
	while (x < WIN_X)
	{
		wolf_commute_value(w, x);
		rt = wolf_detect_wall(w, 0);
		if (rt != -1)
			wolf_calculator(w, rt, x);
		x++;
	}
	wolf_render_sprite(w);
	mlx_put_image_to_window(w->mlx.mlx, w->mlx.win, w->mlx.img, 0, 0);
	mlx_destroy_image(w->mlx.mlx, w->mlx.img);
	wolf_onscreen(w);
}
