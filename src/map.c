/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:07:59 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/24 09:16:11 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	map_reader(t_data *data, char *argv)
{
	int		nb_lines;
	int		fd;
	char	*tmp;

	nb_lines = 0;
	fd = open(argv, O_RDONLY);
	if (!fd)
		ft_error(data, "opening file failed");
	tmp = get_next_line(fd);
	// A voir plus tard si ca pose probleme
	data->map.column = ft_strlen(tmp) - 1;
	while (tmp)
	{
		nb_lines++;
		tmp = get_next_line(fd);
		// printf("%s\n", tmp);
		free(tmp);
	}
	close(fd);
	data->map.line = nb_lines;
	create_map(data, argv);
}

void	create_map(t_data *data, char *argv)
{
	int	i;
	int	fd;
	

	i = 0;
	fd = open(argv, O_RDONLY);
	if (!fd)
		ft_error(data, "opening file failed");
	data->map.map = malloc(sizeof(char *) * (data->map.line + 1));
	
	while (i < data->map.line)
	{
		data->map.map[i] = get_next_line(fd);
		printf("%s\n", data->map.map[i]);
		i++;
	}
}