/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:29:44 by forsili           #+#    #+#             */
/*   Updated: 2021/01/21 14:29:46 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen_int(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		check_zero(char buf[4096][BUFFER_SIZE], int fd)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[fd][i] == 0)
			count++;
		i++;
	}
	if (count == BUFFER_SIZE)
		return (1);
	return (0);
}
