/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:01:07 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:01:08 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_dda(t_spawn *sp, int x, t_hook *h)
{
	sp->camerax = 2 * x / (double)h->var.rx - 1;
	sp->raydirx = sp->dirx + sp->planex * -sp->camerax;
	sp->raydiry = sp->diry + sp->planey * -sp->camerax;
	sp->mapy = (int)sp->posy;
	sp->mapx = (int)sp->posx;
	sp->deltadistx = fabs(1 / sp->raydirx);
	sp->deltadisty = fabs(1 / sp->raydiry);
	sp->hit = 0;
}

void		var_dda_gun(t_spawn *sp, int x, t_hook *h)
{
	set_dda(sp, x, h);
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

int			dda_gun(t_spawn *sp, char **map, int *x, int *y)
{
	while (1)
	{
		if (sp->sidedistx <= sp->sidedisty)
			guny(sp);
		else if (sp->sidedistx > sp->sidedisty)
			gunx(sp);
		if (map[sp->mapy][sp->mapx] == '2')
		{
			*x = sp->mapx;
			*y = sp->mapy;
			return (1);
		}
		if (map[(int)sp->posy][(int)sp->posx] == '2')
		{
			*x = sp->mapx;
			*y = sp->mapy;
			return (1);
		}
		if (map[sp->mapy][sp->mapx] == '1')
			return (0);
	}
}

int			search_sprite(t_hook *h, int x, int y)
{
	int i;

	i = 0;
	while (h->sprite[i])
	{
		if ((int)h->sprite[i]->x == x && (int)h->sprite[i]->y == y)
			return (i);
		i++;
	}
	return (-1);
}

void		shoot(t_hook *h)
{
	int x;
	int y;
	int i;
	int x2;

	x2 = (h->var.rx / 2 - 1);
	while (x2 < (h->var.rx / 2 + 1))
	{
		var_dda_gun(h->sp, x2, h);
		if (dda_gun(h->sp, h->map, &x, &y))
		{
			if ((i = search_sprite(h, x, y)) == -1)
				return ;
			set_life_sprite(h, i);
			if (h->sprite[i]->life <= 0)
			{
				h->sprite[i]->k = 0;
				h->map[(int)h->sprite[i]->y][(int)h->sprite[i]->x] = '0';
			}
			break ;
		}
		x2++;
	}
}
