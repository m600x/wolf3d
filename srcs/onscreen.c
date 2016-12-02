/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onscreen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:46:11 by alao              #+#    #+#             */
/*   Updated: 2016/12/02 14:12:39 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** GUI : Player position.
*/

static void			wolf_os_player(t_wolf *w)
{
	char			**tmp;
	char			*rt;

	tmp = ft_sstrnew(10);
	tmp[0] = ft_strdup("Player X [");
	tmp[1] = ft_itoa((int)w->p.pos_x);
	tmp[2] = ft_strdup("] Y [");
	tmp[3] = ft_itoa((int)w->p.pos_y);
	tmp[4] = ft_strdup("] Step [");
	tmp[5] = ft_itoa(w->p.step);
	tmp[6] = ft_strdup("] Distance meters [");
	tmp[7] = ft_itoa(w->p.step / 4);
	tmp[8] = ft_strdup("]");
	rt = ft_sstrtostr(tmp, "");
	mlx_string_put(w->mlx.mlx, w->mlx.win, 0, 0, 0, rt);
	rt ? ft_memdel((void *)&rt) : (0);
	tmp ? ft_sstrdel(tmp) : (0);
}

/*
** GUI : Print out the value using the off_x and off_y as center position.
*/

void				wolf_value(t_wolf *w, int off_x, int off_y, int value)
{
	char			*tmp;
	void			*img;
	int				i;

	i = 0;
	off_x = off_x - (40 * ((ft_length_int(value) - 1) / 2));
	ft_length_int(value) == 2 ? off_x -= 20 : (0);
	tmp = ft_itoa(value);
	while (tmp[i])
	{
		(tmp[i] - 48 == 0) ? img = IMG_GUI_N0 : (0);
		(tmp[i] - 48 == 1) ? img = IMG_GUI_N1 : (0);
		(tmp[i] - 48 == 2) ? img = IMG_GUI_N2 : (0);
		(tmp[i] - 48 == 3) ? img = IMG_GUI_N3 : (0);
		(tmp[i] - 48 == 4) ? img = IMG_GUI_N4 : (0);
		(tmp[i] - 48 == 5) ? img = IMG_GUI_N5 : (0);
		(tmp[i] - 48 == 6) ? img = IMG_GUI_N6 : (0);
		(tmp[i] - 48 == 7) ? img = IMG_GUI_N7 : (0);
		(tmp[i] - 48 == 8) ? img = IMG_GUI_N8 : (0);
		(tmp[i] - 48 == 9) ? img = IMG_GUI_N9 : (0);
		wolf_mlx_image(w, img, off_x, off_y);
		off_x += 40;
		i++;
	}
	tmp ? ft_memdel((void *)&tmp) : (0);
}

/*
** GUI : Select the right image depending of the number of heroin shot.
*/

void				wolf_heroin(t_wolf *w)
{
	if (w->p.heroin == 5)
		wolf_mlx_image(w, IMG_HEROIN_5, MLX_RIGHT, MLX_RIGHT);
	if (w->p.heroin == 4)
		wolf_mlx_image(w, IMG_HEROIN_4, MLX_RIGHT, MLX_RIGHT);
	if (w->p.heroin == 3)
		wolf_mlx_image(w, IMG_HEROIN_3, MLX_RIGHT, MLX_RIGHT);
	if (w->p.heroin == 2)
		wolf_mlx_image(w, IMG_HEROIN_2, MLX_RIGHT, MLX_RIGHT);
	if (w->p.heroin == 1)
		wolf_mlx_image(w, IMG_HEROIN_1, MLX_RIGHT, MLX_RIGHT);
	if (w->p.heroin == 0)
		wolf_mlx_image(w, IMG_HEROIN_0, MLX_RIGHT, MLX_RIGHT);
}

/*
** GUI : Head of the player reflecting if a rotation is made.
*/

void				wolf_head(t_wolf *w)
{
	if (w->p.junkie)
	{
		if (w->e.gui_head == 'l')
			wolf_mlx_image(w, IMG_HEAD_LH, MLX_CENTER, MLX_RIGHT);
		if (w->e.gui_head == 'm')
			wolf_mlx_image(w, IMG_HEAD_MH, MLX_CENTER, MLX_RIGHT);
		if (w->e.gui_head == 'r')
			wolf_mlx_image(w, IMG_HEAD_RH, MLX_CENTER, MLX_RIGHT);
	}
	else
	{
		if (w->e.gui_head == 'l')
			wolf_mlx_image(w, IMG_HEAD_L, MLX_CENTER, MLX_RIGHT);
		if (w->e.gui_head == 'm')
			wolf_mlx_image(w, IMG_HEAD_M, MLX_CENTER, MLX_RIGHT);
		if (w->e.gui_head == 'r')
			wolf_mlx_image(w, IMG_HEAD_R, MLX_CENTER, MLX_RIGHT);
	}
}

/*
** GUI : Start.
*/

void				wolf_onscreen(t_wolf *w)
{
	wolf_os_player(w);
	wolf_mlx_image(w, IMG_GUI_FOOT, MLX_CENTER, MLX_RIGHT);
	wolf_head(w);
	wolf_heroin(w);
	if (w->p.step / 4 < 9999)
		wolf_value(w, 350, 655, (w->p.step / 4));
	wolf_value(w, 75, 655, (w->level));
	wolf_value(w, 880, 655, (w->e.stime - w->e.offtime));
}
