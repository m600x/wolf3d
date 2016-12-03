/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:56:21 by alao              #+#    #+#             */
/*   Updated: 2016/12/03 12:00:19 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include "struct.h"
# include "vars.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# include <unistd.h>
# include "fcntl.h"
# include <time.h>

/*
** Unvariables
*/

# define MLX_LEFT		0
# define MLX_CENTER		1
# define MLX_RIGHT		2
# define WIN_X			1280
# define WIN_Y			720
# define WIN_CX			WIN_X / 2
# define WIN_CY			WIN_Y / 2
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
# define WOLF_DFL_SCR	10000
# define SPR_SCALE		2.5

/*
** Localization for errors.
*/

# define ERR_NO_OPEN	"File error: Failed to open the file."
# define ERR_MALLOC		"Malloc Error."
# define ERR_NOT_NUM	"Map error: a non number as been found."
# define ERR_NOT_EQU	"Map error: Lines are not equal in length."
# define ERR_ASCII		"Map error: a non ascii char as been found."
# define ERR_MISS		"Dora3D fatal error: cannot find: [ "

/*
** Key mapping.
*/

# define QUIT			K_ESC
# define MV_FW			K_W
# define MV_BW			K_S
# define MV_SL			K_A
# define MV_SR			K_D
# define MV_RL			K_Q
# define MV_RR			K_E
# define USE_ITEM		K_SPACE
# define TEXTURED		K_T
# define K_ESC			53
# define K_ENTER		36
# define K_SPACE		49
# define K_UP			126
# define K_DOWN			125
# define K_W			13
# define K_S			1
# define K_A			0
# define K_D			2
# define K_Q			12
# define K_E			14
# define K_T			17

/*
** Functions.
*/

void					wolf_error(char *reason);
int						wolf_exit(t_wolf *w);
void					wolf_parser(t_wolf *w);
void					wolf_init(t_wolf *w, int first);
void					wolf_welcome(t_wolf *w);
int						wolf_loop(t_wolf *w);
int						wolf_key(int key, t_wolf *w);
void					wolf_items_pick(t_wolf *w);
int						wolf_player_status(t_wolf *w, int key, int rt);
void					wolf_sound(t_wolf *w);
void					wolf_leveling(t_wolf *w);
void					wolf_engine(t_wolf *w);
void					wolf_spriter(t_wolf *w);
void					wolf_rendering(t_wolf *w, int x, int y, int t);
void					wolf_render_sprite(t_wolf *w);
int						wolf_sprite_checker(t_wolf *w, int x);
void					wolf_onscreen(t_wolf *w);
void					wolf_value(t_wolf *w, int off_x, int off_y, int value);
void					wolf_mlx_pixel(t_wolf *w, int x, int y, int color);
void					wolf_mlx_image(t_wolf *w, char *img, int x, int y);
int						wolf_mlx_get_color(t_wolf *w, void *pic, int x, int y);

#endif
