/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 09:14:35 by alao              #+#    #+#             */
/*   Updated: 2016/12/02 13:55:18 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Fill the array with values from the map.
*/

static void		wolf_filler(t_wolf *w, int x, int y)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	**splitted;

	if ((fd = open(w->choice, O_RDONLY)) < 0)
		wolf_error(ERR_NO_OPEN);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strtrim(line);
		splitted = ft_strsplit(tmp, ' ');
		x = 0;
		while (x < w->map_x && splitted[x])
		{
			w->map[y][x].wall = ft_atoi(splitted[x]);
			x++;
		}
		line ? ft_memdel((void *)&line) : (0);
		tmp ? ft_memdel((void *)&tmp) : (0);
		splitted ? ft_sstrdel(splitted) : (0);
		y++;
	}
	close(fd);
}

/*
** Support function: Check if the splitted line only contain numbers of it's
**                   an error and return 1 which will stock the parsing.
*/

static int		ft_isnumber(char *str)
{
	int t;

	t = 0;
	if (str && str[t] == '-')
		t++;
	while (str && str[t])
	{
		if ((str[t] >= 48 && str[t] <= 58) || str[t] == 32 || str[t] == '-')
			t++;
		else
			return (1);
	}
	return (0);
}

/*
** Allocate the array with the map size retrieved below.
*/

static void		wolf_alloc(t_wolf *w, int i)
{
	if (!(w->map = (t_pxl **)malloc(sizeof(t_pxl *) * w->map_y)))
		wolf_error(ERR_MALLOC);
	while (i < w->map_y)
		if (!(w->map[i++] = (t_pxl *)malloc(sizeof(t_pxl) * w->map_x)))
			wolf_error(ERR_MALLOC);
	wolf_filler(w, 0, 0);
}

/*
** Open the file and determine the map size while checking if it only contain
** numbers and if the lines are equal. If not, the parsing stop and fdf exit.
*/

void			wolf_parser(t_wolf *w)
{
	char	**splitted;
	char	*line;
	char	*tmp;
	int		fd;

	if ((fd = open(w->choice, O_RDONLY)) < 0)
		wolf_error(ERR_NO_OPEN);
	if ((read(fd, NULL, 0)) < 0)
		wolf_error(ERR_NO_OPEN);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strtrim(line);
		splitted = ft_strsplit(tmp, ' ');
		ft_isnumber(tmp) ? wolf_error(ERR_NOT_NUM) : (0);
		(w->map_x == 0) ? w->map_x = ft_sstrlen(splitted) : (0);
		if (w->map_x != ft_sstrlen(splitted))
			wolf_error(ERR_NOT_EQU);
		tmp ? ft_memdel((void *)&tmp) : (0);
		line ? ft_memdel((void *)&line) : (0);
		splitted ? ft_sstrdel(splitted) : (0);
		w->map_y++;
	}
	close(fd);
	wolf_alloc(w, 0);
}
