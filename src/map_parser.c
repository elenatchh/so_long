/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:18:09 by elefonta          #+#    #+#             */
/*   Updated: 2024/10/02 11:42:28 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	flood_fill(t_data *data, int x, int y)
{
	static int	collectible = 0;
	static bool	exit = false;

	if (data->map.copymap[y][x] == 'E')
		exit = true;
	if (data->map.copymap[y][x] == '1' || data->map.copymap[y][x] == 'E')
		return (false);
	if (data->map.copymap[y][x] == 'C')
		collectible++;
	data->map.copymap[y][x] = '1';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
	return (collectible == data->countitem.collectible && exit);
}

void	player(t_data *data)
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
				if (!flood_fill(data, x, y))
					ft_error(data, "player cannot play");
			}
		}
	}
	verif_count(data);
}

void	verif_count(t_data *data)
{
	if (data->countitem.player != 1)
		ft_error(data, "wrong number of player");
	if (data->countitem.collectible < 1)
		ft_error(data, "no colectible");
	if (data->countitem.exit != 1)
		ft_error(data, "wrong number of exit");
}

void	verif_items(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map.line)
	{
		x = -1;
		if (data->map.map[y][0] != '1' || data->map.map[y][data->map.column
			- 1] != '1')
			ft_error(data, "wrong wall");
		while (++x < data->map.column)
		{
			if (data->map.map[0][x] != '1' || data->map.map[data->map.line
				- 1][x] != '1')
				ft_error(data, "wrong wall");
			if (data->map.map[y][x] == 'P')
				data->countitem.player++;
			if (data->map.map[y][x] == 'C')
				data->countitem.collectible++;
			if (data->map.map[y][x] == 'E')
				data->countitem.exit++;
		}
	}
	verif_count(data);
}

void	map_verif(t_data *data, char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (ft_strncmp(&argv[len - 4], ".ber", 4))
		ft_error(data, "bad extension");
}
