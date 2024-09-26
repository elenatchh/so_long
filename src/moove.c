/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:03:48 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/26 11:28:20 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static bool	flood_fill(t_data *data, int x, int y)
{
	static	int 		collectible = 0;
	static	bool		exit = false;

	if (data->map.copymap[y][x] == '1')
		return (false);
	if (data->map.copymap[y][x] == 'E')
		exit = true;
	if (data->map.copymap[y][x] == 'C')
		collectible++;
	data->map.copymap[y][x] = '1';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
	return(collectible == data->countitem.collectible && exit);
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
				if (!flood_fill(data, x, y))
					ft_error(data, "player cannot play");
					
		}
	}
	verif_count(data);
}
