/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:50:58 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/13 12:40:21 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>

char	*ft_get_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_next_line(char *str);

size_t	ft_strlen(const char *s);
char	*ft_free_string(char *str);
int		ft_is_new_line(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif