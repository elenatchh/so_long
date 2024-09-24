/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:37:31 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/23 13:49:45 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_data *data)
{
	data->mlx.mlx_pointer = mlx_init();
	if (!data->mlx.mlx_pointer)
		ft_error(data, "error mlx pointer");
	data->mlx.windows = mlx_new_window(data->mlx.mlx_pointer, 1000, 1000,
			"so_long");
	if (!data->mlx.windows)
		ft_error(data, "error window pointer");
}
int	touchexit(int key, t_data *data)
{
	(void)data;
	if (key == ESC)
		exit_game(data);
	return (0);
}

static void	load_xpm(t_data *data)
{
	int	img_size;

	img_size = 32;
	data->square.bg = mlx_xpm_file_to_image(data->mlx.mlx_pointer, BACKGROUND,
			&img_size, &img_size);
	data->square.player = mlx_xpm_file_to_image(data->mlx.mlx_pointer, PLAYER,
			&img_size, &img_size);
	data->square.floor = mlx_xpm_file_to_image(data->mlx.mlx_pointer, FLOOR,
			&img_size, &img_size);
	data->square.collectible = mlx_xpm_file_to_image(data->mlx.mlx_pointer,
			COLLECTIBLE, &img_size, &img_size);
	data->square.wall = mlx_xpm_file_to_image(data->mlx.mlx_pointer, WALL,
			&img_size, &img_size);
	data->square.exit = mlx_xpm_file_to_image(data->mlx.mlx_pointer, EXIT,
			&img_size, &img_size);
	if (!data->square.bg || !data->square.wall || !data->square.collectible
		|| !data->square.floor || !data->square.player || !data->square.exit)
		ft_error(data, "load image error");
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (argc != 2)
		ft_error(&data, "mauvais nombre d'args");
	ft_init(&data);
	// Try to load the file
	// t_square* square = mlx_xpm_file_to_image("./textures/ground.xpm");
	load_xpm(&data);
	map_reader(&data, argv[1]);
	mlx_put_image_to_window(data.mlx.mlx_pointer, data.mlx.windows,
		data.square.bg, 500, 500);
	mlx_put_image_to_window(data.mlx.mlx_pointer, data.mlx.windows,
		data.square.player, 50, 500);
	mlx_put_image_to_window(data.mlx.mlx_pointer, data.mlx.windows,
		data.square.collectible, 100, 100);
	mlx_put_image_to_window(data.mlx.mlx_pointer, data.mlx.windows,
		data.square.wall, 600, 600);
	mlx_put_image_to_window(data.mlx.mlx_pointer, data.mlx.windows,
		data.square.exit, 600, 600);
	mlx_hook(data.mlx.windows, KEYPRESS, KeyPressMask, touchexit, &data);
	mlx_hook(data.mlx.windows, DST_N, StructureNotifyMask, exit_game, &data);
	mlx_loop(data.mlx.mlx_pointer);
	return (EXIT_SUCCESS);
}
