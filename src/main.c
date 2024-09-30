/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:37:31 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/30 15:06:11 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_data *data)
{
	int	img_size;

	img_size = 60;
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_error(data, "error mlx pointer");
	data->win = mlx_new_window(data->mlx, data->map.column * 60, data->map.line
			* 60, "so_long");
	if (!data->win)
		ft_error(data, "error window pointer");
	data->square.image.w = data->map.column * 60;
	data->square.image.h = data->map.line * 60;
	data->square.image.img = mlx_new_image(data->mlx, data->square.image.w,
			data->square.image.h);
	if (!data->square.image.img)
		ft_error(data, "can't create background image.");
	data->square.image.addr = mlx_get_data_addr(data->square.image.img,
			&(data->square.image.bpp), &(data->square.image.size_line),
			&(data->square.image.endian));
}

int	touchexit(int key, t_data *data)
{
	if (key == UP)
		move_player(data, data->pos.x, data->pos.y - 1);
	else if (key == DOWN)
		move_player(data, data->pos.x, data->pos.y + 1);
	else if (key == RIGHT)
		move_player(data, data->pos.x + 1, data->pos.y);
	else if (key == LEFT)
		move_player(data, data->pos.x - 1, data->pos.y);
	else if (key == ESC)
		exit_game(data);
	return (0);
}

static void	spawn_image(t_data *data, t_image *img, char *path, int img_size)
{
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img_size, &img_size);
	if (!img->img)
		ft_error(data, "load image error");
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line,
			&img->endian);
	img->w = img_size;
	img->h = img_size;
}

static void	load_xpm(t_data *data)
{
	int	img_size;

	img_size = 60;
	spawn_image(data, &data->square.player, PLAYER, img_size);
	spawn_image(data, &data->square.wall, WALL, img_size);
	spawn_image(data, &data->square.collectible, COLLECTIBLE, img_size);
	spawn_image(data, &data->square.exit, EXIT, img_size);
	spawn_image(data, &data->square.floor, FLOOR, img_size);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (argc != 2)
		ft_error(&data, "mauvais nombre d'args");
	map_verif(&data, argv[1]);
	map_reader(&data, argv[1]);
	verif_items(&data);
	player(&data);
	ft_init(&data);
	load_xpm(&data);
	put_img(&data);
	find_player(&data);
	printf("pos x key joueur : %d\n", data.pos.x);
	printf("pos y key joueur : %d\n", data.pos.y);
	mlx_hook(data.win, KEYPRESS, KeyPressMask, touchexit, &data);
	mlx_hook(data.win, DST_N, StructureNotifyMask, exit_game, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
