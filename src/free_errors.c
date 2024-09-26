/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:13:28 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/26 14:32:58 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_error(t_data *data, char *str)
{
	write(2, "Error: ", 7);
	if (str)
		write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	free_all(data);
	exit(EXIT_FAILURE);
}
void	destroy_img(t_data *data)
{
	if (data->square.wall.img) {
		mlx_destroy_image(data->mlx, data->square.wall.img);
		printf("image destroy l29 free_errors.c\n");
	}
	if (data->square.collectible.img)
		mlx_destroy_image(data->mlx, data->square.collectible.img);
	if (data->square.player.img)
		mlx_destroy_image(data->mlx, data->square.player.img);
	if (data->square.floor.img)
		mlx_destroy_image(data->mlx, data->square.floor.img);
	if (data->square.exit.img)
		mlx_destroy_image(data->mlx, data->square.exit.img);
}

void	free_all(t_data *data)
{
	destroy_img(data);
	if (data->fd != 0)
		close(data->fd);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
	{
		printf("free mlx l50\n");
		// mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map.map)
		ft_free_matrix(&(data->map.map));
	if (data->map.copymap != NULL)
		ft_free_matrix(&(data->map.copymap));
}
int exit_game(t_data *data)
{
	free_all(data);
	exit(EXIT_SUCCESS);
	return (0);
}
//Faire fonction qui free tout le contenu de data si ce nest pas null