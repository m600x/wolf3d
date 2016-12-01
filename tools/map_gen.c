/*
Compile command:
gcc map_gen.c -Lminilibx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o mapgen

Usage:
./mapgen x.xpm
*/

#include "minilibx/mlx.h"
#include "libft/includes/libft.h"
#include <stdio.h>

#define WALL		0xFFFEFF
#define EMPTY		0
#define PLAYER		0xFF0000
#define HEROIN		-1
#define EXIT		0x00FF00

#define TOWALL		1
#define TOEMPTY		0
#define TOPLAYER	2
#define TOHEROIN	3
#define TOEXIT		4

int				get_color(void *img, int x, int y)
{
	char		*px;
	int			bpp;
	int			endian;
	int			len;
	int			color;

	color = 0;
	px = mlx_get_data_addr(img, &bpp, &len, &endian);
	px += y * len + x * (bpp / 8);
	color += (px[2] & 0xFF) << 16;
	color += (px[1] & 0xFF) << 8;
	color += *px;
	return (color);
}

int print(void *mlx, void *img, int tx, int ty)
{
	int x = 0;
	int y = 0;
	int clr = 0;

	y = 0;
	while (y < ty)
	{
		x = 0;
		while (x < tx)
		{
			clr = get_color(img, x, y);
//			printf("clr [%d]\n", clr);
			(clr == WALL) ? ft_putchar('1') : (0);
			(clr == EMPTY) ? ft_putchar('0') : (0);
			(clr == PLAYER) ? ft_putchar('2') : (0);
			(clr == HEROIN) ? ft_putchar('3') : (0);
			(clr == EXIT) ? ft_putchar('4') : (0);
			if (x < tx - 1)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	return (0);
}


int load(void *mlx, char *path)
{
	void *img;
	int tx;
	int ty;

	img = mlx_xpm_file_to_image(mlx, path, &tx, &ty);
//	printf("Image [%s] X [%d] Y [%d]\n", path, tx, ty);
	print(mlx, img, tx, ty);
	return (0);
}

int main(int argc, char **argv)
{
	void *mlx;

	if (argc != 2)
		return (-1);
	mlx = mlx_init();
	load(mlx, argv[1]);
//	printf("T\n");
	return (0);
}
