/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:03:48 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/30 15:20:02 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_data *data, int x, int y)
{
	if (data->map.map[y][x] != '1')
	{
		data->pos.x = x;
		data->pos.y = y;
		if ()
		// put_img_to_img(data->square.image, data->square.floor,
		// 			data->pos.x * 60, data->pos.y * 60);
		put_img_to_img(data->square.image, data->square.player,
					data->pos.x * 60, data->pos.y * 60);
		mlx_put_image_to_window(data->mlx, data->win, data->square.image.img, 0, 0);
		printf("x : %d\n", data->pos.x);
		printf("y : %d\n", data->pos.y);
	}
}

void find_player(t_data *data)
{
	int x;
	int y;
	
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
