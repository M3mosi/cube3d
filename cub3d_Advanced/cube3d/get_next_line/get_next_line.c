/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:29:12 by forsili           #+#    #+#             */
/*   Updated: 2021/01/21 14:29:15 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc(char *str, int mod)
{
	char *tmp;

	if (mod == 0)
		if (!(tmp = malloc((ft_strlen_int(str) + BUFFER_SIZE + 1) * sizeof(char))))
			return (0);
	if (mod == 1)
		if (!(tmp = malloc((ft_strlen_int(str) + 1) * sizeof(char))))
			return (0);
	tmp = ft_strcpy(tmp, str);
	free(str);
	return (tmp);
}

int		empty_buf(char buf[4064][BUFFER_SIZE], char **line, int fd, int j)
{
	int k;

	k = 0;
	j = ft_strlen_int(*line);
	if (!(check_zero(buf, fd)))
	{
		while (buf[fd][k] != '\n' && k < BUFFER_SIZE)
		{
			if (buf[fd][k] != 0)
			{
				(*line)[j] = buf[fd][k];
				buf[fd][k] = 0;
				j++;
			}
			k++;
		}
		(*line)[j] = 0;
	}
	if (buf[fd][k] == '\n')
	{
		buf[fd][k] = 0;
		*line = alloc(*line, 1);
		return (1);
	}
	return (0);
}

int		check_buf(char buf[4064][BUFFER_SIZE], char **line, int fd)
{
	int res_read;
	int j;

	j = 0;
	if (empty_buf(buf, line, fd, j))
	{
		*line = alloc(*line, 1);
		return (1);
	}
	*line = alloc(*line, 0);
	res_read = (read(fd, buf[fd], BUFFER_SIZE));
	if (res_read <= 0)
	{
		*line = alloc(*line, 1);
		return (res_read);
	}
	return (2);
}

int		get_next_line(int fd, char **line)
{
	static char		buf[4064][BUFFER_SIZE];
	int				exit;

	exit = 2;
	if (fd < 0 || fd > 256 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(*line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	ft_bzero(*line, BUFFER_SIZE);
	while (exit == 2)
		exit = check_buf(buf, line, fd);
	if (exit != 2)
		return (exit);
	return (-1);
}
