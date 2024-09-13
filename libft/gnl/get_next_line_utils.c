/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:50:45 by elefonta          #+#    #+#             */
/*   Updated: 2024/04/25 11:58:49 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sj;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	sj = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!sj)
		return (NULL);
	while (s1[++i])
		sj[i] = s1[i];
	while (s2[j])
		sj[i++] = s2[j++];
	sj[i] = '\0';
	return (free(s1), sj);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_free_string(char *str)
{
	free(str);
	return (NULL);
}

int	ft_is_new_line(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_get_line(char *str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	j = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	buff = malloc(sizeof(char) * (i + 2));
	if (!buff)
		return (0);
	while (j <= i)
	{
		buff[j] = str[j];
		j++;
	}
	buff[j] = '\0';
	return (buff);
}
