/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:40:31 by alao              #+#    #+#             */
/*   Updated: 2016/12/03 12:19:11 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** PLAYER : Update the value concerning the player.
*/

int				wolf_player_status(t_wolf *w, int key, int rt)
{
	if (key == TEXTURED && (rt = 1))
		w->e.textured = w->e.textured ? 0 : 1;
	if (w->p.high == 0 && (rt = 1))
		w->p.junkie = 0;
	if (w->p.junkie && (rt = 1))
		w->p.high--;
	if (key == K_SPACE && w->p.heroin > 0 && w->p.junkie == 0 && (rt = 1))
	{
		system(AUD_HERUSE);
		w->p.heroin--;
		w->p.junkie = 1;
		w->p.high = WOLF_HIGH_T * 4;
		w->p.spd = WOLF_SPD * WOLF_HIGH_F;
	}
	return (rt);
}

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
		w->p.heroin == 0 ? system(AUD_HERFPICK) : system(AUD_HERPICK);
		w->p.heroin++;
	}
	if (item == 4)
	{
		wolf_leveling(w);
		system(AUD_LEVEL);
	}
}
