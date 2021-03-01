/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:59:42 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 11:59:44 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_check(char **map, int i, int j)
{
	if (valid_char_no_one(map[i][j]))
	{
		if ((int)ft_strlen(map[i - 1]) < j)
			return (0);
		if ((int)ft_strlen(map[i + 1]) < j)
			return (0);
		if (j == 0 || j == (int)ft_strlen(map[i]))
			return (0);
		if (!valid_char2(map[i + 1][j]) || !valid_char2(map[i - 1][j]) ||
			!valid_char2(map[i][j + 1]) || !valid_char2(map[i][j - 1]))
			return (0);
	}
	return (1);
}

int		check_diagonal(char **map, size_t size)
{
	size_t i;
	size_t j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (map[i][j])
		{
			if (!check_check(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_line(char **map, size_t size)
{
	int i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != ' ' && map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[size][i])
	{
		if (map[size][i] != 49 && map[size][i] != ' ')
			return (0);
		i++;
	}
	if (!check_diagonal(map, size))
		return (0);
	else
		return (1);
}

int		check_char(char **map)
{
	int i;
	int j;
	int flag;

	i = 0;
	flag = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!valid_char(map[i][j]))
				return (0);
			if (flag == 0 && is_char(map[i][j]))
				flag = 1;
			else if (flag == 1 && is_char(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (!flag)
		return (0);
	return (1);
}

void	check_map(char **map)
{
	size_t	size;

	size = manage_map(map);
	if (!check_char(map) || !check_line(map, size - 1))
		invalid_map_err(map);
}
