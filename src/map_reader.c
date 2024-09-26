/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:07:59 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/26 15:19:52 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	map_reader(t_data *data, char *argv)
{
	int		nb_lines;
	char	*tmp;

	nb_lines = 0;
	data->fd = open(argv, O_RDONLY);
	if (!data->fd)
		ft_error(data, "opening file failed");
	tmp = get_next_line(data->fd);
	data->map.column = ft_strlen(tmp) - 1;
	while (tmp)
	{
		nb_lines++;
		free(tmp);
		tmp = get_next_line(data->fd);
		if (!tmp)
			break;
	}
	close(data->fd);
	data->map.line = nb_lines;
	create_map(data, argv);
}

void	create_map(t_data *data, char *argv)
{
	int	i;
	
	i = 0;
	data->fd = open(argv, O_RDONLY);
	if (!data->fd)
		ft_error(data, "opening file failed");
	data->map.map = ft_calloc((data->map.line + 1), sizeof(char *));
	if (!data->map.map)
		ft_error(data, "malloc failed");
	data->map.copymap = ft_calloc((data->map.line + 1), sizeof(char *));
	if (!data->map.copymap)
		ft_error(data, "malloc failed");
	while (i < data->map.line)
	{
		data->map.map[i] = get_next_line(data->fd);
		data->map.copymap[i] = ft_strdup(data->map.map[i]);
		i++;
	}
	data->map.map[i] = NULL;
	data->map.copymap[i] = NULL;
	close(data->fd);
}

void	put_img(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map.line)
	{
		x = -1;
		while (++x < data->map.column)
		{
			printf("coord x=%i y=%i, c=%c\n", x, y, data->map.map[y][x]);
			if (data->map.map[y][x] == '1')
				put_img_to_img(&data->square.image,
								data->square.wall, x * 60, y * 60);
			if (data->map.map[y][x] == 'C')
				put_img_to_img(&data->square.image,
								data->square.collectible, x * 60, y * 60);
			if (data->map.map[y][x] == 'P')
				put_img_to_img(&data->square.image,
								data->square.player, x * 60, y * 60);
			if (data->map.map[y][x] == '0')
				put_img_to_img(&data->square.image,
								data->square.floor, x * 60, y * 60);
			if (data->map.map[y][x] == 'E')
				put_img_to_img(&data->square.image,
								data->square.exit, x * 60, y * 60);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->square.image.img, 0, 0);
}

