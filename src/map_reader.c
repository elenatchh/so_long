/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:07:59 by elefonta          #+#    #+#             */
/*   Updated: 2024/10/08 10:34:11 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(t_data *data, char *argv)
{
	int	i;

	i = 0;
	data->fd = open(argv, O_RDONLY);
	if (!data->fd)
		ft_error(data, "opening file failed");
	while (i < 19 && (i == 0 || data->map.map[i - 1]))
	{
		data->map.map[i] = get_next_line(data->fd);
		data->map.copymap[i] = ft_strdup(data->map.map[i]);
		if (data->map.map[i] && !data->map.copymap[i])
			(get_next_line(-1), close(data->fd), exit_game(data));
		if (!data->map.map[i])
			break ;
		if (data->map.map[i] && data->map.copymap[i])
			data->map.line++;
		i++;
	}
	data->map.column = ft_strlen(data->map.map[0]) - 1;
	get_next_line(-1);
	close(data->fd);
	if (i > 17)
		exit_game(data);
}

void	put_img(t_data *data)
{
	data->pos.y = -1;
	while (++data->pos.y < data->map.line)
	{
		data->pos.x = -1;
		while (++data->pos.x < data->map.column)
		{
			if (data->map.map[data->pos.y][data->pos.x] == '1')
				put_img_to_img(data->square.image, data->square.wall,
					data->pos.x * 60, data->pos.y * 60);
			if (data->map.map[data->pos.y][data->pos.x] == 'C')
				put_img_to_img(data->square.image, data->square.collectible,
					data->pos.x * 60, data->pos.y * 60);
			if (data->map.map[data->pos.y][data->pos.x] == 'P')
				put_img_to_img(data->square.image, data->square.player,
					data->pos.x * 60, data->pos.y * 60);
			if (data->map.map[data->pos.y][data->pos.x] == '0')
				put_img_to_img(data->square.image, data->square.floor,
					data->pos.x * 60, data->pos.y * 60);
			if (data->map.map[data->pos.y][data->pos.x] == 'E')
				put_img_to_img(data->square.image, data->square.exit,
					data->pos.x * 60, data->pos.y * 60);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->square.image.img, 0, 0);
}
