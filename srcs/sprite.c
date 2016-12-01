/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:06:05 by alao              #+#    #+#             */
/*   Updated: 2016/12/01 18:50:52 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** SPRITE_RENDER : Return a pointer to the right sprite image.
*/

static void		*wolf_sprite_selector(t_wolf *w, t_sprite *s)
{
	if (s->type == 3)
		return (w->mlx.t_heroin);
	if (s->type == 4)
		return (w->mlx.t_tp);
	return (NULL);
}

/*
** SPRITE RENDER : Render the sprite just like for the wall.
*/

static void		wolf_sprite_renderer(t_wolf *w, int x, int y, t_sprite *s)
{
	int			sp_texx;
	int			sp_texy;
	int			clr;
	int			tmp;
	void		*sprite;

	x = w->v.sp_xstart;
	sprite = wolf_sprite_selector(w, s);
	while (x < w->v.sp_xend)
	{
		sp_texx = (int)(256 * (x - w->v.sp_fact) * IMG_SPR_X / w->v.sp_x) / 256;
		y = w->v.sp_ystart;
		while (y < w->v.sp_yend)
		{
			tmp = (s->scaled) ?(y - (int)(256 / w->v.sp_transy)) : y;
			tmp = tmp * IMG_SPR_Y - WIN_Y * 128 + w->v.sp_y * 128;
			sp_texy = ((tmp * IMG_SPR_Y) / w->v.sp_y) / 256;
			clr = wolf_mlx_get_color(w, sprite, sp_texx, sp_texy);
			clr != 0 ? wolf_mlx_pixel(w, x, y, clr) : (0);
			y++;
		}
		x++;
	}
}

/*
** SPRITE RENDER : Calculate the size and position of the sprite from the list.
**                 The sprite is also rescaled down is the int from the struct
**                 say so. Depending on the ray launched and the value from the
**                 map. For instance if the sprite is a 3, that's an heroin
**                 which is scaled down compared to a 4 (the teleporter) that is
**                 scaled 1:1.
*/

static void		wolf_sprite_calculator(t_wolf *w, t_sprite *s)
{
	double		tmp;

	w->v.sp_x = s->x - w->p.pos_x;
	w->v.sp_y = s->y - w->p.pos_y;
	tmp = 1.0 / (w->p.pln_x * w->p.dir_y - w->p.dir_x * w->p.pln_y);
	w->v.sp_transx = tmp * (w->p.dir_y * w->v.sp_x - w->p.dir_x * w->v.sp_y);
	w->v.sp_transy = tmp * (-w->p.pln_y * w->v.sp_x + w->p.pln_x * w->v.sp_y);
	w->v.sp_fact = (int)(WIN_CX * (1 + w->v.sp_transx / w->v.sp_transy));
	w->v.sp_y = abs((int)(WIN_Y / w->v.sp_transy));
	(s->scaled) ? w->v.sp_y /= SPR_SCALE : (0);
	w->v.sp_ystart = -w->v.sp_y / 2 + WIN_CY;
	(s->scaled) ? w->v.sp_ystart += (int)(256 / w->v.sp_transy) + 1 : (0);
	(w->v.sp_ystart < 0) ? w->v.sp_ystart = 0 : (0);
	w->v.sp_yend = w->v.sp_y / 2 + WIN_CY;
	(s->scaled) ? w->v.sp_yend += (int)(256 / w->v.sp_transy) : (0);
	(w->v.sp_yend >= WIN_Y) ? w->v.sp_yend = WIN_Y - 1 : (0);
	w->v.sp_x = abs((int)(WIN_Y / w->v.sp_transy));
	(s->scaled) ? w->v.sp_x /= SPR_SCALE : (0);
	w->v.sp_xstart = -w->v.sp_x / 2 + w->v.sp_fact;
	(w->v.sp_xstart < 0) ? w->v.sp_xstart = 0 : (0);
	w->v.sp_xend = w->v.sp_x / 2 + w->v.sp_fact;
	(w->v.sp_xend >= WIN_X) ? w->v.sp_xend = WIN_X - 1 : (0);
	w->v.sp_fact = -w->v.sp_x / 2 + w->v.sp_fact;
}

/*
** SPRITE RENDER : Start.
*/

void			wolf_render_sprite(t_wolf *w)
{
	t_sprite	*ptr;
	t_sprite	*tmp;

	ptr = w->s;
	while (ptr)
	{
		wolf_sprite_calculator(w, ptr);
		wolf_sprite_renderer(w, 0, 0, ptr);
		ptr = ptr->next;
	}
	ptr = w->s;
	while (ptr && ptr->next)
	{
		tmp = ptr;
		ptr = ptr->next;
		ft_memdel((void *)&tmp);
	}
	ptr ? ft_memdel((void *)&ptr) : (0);
	w->s = NULL;
}
