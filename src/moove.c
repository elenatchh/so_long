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

void	move_player(t_data *data, int x, int y, int code_mvt)
{
	// Dès qu'il trouve un collectible, on décrémente le compteur de collectibles pour
	// savoir à quel moment on les aura tous récuperés, pour quitter le jeu ensuite
	if (data->map.map[y][x] == 'C')
		data->countitem.collectible--;
	// Si on arrive sur la sortie et qu'on a récupéré tous les collectibles, on quitte le jeu
	if (data->map.map[y][x] == 'E' && data->countitem.collectible == 0)
		exit_game(data);
	// En fonction du code de mouvement envoyé par touchexit, on remplace l'ancienne position
	// du joueur par l'image du sol, et on met l'image du joueur à la nouvelle position
	if (data->map.map[y][x] != '1' && data->map.map[y][x] != 'E')
	{
		// A chaque appel de cette fonction, on incrémente le compteur de mouvements
		data->countitem.moves++;
		data->pos.x = x;
		data->pos.y = y;
		if (code_mvt == 0)
			put_img_to_img(data->square.image, data->square.floor,
				data->pos.x * 60, (data->pos.y + 1) * 60);
		else if (code_mvt == 1)
			put_img_to_img(data->square.image, data->square.floor,
				data->pos.x * 60, (data->pos.y - 1) * 60);
		else if (code_mvt == 2)
			put_img_to_img(data->square.image, data->square.floor,
				(data->pos.x - 1) * 60, data->pos.y * 60);
		else if (code_mvt == 3)
			put_img_to_img(data->square.image, data->square.floor,
				(data->pos.x + 1) * 60, data->pos.y * 60);
		put_img_to_img(data->square.image, data->square.player,
			data->pos.x * 60, data->pos.y * 60);
		// On affiche l'image finale
		mlx_put_image_to_window(data->mlx, data->win, data->square.image.img, 0, 0);
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
