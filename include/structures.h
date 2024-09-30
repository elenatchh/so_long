/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:01:02 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/30 13:34:28 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "so_long.h"

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			h;
	int			w;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct s_square
{
	t_image		wall;
	t_image		floor;
	t_image		player;
	t_image		collectible;
	t_image		exit;
	t_image		image;
}				t_square;

typedef struct map
{
	char		**map;
	char		**copymap;
	int			line;
	int			column;
}				t_map;

typedef struct countitem
{
	int			player;
	int			collectible;
	int			exit;
}				t_countitem;

typedef struct pos
{
	int x;
	int y;
}			t_pos; 

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_square	square;
	t_map		map;
	t_countitem	countitem;
	int			fd;
	t_pos		pos;
}				t_data;

#endif