/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:01:02 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/23 13:22:59 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "so_long.h"

typedef struct s_square
{
	void		*wall;
	void		*floor;
	void		*player;
	void		*collectible;
	void		*exit;
	void		*bg;
}				t_square;

typedef struct map
{
	char 	**map;
	int		line;
	int		column;
}			t_map;

typedef	struct s_mlx
{
	void	*mlx_pointer;
	void	*windows;
}				t_mlx;

typedef	struct s_data
{
	t_mlx		mlx;
	t_square	square;
	t_map		map;
}				t_data;


#endif