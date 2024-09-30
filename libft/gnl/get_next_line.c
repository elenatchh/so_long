/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:49:45 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/23 13:14:09 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char *str)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	buf = malloc(sizeof(char) * (ft_strlens(str) - i));
	if (!buf)
		return (free(str), NULL);
	j = i + 1;
	i = 0;
	while (str[j])
		buf[i++] = str[j++];
	buf[i] = '\0';
	return (free(str), buf);
}

char	*get_next_line(int fd)
{
	int			nbyte;
	char		*tamp;
	static char	*buffrest;
	char		*ret;

	nbyte = 1;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	tamp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tamp)
		return (NULL);
	while (nbyte && !ft_is_new_line(buffrest))
	{
		nbyte = read(fd, tamp, BUFFER_SIZE);
		if (nbyte == -1)
			return (ft_free_string(tamp));
		tamp[nbyte] = '\0';
		buffrest = ft_strjoin(buffrest, tamp);
		if (!buffrest)
			return (ft_free_string(tamp));
	}
	ret = ft_get_line(buffrest);
	buffrest = ft_next_line(buffrest);
	return (free(tamp), ret);
}
