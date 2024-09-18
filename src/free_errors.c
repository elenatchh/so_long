/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:13:28 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/18 14:33:22 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_error(t_data *data, char *str)
{
	write(2, "error : ", 9);
	
	while(*str)
	{
		write(2, str, 1);
		str++;
	}
	write(2, "\n", 1);
	free_all(data);
	exit(EXIT_FAILURE);
}
void	destroy_img(t_data *data)
{
	if (data->square.bg)
		mlx_destroy_image(data->mlx.mlx_pointer, data->square.bg);
	if (data->square.wall)
		mlx_destroy_image(data->mlx.mlx_pointer, data->square.wall);
	if (data->square.collectible)
		mlx_destroy_image(data->mlx.mlx_pointer, data->square.collectible);
	if (data->square.player)
		mlx_destroy_image(data->mlx.mlx_pointer, data->square.player);
	if (data->square.floor)
		mlx_destroy_image(data->mlx.mlx_pointer, data->square.floor);
	if (data->square.exit)
		mlx_destroy_image(data->mlx.mlx_pointer, data->square.exit);
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	destroy_img(data);
	if (data->mlx.windows != NULL)
		mlx_destroy_window(data->mlx.mlx_pointer, data->mlx.windows);
	if (data->mlx.mlx_pointer != NULL)
	{
		mlx_destroy_display(data->mlx.mlx_pointer);
		free(data->mlx.mlx_pointer);
	}
	//Free la pasteque double tableau (la map)
}
int exit_game(t_data *data)
{
	free_all(data);
	exit(EXIT_SUCCESS);
	return (0); 
}

//Faire fonction qui free tout le contenu de data si ce nest pas null