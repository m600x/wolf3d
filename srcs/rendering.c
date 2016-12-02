/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:32:26 by alao              #+#    #+#             */
/*   Updated: 2016/12/02 13:36:00 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** TEXTURES : Print the corresponding point of the textures in X and Y for both
**            the ground and sky at the exact same point but in mirrored pos.
*/

void			wolf_render_skyground(t_wolf *w, int x, int y)
{
	int			clr;
	double		tmp;
	double		cfx;
	double		cfy;

	while (y < WIN_Y)
	{
		tmp = (WIN_Y / (2.0 * y - WIN_Y)) / w->v.wplen;
		cfx = tmp * w->v.fsx + (1.0 - tmp) * w->p.pos_x;
		w->v.ftx = (int)(cfx * IMG_TEX_X) % IMG_TEX_Y;
		cfy = tmp * w->v.fsy + (1.0 - tmp) * w->p.pos_y;
		w->v.fty = (int)(cfy * IMG_TEX_Y) % IMG_TEX_X;
		clr = wolf_mlx_get_color(w, w->mlx.t_sky, w->v.ftx, w->v.fty);
		wolf_mlx_pixel(w, x, WIN_Y - y, clr);
		clr = wolf_mlx_get_color(w, w->mlx.t_gnd, w->v.ftx, w->v.fty);
		wolf_mlx_pixel(w, x, y, clr);
		y++;
	}
}

/*
** TEXTURES : Calculate the point of impact for the sky in X and Y then call
**            the above function that will print out.
*/

void			wolf_tex_skyground(t_wolf *w, int x)
{
	if (w->v.wcolor == WOLF_WCE && (w->v.fsx = w->v.cmap_x))
		w->v.fsy = w->v.cmap_y + w->v.whit;
	if (w->v.wcolor == WOLF_WCW && (w->v.fsx = w->v.cmap_x + 1.0))
		w->v.fsy = w->v.cmap_y + w->v.whit;
	if (w->v.wcolor == WOLF_WCS && (w->v.fsx = w->v.cmap_x + w->v.whit))
		w->v.fsy = w->v.cmap_y;
	if (w->v.wcolor == WOLF_WCN && (w->v.fsx = w->v.cmap_x + w->v.whit))
		w->v.fsy = w->v.cmap_y + 1.0;
	if (w->v.wend < 0)
		w->v.wend = WIN_Y - 1;
	wolf_render_skyground(w, x, w->v.wend + 1);
}

/*
** RENDERING : Calculate the hit point in the texture and will cycle through
**             the whole line for the wall portion then call of the sky and
**             ground function.
*/

void			wolf_rendering(t_wolf *w, int x, int y, int t)
{
	int			t_x;
	int			t_y;
	int			clr;

	t_x = (int)(w->v.whit * (double)IMG_TEX_X);
	if (w->v.wside && w->v.rdir_y < 0)
		t_x = IMG_TEX_X - t_x - 1;
	if (!w->v.wside && w->v.rdir_x > 0)
		t_x = IMG_TEX_X - t_x - 1;
	y = w->v.wstart;
	while (y < WIN_Y && y < w->v.wend)
	{
		t = y * 256 - WIN_Y * 128 + w->v.wlen * 128;
		t_y = ((t * IMG_TEX_Y) / w->v.wlen) / 256;
		clr = wolf_mlx_get_color(w, w->mlx.t_wall, t_x, t_y);
		wolf_mlx_pixel(w, x, y++, clr);
	}
	wolf_tex_skyground(w, x);
}
