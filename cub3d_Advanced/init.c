/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonegiovo <simonegiovo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:20:27 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/07 16:53:07 by simonegiovo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_hook		hook_init(char **map, t_var var, t_spawn spawn, t_vars vars)
{
	t_hook	h;
	int		width;
	int		height;

	h.tex[0] = mlx_xpm_file_to_image(vars.mlx, var.no, &width, &height);
	h.tex[1] = mlx_xpm_file_to_image(vars.mlx, var.so, &width, &height);
	h.tex[2] = mlx_xpm_file_to_image(vars.mlx, var.ea, &width, &height);
	h.tex[3] = mlx_xpm_file_to_image(vars.mlx, var.we, &width, &height);
	h.tex[4] = mlx_xpm_file_to_image(vars.mlx, var.s, &width, &height);
	h.map = map;
	h.var = var;
	h.sp = &spawn;
	return (h);
}

void		set_dir(t_spawn *sp, char c)
{
	sp->lr = 0;
	sp->fb = 0;
	sp->jump = 0;
	sp->appo = 0;
	sp->swjp = 0;
	sp->sprint = 0;
	sp->hit_sprite = 0;
	if (c == 'N')
	{
		sp->dirx = 0;
		sp->diry = -1;
		sp->planex = -0.70;
		sp->planey = 0;
	}
	else if (c == 'E')
	{
		sp->dirx = 1;
		sp->diry = 0;
		sp->planex = 0;
		sp->planey = -0.66;
	}
	else if (c == 'S')
	{
		sp->dirx = 0;
		sp->diry = 1;
		sp->planex = 0.66;
		sp->planey = 0;
	}
	else if (c == 'W')
	{
		sp->dirx = -1;
		sp->diry = 0;
		sp->planex = 0;
		sp->planey = 0.66;
	}
}

void		init_spawn(char **map, t_spawn *sp)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' ||
				map[i][j] == 'W')
			{
				set_dir(sp, map[i][j]);
				sp->posy = (double)i + 0.5;
				sp->posx = (double)j + 0.5;
			}
			j++;
		}
		i++;
	}
}
