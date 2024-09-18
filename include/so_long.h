/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:25:58 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/18 14:24:19 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>

# include "structures.h"
# include "mlx.h"
# include "libft.h"

# define WALL "./textures/wall.xpm"
# define PLAYER "./textures/player.xpm"
# define EXIT "./textures/exit.xpm"
# define COLLECTIBLE "./textures/pumpkin1.xpm"
# define FLOOR "./textures/floor.xpm"
# define BACKGROUND "./textures/bg.xpm"

# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>


# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define ESC 65307

# define KEYPRESS 2
# define DST_N 17

# define WIDTH 640
# define HEIGHT 360


//ERRORS
int		exit_game(t_data *data);
void	ft_error(t_data *data, char *str);
void	free_all(t_data *data);
void	destroy_img(t_data *data);

#endif