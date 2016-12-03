/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:46:42 by alao              #+#    #+#             */
/*   Updated: 2016/12/03 11:05:44 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** WELCOME : Synopsis on console output
*/

static void		wolf_synopsis(void)
{
	ft_putcolor_fd("\n\tSynopsis:\n\n", "\e[1;4;34m", 1);
	ft_putstr("    Dora have lot of trouble catching Chipeur and she's stuck ");
	ft_putstr("in a Labyrinth finding him. Luckily for her, she's a ");
	ft_putstr("junkie and Chipeur dropped a few heroin shot on his escape ");
	ft_putstr("that will help her run much faster to catch him.\n    But be ");
	ft_putstr("aware Dora, drugs are bad... M'kay?...\n        You might ");
	ft_putendl("have trouble seeing clearly...\n");
}

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
	wolf_synopsis();
	wolf_mlx_image(w, IMG_WELCOME, MLX_LEFT, MLX_LEFT);
	wolf_mlx_image(w, IMG_WELCOME_N, MLX_LEFT, MLX_RIGHT);
	mlx_hook(w->mlx.win, 17, (1L << 17), &wolf_exit, w);
	mlx_hook(w->mlx.win, 2, (1L << 0), &wolf_welcome_hook, w);
	mlx_loop(w->mlx.mlx);
}
