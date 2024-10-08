/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:03:48 by elefonta          #+#    #+#             */
/*   Updated: 2024/10/07 12:32:51 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_collectible_exit(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == 'C')
	{
		data->map.map[y][x] = '0';
		data->countitem.collectible--;
	}
	if (data->map.map[y][x] == 'E' && data->countitem.collectible == 0)
		exit_game(data);
}

void	move_player(t_data *data, int x, int y, int code_mvt)
{
	check_collectible_exit(data, x, y);
	if (data->map.map[y][x] != '1' && data->map.map[y][x] != 'E')
	{
		data->countitem.moves++;
		data->pos.x = x;
		data->pos.y = y;
		if (code_mvt == 0)
			put_img_to_img(data->square.image, data->square.floor, data->pos.x
				* 60, (data->pos.y + 1) * 60);
		else if (code_mvt == 1)
			put_img_to_img(data->square.image, data->square.floor, data->pos.x
				* 60, (data->pos.y - 1) * 60);
		else if (code_mvt == 2)
			put_img_to_img(data->square.image, data->square.floor, (data->pos.x
					- 1) * 60, data->pos.y * 60);
		else if (code_mvt == 3)
			put_img_to_img(data->square.image, data->square.floor, (data->pos.x
					+ 1) * 60, data->pos.y * 60);
		put_img_to_img(data->square.image, data->square.player, data->pos.x
			* 60, data->pos.y * 60);
		mlx_put_image_to_window(data->mlx, data->win, data->square.image.img, 0,
			0);
	}
}

void	find_player(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map.line)
	{
		x = -1;
		while (++x < data->map.column)
		{
			if (data->map.map[y][x] == 'P')
			{
				data->pos.x = x;
				data->pos.y = y;
			}
		}
	}
}
