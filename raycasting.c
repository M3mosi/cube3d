/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:03:22 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:03:23 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ray_calc(t_spawn *sp, t_var var, int x)
{
	sp->camerax = 2 * x / (double)var.rx - 1;
	sp->raydirx = sp->dirx + sp->planex * -sp->camerax;
	sp->raydiry = sp->diry + sp->planey * -sp->camerax;
}

void		var_dda(t_spawn *sp)
{
	sp->mapy = (int)sp->posy;
	sp->mapx = (int)sp->posx;
	sp->deltadistx = fabs(1 / sp->raydirx);
	sp->deltadisty = fabs(1 / sp->raydiry);
	sp->hit = 0;
	if (sp->raydirx < 0)
	{
		sp->stepx = -1;
		sp->sidedistx = (sp->posx - sp->mapx) * sp->deltadistx;
	}
	else
	{
		sp->stepx = 1;
		sp->sidedistx = (sp->mapx + 1.0 - sp->posx) * sp->deltadistx;
	}
	if (sp->raydiry < 0)
	{
		sp->stepy = -1;
		sp->sidedisty = (sp->posy - sp->mapy) * sp->deltadisty;
	}
	else
	{
		sp->stepy = 1;
		sp->sidedisty = (sp->mapy + 1.0 - sp->posy) * sp->deltadisty;
	}
}

void		dda(t_spawn *sp, char **map)
{
	sp->hit = 0;
	while (sp->hit == 0)
	{
		if (sp->sidedistx <= sp->sidedisty)
		{
			sp->sidedistx += sp->deltadistx;
			sp->mapx += sp->stepx;
			if (sp->stepx == 1)
				sp->side = 0;
			else if (sp->stepx == -1)
				sp->side = 2;
		}
		else if (sp->sidedistx > sp->sidedisty)
		{
			sp->sidedisty += sp->deltadisty;
			sp->mapy += sp->stepy;
			if (sp->stepy == 1)
				sp->side = 1;
			else if (sp->stepy == -1)
				sp->side = 3;
		}
		if (map[sp->mapy][sp->mapx] == '1')
			sp->hit = 1;
	}
}

void		tex_coord(t_spawn *sp, t_var var)
{
	if (sp->side == 0 || sp->side == 2)
		sp->wallx = sp->posy + sp->perpwalldist * sp->raydiry;
	else
		sp->wallx = sp->posx + sp->perpwalldist * sp->raydirx;
	sp->wallx -= floor((sp->wallx));
	sp->texx = (int)(sp->wallx * (double)64);
	if ((sp->side == 0 || sp->side == 2) && sp->raydirx > 0)
		sp->texx = 64 - sp->texx - 1;
	if ((sp->side == 1 || sp->side == 3) && sp->raydiry < 0)
		sp->texx = 64 - sp->texx - 1;
	sp->step = 1.0 * 64 / sp->lineheight;
	sp->texpos = (sp->drawstart - var.ry / 2 + sp->lineheight / 2) * sp->step;
}
