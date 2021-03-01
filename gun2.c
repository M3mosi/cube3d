/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:01:12 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:01:13 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		gunx(t_spawn *sp)
{
	sp->sidedisty += sp->deltadisty;
	sp->mapy += sp->stepy;
	if (sp->stepy == 1)
		sp->side = 1;
	else if (sp->stepy == -1)
		sp->side = 3;
}

void		guny(t_spawn *sp)
{
	sp->sidedistx += sp->deltadistx;
	sp->mapx += sp->stepx;
	if (sp->stepx == 1)
		sp->side = 0;
	else if (sp->stepx == -1)
		sp->side = 2;
}

void		set_life_sprite(t_hook *h, int i)
{
	if (h->sp->jump > 0)
		h->sprite[i]->life = 0;
	else
		h->sprite[i]->life -= 50;
}
