/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:01:02 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/18 13:10:06 by elefonta         ###   ########.fr       */
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

typedef	struct s_mlx
{
	void	*mlx_pointer;
	void	*windows;
}				t_mlx;

typedef	struct s_data
{
	t_mlx		mlx;
	t_square	square;
}				t_data;


#endif