/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:06:05 by alao              #+#    #+#             */
/*   Updated: 2016/12/03 11:24:30 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		wolf_sprite_behind_wall(t_wolf *w)
{
	while (42)
	{
		if (w->v.slen_x < w->v.slen_y)
		{
			w->v.slen_x += w->v.dlen_x;
			w->v.cmap_x += w->v.step_x;
		}
		else
		{
			w->v.slen_y += w->v.dlen_y;
			w->v.cmap_y += w->v.step_y;
		}
		if (w->map[w->v.cmap_y][w->v.cmap_x].wall > 1)
			return (1);
		if (w->map[w->v.cmap_y][w->v.cmap_x].wall == 1)
			return (0);
	}
	return (-1);
}

int				wolf_sprite_checker(t_wolf *w, int x)
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
	return (wolf_sprite_behind_wall(w));
}

/*
** SPRITE : Put the new sprite in the list.
*/

static void		wolf_sprite_saver(t_wolf *w, t_sprite *nd)
{
	int			tag;
	t_sprite	*ptr;
	t_sprite	*tmp;

	tag = 1;
	ptr = w->s;
	while (ptr && tag != -1 && tag != 0)
	{
		if (ptr->x == nd->x && ptr->y == nd->y)
			tag = -1;
		if (ptr->x != nd->x && ptr->y != nd->y)
			(ptr->dist > nd->dist) ? tag = 0 : (0);
		tmp = ptr;
		ptr = ptr->next;
	}
	(tag == -1) ? ft_memdel((void *)&nd) : (0);
	(tag == 0) ? nd->next = tmp->next : (0);
	(tag == 0 || tag == 1) ? tmp->next = nd : (0);
}

/*
** SPRITE : Create the new node for the list of sprite then call the above
**          function that will put it in the list.
*/

void			wolf_spriter(t_wolf *w)
{
	t_sprite	*nd;

	nd = (t_sprite *)malloc(sizeof(t_sprite));
	nd->dist = sqrt(w->p.pos_x - w->v.cmap_x) + sqrt(w->p.pos_y - w->v.cmap_y);
	nd->type = w->map[w->v.cmap_y][w->v.cmap_x].wall;
	nd->scaled = (nd->type == 3) ? 1 : 0;
	nd->next = NULL;
	nd->x = w->v.cmap_x + 0.5;
	nd->y = w->v.cmap_y + 0.5;
	if (w->s == NULL)
		w->s = nd;
	else
		wolf_sprite_saver(w, nd);
}
