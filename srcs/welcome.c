/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:46:42 by alao              #+#    #+#             */
/*   Updated: 2016/12/01 20:12:34 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** WELCOME : Hooker function for the welcome screen.
*/

static int		wolf_welcome_hook(int key, t_wolf *w)
{
	if (key == K_ESC)
		wolf_exit(w);
	if ((key == K_UP || key == MV_FW) && w->level != 1 && (w->level = 1))
		wolf_mlx_image(w, IMG_WELCOME_N, MLX_LEFT, MLX_RIGHT);
	if ((key == K_DOWN || key == MV_BW) && w->level != 2 && (w->level = 2))
		wolf_mlx_image(w, IMG_WELCOME_Q, MLX_LEFT, MLX_RIGHT);
	if (key == K_ENTER && w->level == 1)
		return (wolf_loop(w));
	if (key == K_ENTER && (w->level == 2))
		wolf_exit(w);
	return (0);
}

/*
** WELCOME : Display the welcome menu to start the game. The background is
**           drawn, then the default choice (which is new game) and a mini
**           hooker function above is called to handle the choice.
*/

void			wolf_welcome(t_wolf *w)
{
	wolf_mlx_image(w, IMG_WELCOME, MLX_LEFT, MLX_LEFT);
	wolf_mlx_image(w, IMG_WELCOME_N, MLX_LEFT, MLX_RIGHT);
	mlx_hook(w->mlx.win, 17, (1L << 17), &wolf_exit, w);
	mlx_hook(w->mlx.win, 2, (1L << 0), &wolf_welcome_hook, w);
	mlx_loop(w->mlx.mlx);
}
