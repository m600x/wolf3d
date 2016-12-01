/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 10:23:57 by alao              #+#    #+#             */
/*   Updated: 2016/12/01 18:20:43 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct			s_sprite
{
	double				dist;
	int					type;
	struct s_sprite		*next;
	double				x;
	double				y;
	int					scaled;
}						t_sprite;

typedef struct			s_pxl
{
	int					wall;
	int					color;
	char				orientation;
}						t_pxl;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	void				*t_wall;
	void				*t_sky;
	void				*t_gnd;
	void				*g_footer;
	void				*t_heroin;
	void				*t_tp;
	int					bpp;
	int					end;
	int					len;
}						t_mlx;

typedef struct			s_player
{
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				pln_x;
	double				pln_y;
	double				spd;
	double				rot;
	int					junkie;
	int					high;
	int					heroin;
	double				distance;
	int					step;
}						t_player;

typedef struct			s_var
{
	double				cam_x;
	double				rdir_x;
	double				rdir_y;
	int					cmap_x;
	int					cmap_y;
	double				dlen_x;
	double				dlen_y;
	double				slen_x;
	double				slen_y;
	int					step_x;
	int					step_y;
	double				wlen;
	double				wplen;
	int					wstart;
	int					wend;
	double				whit;
	int					wside;
	int					wcolor;
	double				fsx;
	double				fsy;
	int					ftx;
	int					fty;
	double				sp_x;
	double				sp_y;
	int					sp_fact;
	double				sp_transx;
	double				sp_transy;
	int					sp_xstart;
	int					sp_xend;
	int					sp_ystart;
	int					sp_yend;
}						t_var;

typedef struct			s_emb
{
	int					stime;
	int					offtime;
	int					textured;
	char				gui_head;
	int					aud_fsi;
	int					aud_fst;
}						t_emb;

typedef struct			s_wolf
{
	t_mlx				mlx;
	char				*choice;
	t_pxl				**map;
	int					map_x;
	int					map_y;
	int					level;
	t_var				v;
	t_sprite			*s;
	t_player			p;
	t_emb				e;
}						t_wolf;

#endif
