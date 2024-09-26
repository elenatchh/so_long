/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:18:09 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/25 15:02:02 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verif_count(t_data *data)
{
	if (data->countitem.player != 1)
		ft_error(data,"wrong number of player");
	if (data->countitem.collectible < 1)
		ft_error(data,"no colectible");
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
		if (data->map.map[y][0] != '1' || data->map.map[y][data->map.column - 1] != '1')
			ft_error(data, "wrong wall");
		while (++x < data->map.column)
		{
			if (data->map.map[0][x] != '1' || data->map.map[data->map.line - 1][x] != '1' )
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
	if (ft_strncmp(&argv[len-4], ".ber", 4))
		ft_error(data, "bad extension");
}

