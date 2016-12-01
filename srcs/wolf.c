/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 09:10:09 by alao              #+#    #+#             */
/*   Updated: 2016/12/01 18:51:11 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** EXIT.
*/

int				wolf_exit(t_wolf *w)
{
	w = NULL;
	system(AUD_OFF);
	exit(EXIT_SUCCESS);
}

/*
** Error handling. Will print the error and exit the program.
*/

void			wolf_error(char *reason)
{
	ft_putendl_fd(reason, 2);
	exit(EXIT_FAILURE);
}

/*
** LOOP : Only recalculate the time in seconds passed since the game started.
**        it will reprint the time every seconds.
*/

static int		wolf_time(t_wolf *w)
{
	int			ttime;

	ttime = time(0);
	if (ttime - w->e.stime > 0)
	{
		w->e.stime = ttime;
		wolf_value(w, 880, 655, (w->e.stime - w->e.offtime));
	}
	return (0);
}

/*
** LOOP : Main looper.
*/

static int		wolf_loop(t_wolf *w)
{
	wolf_engine(w);
	system(AUD_OPN);
	mlx_hook(w->mlx.win, 17, (1L << 17), &wolf_exit, w);
	mlx_hook(w->mlx.win, 2, (1L << 0), &wolf_key, w);
	mlx_loop_hook(w->mlx.mlx, &wolf_time, w);
	mlx_loop(w->mlx.mlx);
	return (0);
}

/*
** Start of wolf3d
*/

int				main(int argc, char *argv[])
{
	t_wolf		w;

	(void)argc;
	(void)argv;
	w.map_x = 0;
	w.map_y = 0;
	w.choice = DEF_MAP;
	w.level = 1;
	w.mlx.mlx = mlx_init();
	wolf_parser(&w);
	wolf_init(&w, 1);
	w.mlx.win = mlx_new_window(w.mlx.mlx, WIN_X, WIN_Y, "Dora 3D");
	wolf_loop(&w);
	return (0);
}
