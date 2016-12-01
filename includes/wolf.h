/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:56:21 by alao              #+#    #+#             */
/*   Updated: 2016/12/01 17:48:24 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include "keys.h"
# include "struct.h"
# include "vars.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# include <unistd.h>
# include "fcntl.h"

#include <stdio.h>
#include <time.h>

# define MLX_LEFT		0
# define MLX_CENTER		1
# define MLX_RIGHT		2
# define WIN_X			1280
# define WIN_Y			720
# define WIN_CX			WIN_X / 2
# define WIN_CY			WIN_Y / 2
# define DEF_MAP		XPM_MAP_1
# define WOLF_ROT		0.1
# define WOLF_SPD		0.2
# define WOLF_WCN		0xf10714
# define WOLF_WCS		0xd3ffce
# define WOLF_WCW		0x606e0c
# define WOLF_WCE		0x8a77b7
# define WOLF_SKY		0x7abbff
# define WOLF_GND		0x333333
# define WOLF_HIGH_T	100
# define WOLF_HIGH_F	3
# define SPR_SCALE		2.5

# define ERR_NO_OPEN	"File error: Failed to open the file."
# define ERR_MALLOC		"Malloc Error."
# define ERR_NOT_NUM	"Map error: a non number as been found."
# define ERR_NOT_EQU	"Map error: Lines are not equal in length."
# define ERR_ASCII		"Map error: a non ascii char as been found."
# define ERR_MISS		"Dora3D fatal error: cannot find: [ "

void					wolf_error(char *reason);
int						wolf_exit(t_wolf *w);
void					wolf_parser(t_wolf *w);
void					wolf_init(t_wolf *w, int first);
int						wolf_key(int key, t_wolf *w);
void					wolf_items_pick(t_wolf *w);
void					wolf_sound(t_wolf *w);
void					wolf_leveling(t_wolf *w);
void					wolf_engine(t_wolf *w);
void					wolf_spriter(t_wolf *w);
void					wolf_rendering(t_wolf *w, int x, int y, int t);
void					wolf_render_sprite(t_wolf *w);
void					wolf_onscreen(t_wolf *w);
void					wolf_value(t_wolf *w, int off_x, int off_y, int value);
void					wolf_mlx_pixel(t_wolf *w, int x, int y, int color);
void					wolf_mlx_image(t_wolf *w, char *img, int x, int y);
int						wolf_mlx_get_color(t_wolf *w, void *pic, int x, int y);

#endif