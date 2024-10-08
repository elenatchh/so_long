/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:37:31 by elefonta          #+#    #+#             */
/*   Updated: 2024/10/08 12:55:38 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_mlx(t_data *data)
{
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

int	key_handler(int key, t_data *data)
{
	if (key == UP || key == W)
		move_player(data, data->pos.x, data->pos.y - 1, 0);
	else if (key == DOWN || key == S)
		move_player(data, data->pos.x, data->pos.y + 1, 1);
	else if (key == RIGHT || key == D)
		move_player(data, data->pos.x + 1, data->pos.y, 2);
	else if (key == LEFT || key == A)
		move_player(data, data->pos.x - 1, data->pos.y, 3);
	else if (key == ESC)
		exit_game(data);
	write(1, "moves: ", 7);
	ft_putnbr_fd(data->countitem.moves, 1);
	write(1, "\n", 1);
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
	check_extension(&data, argv[1]);
	create_map(&data, argv[1]);
	verif_items(&data);
	ft_search_player(&data);
	ft_init_mlx(&data);
	load_xpm(&data);
	put_img(&data);
	find_player(&data);
	mlx_hook(data.win, KEYPRESS, KeyPressMask, key_handler, &data);
	mlx_hook(data.win, DST_N, StructureNotifyMask, exit_game, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
