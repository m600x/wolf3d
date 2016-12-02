/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:06:05 by alao              #+#    #+#             */
/*   Updated: 2016/12/02 12:18:33 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
	while (ptr && tag != -1)
	{
		if ((int)ptr->x == (int)nd->x && (int)ptr->y == (int)nd->y)
			tag = -1;
		if ((int)ptr->x != (int)nd->x && (int)ptr->y != (int)nd->y)
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
