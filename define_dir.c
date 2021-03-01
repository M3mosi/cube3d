/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:00:24 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:00:25 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		north(t_spawn *spawn)
{
	spawn->dirx = 1;
	spawn->diry = 0;
	return ;
}

void		east(t_spawn *spawn)
{
	spawn->dirx = 0;
	spawn->diry = 1;
	return ;
}

void		south(t_spawn *spawn)
{
	spawn->dirx = -1;
	spawn->diry = 0;
	return ;
}

void		west(t_spawn *spawn)
{
	spawn->dirx = 0;
	spawn->diry = -1;
	return ;
}

void		find_direction(t_spawn *spawn, char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				north(spawn);
			else if (map[i][j] == 'E')
				east(spawn);
			else if (map[i][j] == 'S')
				south(spawn);
			else if (map[i][j] == 'W')
				west(spawn);
			j++;
		}
		i++;
	}
}
