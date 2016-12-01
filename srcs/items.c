/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:40:31 by alao              #+#    #+#             */
/*   Updated: 2016/12/01 18:31:10 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** SPRITE : If Dora walk on a sprite, the function is called and handle the
**          behavior. Like for instance if it's a 3 number, that mean Dora
**          walked on an heroin shot and will pick up the item if it's not
**          already full (5 max) and trigger a sound. If it's a number 4 that
**          mean it's the exit of the world. The function wolf_leveling() is
**          called to reload the map, sprite. Then finally a sound is played.
**          Other behavior can be easily added for sprite, monster or whatever
**          the game might need.
*/

void			wolf_items_pick(t_wolf *w)
{
	int			item;

	item = w->map[(int)w->p.pos_y][(int)w->p.pos_x].wall;
	if (item == 3 && w->p.heroin < 5)
	{
		w->map[(int)w->p.pos_y][(int)w->p.pos_x].wall = 0;
		w->p.heroin++;
		system(AUD_HERPICK);
	}
	if (item == 4)
	{
		wolf_leveling(w);
		system(AUD_LEVEL);
	}
}
