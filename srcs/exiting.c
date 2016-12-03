/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 08:45:14 by alao              #+#    #+#             */
/*   Updated: 2016/12/03 15:19:01 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** EXIT : Destroy all the image pointer and window from MLX.
*/

static void			wolf_free_image(t_wolf *w)
{
	w->mlx.t_sky ? mlx_destroy_image(w->mlx.mlx, w->mlx.t_sky) : (0);
	w->mlx.t_wall ? mlx_destroy_image(w->mlx.mlx, w->mlx.t_wall) : (0);
	w->mlx.t_gnd ? mlx_destroy_image(w->mlx.mlx, w->mlx.t_gnd) : (0);
	w->mlx.g_footer ? mlx_destroy_image(w->mlx.mlx, w->mlx.g_footer) : (0);
	w->mlx.t_heroin ? mlx_destroy_image(w->mlx.mlx, w->mlx.t_heroin) : (0);
	w->mlx.t_tp ? mlx_destroy_image(w->mlx.mlx, w->mlx.t_tp) : (0);
	mlx_destroy_window(w->mlx.mlx, w->mlx.win);
}

/*
** EXIT : Free the sprite list if exist.
*/

static void			wolf_free_sprite(t_wolf *w)
{
	t_sprite		*tmp;
	t_sprite		*ptr;

	ptr = w->s;
	while (ptr && ptr->next)
	{
		tmp = ptr;
		ptr = ptr->next;
		ft_memdel((void *)&tmp);
	}
	ptr ? ft_memdel((void *)&ptr) : (0);
}

/*
** EXIT : Free the map array if exist.
*/

static void			wolf_free_map(t_wolf *w)
{
	int				x;

	x = 0;
	while (x < w->map_y)
		free(w->map[x++]);
	free(w->map);
	w->map = NULL;
	w->map_x = 0;
	w->map_y = 0;
}

/*
** EXIT.
*/

int					wolf_exit(t_wolf *w)
{
	(w->map) ? wolf_free_map(w) : (0);
	(w->s) ? wolf_free_sprite(w) : (0);
	wolf_free_image(w);
	ft_putendl("");
	system(AUD_OFF);
	exit(EXIT_SUCCESS);
}
