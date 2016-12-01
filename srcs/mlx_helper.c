/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:15:23 by alao              #+#    #+#             */
/*   Updated: 2016/12/01 18:20:44 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** MLX : Put the image in the selected position with X and Y.
*/

void			wolf_mlx_image(t_wolf *w, char *img, int x, int y)
{
	int			tx;
	int			ty;
	int			off_x;
	int			off_y;

	w->mlx.img = mlx_xpm_file_to_image(w->mlx.mlx, img, &tx, &ty);
	if (w->mlx.img == NULL)
	{
		ft_putstr_fd("\e[1;31m", 2);
		ft_putstr_fd(ERR_MISS, 2);
		ft_putstr_fd(img, 2);
		ft_putendl_fd(" ]\e[0m", 2);
		wolf_exit(w);
	}
	off_x = x;
	off_y = y;
	x == MLX_LEFT ? off_x = 0 : (0);
	x == MLX_CENTER ? off_x = (WIN_X - tx) / 2 : (0);
	x == MLX_RIGHT ? off_x = (WIN_X - tx) : (0);
	y == MLX_LEFT ? off_y = 0 : (0);
	y == MLX_CENTER ? off_y = (WIN_Y - ty) / 2 : (0);
	y == MLX_RIGHT ? off_y = (WIN_Y - ty) : (0);
	mlx_put_image_to_window(w->mlx.mlx, w->mlx.win, w->mlx.img, off_x, off_y);
	mlx_destroy_image(w->mlx.mlx, w->mlx.img);
}

/*
** MLX : Put the pixel color in the rendering image.
*/

void			wolf_mlx_pixel(t_wolf *w, int x, int y, int color)
{
	char		*px;
	int			*tmp;

	if (x >= WIN_X || y >= WIN_Y || x < 0 || y < 0)
		return ;
	px = mlx_get_data_addr(w->mlx.img, &w->mlx.bpp, &w->mlx.len, &w->mlx.end);
	tmp = (int *)&px[(y * w->mlx.len) + (x * (w->mlx.bpp / 8))];
	*tmp = color;
}

/*
** MLX : Retrieve the pixel color from the image
*/

int				wolf_mlx_get_color(t_wolf *w, void *img, int x, int y)
{
	char		*px;
	int			color;

	color = 0;
	px = mlx_get_data_addr(img, &w->mlx.bpp, &w->mlx.len, &w->mlx.end);
	px += y * w->mlx.len + x * (w->mlx.bpp / 8);
	color += (px[2] & 0xFF) << 16;
	color += (px[1] & 0xFF) << 8;
	color += *px;
	if (w->p.junkie && color != 0)
		color -= (64 & 0xFF) << 24;
	return (color);
}
