/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:41:21 by alao              #+#    #+#             */
/*   Updated: 2016/12/02 13:35:36 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** HOOKER : Update the value concerning Dora.
*/

static int			wolf_hero_stat(t_wolf *w, int key, int rt)
{
	if (key == TEXTURED && (rt = 1))
		w->e.textured = w->e.textured ? 0 : 1;
	if (w->p.high == 0 && (rt = 1))
		w->p.junkie = 0;
	if (w->p.junkie && (rt = 1))
		w->p.high--;
	if (key == K_SPACE && w->p.heroin > 0 && w->p.junkie == 0 && (rt = 1))
	{
		w->p.heroin--;
		w->p.junkie = 1;
		w->p.high = WOLF_HIGH_T * 4;
		w->p.spd = WOLF_SPD * WOLF_HIGH_F;
	}
	return (rt);
}

/*
** HOOKER : Calculate movements for the strafe and forward/backward. It's also
**          for both direction (front/back or left/right) depending on the int
**          sens. If a forward/backward key is pressed, the function received
**          the direction in X and Y as reference to move. If it's strafe
**          Left or Right it's the plane in X and Y that's received to keep a
**          perpendicular reference for the movement.
*/

static int			wolf_move_calc(t_wolf *w, double v1, double v2, int sens)
{
	int				tmp;
	int				rt;

	rt = 0;
	if (sens)
	{
		tmp = (int)(w->p.pos_x + v1 * w->p.spd);
		if (w->map[(int)w->p.pos_y][tmp].wall != 1 && (rt = 1))
			w->p.pos_x += v1 * w->p.spd;
		tmp = (int)(w->p.pos_y + v2 * w->p.spd);
		if (w->map[tmp][(int)w->p.pos_x].wall != 1 && (rt = 1))
			w->p.pos_y += v2 * w->p.spd;
	}
	else
	{
		tmp = (int)(w->p.pos_x - v1 * w->p.spd);
		if (w->map[(int)w->p.pos_y][tmp].wall != 1 && (rt = 1))
			w->p.pos_x -= v1 * w->p.spd;
		tmp = (int)(w->p.pos_y - v2 * w->p.spd);
		if (w->map[tmp][(int)w->p.pos_x].wall != 1 && (rt = 1))
			w->p.pos_y -= v2 * w->p.spd;
	}
	return (rt);
}

/*
** HOOKER : Distribute the right variable for the above function (explained).
**          Also change some value like the head of Dora or the step counter
**          for the sounding. If the step is on a sprite, that's where the
**          function corresponding (wolf_items_pick()) is called too.
*/

static int			wolf_move(t_wolf *w, int key)
{
	int				rt;

	rt = 0;
	(key == MV_FW) ? rt = wolf_move_calc(w, w->p.dir_x, w->p.dir_y, 1) : (0);
	(key == MV_BW) ? rt = wolf_move_calc(w, w->p.dir_x, w->p.dir_y, 0) : (0);
	(key == MV_SL) ? rt = wolf_move_calc(w, w->p.pln_x, w->p.pln_y, 0) : (0);
	(key == MV_SR) ? rt = wolf_move_calc(w, w->p.pln_x, w->p.pln_y, 1) : (0);
	(rt) ? w->p.step++ : (0);
	w->e.gui_head = 'm';
	(w->e.aud_fsi > 4 && rt) ? wolf_sound(w) : w->e.aud_fsi++;
	if (rt && w->map[(int)w->p.pos_y][(int)w->p.pos_x].wall != 0)
		wolf_items_pick(w);
	return (rt);
}

/*
** HOOKER : Calculate the rotation of Dora.
*/

static int			wolf_rotation(t_wolf *w, int key)
{
	double			tmp;
	double			amount;

	tmp = w->p.dir_x;
	amount = w->p.rot * ((key == MV_RL) ? -1 : 1);
	w->p.dir_x = w->p.dir_x * cos(amount) - w->p.dir_y * sin(amount);
	w->p.dir_y = tmp * sin(amount) + w->p.dir_y * cos(amount);
	tmp = w->p.pln_x;
	w->p.pln_x = w->p.pln_x * cos(amount) - w->p.pln_y * sin(amount);
	w->p.pln_y = tmp * sin(amount) + w->p.pln_y * cos(amount);
	w->e.gui_head = (key == MV_RL) ? 'l' : 'r';
	return (1);
}

/*
** DORA : Key hook.
*/

int					wolf_key(int key, t_wolf *w)
{
	int				render;

	render = 0;
	(key == QUIT) ? wolf_exit(w) : (0);
	(key == MV_FW || key == MV_BW) ? render = wolf_move(w, key) : (0);
	(key == MV_SL || key == MV_SR) ? render = wolf_move(w, key) : (0);
	(key == MV_RL || key == MV_RR) ? render = wolf_rotation(w, key) : (0);
	render = wolf_hero_stat(w, key, render);
	if (render)
		wolf_engine(w);
	return (0);
}
