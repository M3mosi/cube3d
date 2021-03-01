/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:06:55 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:06:56 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			print_stripe(t_hook *h, int d, int y, int c)
{
	int n;

	n = 4;
	if (h->sprite[h->s_instampa]->life < 100)
		n = 9;
	d = (y) * 256 - h->var.ry * 128 + h->spr->sprheight * 128;
	h->spr->texy = ((d * 64) / h->spr->sprheight) / 256;
	c = ((unsigned int *)(h->tex[n]->buff))[(int)(h->tex[n]->height
									* h->spr->texy + h->spr->texx)];
	if (c != 13491257)
	{
		draw_dot(h, h->spr->stripe, y + h->sp->appo,
					getcolor(h->tex[4], h->spr->texx, h->spr->texy,
											h->sp->perpwalldist));
	}
	return (++y);
}

void		print_sprite(t_hook *h)
{
	int d;
	int y;
	int	c;

	c = 0;
	d = 0;
	while (h->spr->stripe < h->spr->sprdrawendx)
	{
		h->spr->texx = (int)(256 * (h->spr->stripe -
				(-(h->spr->sprwidth) / 2 + h->spr->screenx))
				* 64 / h->spr->sprwidth) / 256;
		if (h->spr->transy > 0 && h->spr->stripe > 0 &&
			h->spr->stripe < h->var.rx &&
			h->spr->transy < h->sp->zbuff[h->spr->stripe])
		{
			y = h->spr->sprdrawstarty;
			while (y < h->spr->sprdrawendy)
				y = print_stripe(h, d, y, c);
		}
		h->spr->stripe++;
	}
}

void		next_level(t_hook *h)
{
	int i;
	int k;

	i = 0;
	while (h->map[i])
	{
		k = 0;
		while (h->map[i][k])
		{
			if (h->map[i][k] == '0')
			{
				if ((rand() % 800) <= (h->level))
					h->map[i][k] = '2';
			}
			if (h->map[i][k] == 'N' || h->map[i][k] == 'S'
				|| h->map[i][k] == 'E' || h->map[i][k] == 'W')
				h->map[i][k] = '0';
			k++;
		}
		i++;
	}
	h->level++;
}

void		sprite_var(t_hook *h, int i, int *spr_ord)
{
	h->spr->spritex = h->sprite[spr_ord[i]]->x - h->sp->posx;
	h->spr->spritey = h->sprite[spr_ord[i]]->y - h->sp->posy;
	h->spr->invcam = 1.0 / (h->sp->planex * h->sp->diry -
							h->sp->dirx * h->sp->planey);
	h->spr->transx = -h->spr->invcam * (h->sp->diry * h->spr->spritex
									- h->sp->dirx * h->spr->spritey);
	h->spr->transy = h->spr->invcam * (-(h->sp->planey) * h->spr->spritex
										+ h->sp->planex * h->spr->spritey);
	h->spr->screenx = (int)((h->var.rx / 2) *
					(1 + h->spr->transx / h->spr->transy));
	h->spr->sprheight = abs((int)(h->var.ry / (h->spr->transy)));
	h->spr->sprdrawstarty = -(h->spr->sprheight) / 2 + h->var.ry / 2;
	if (h->spr->sprdrawstarty < 0)
		h->spr->sprdrawstarty = 0;
	h->spr->sprdrawendy = h->spr->sprheight / 2 + h->var.ry / 2;
	if (h->spr->sprdrawendy >= h->var.ry)
		h->spr->sprdrawendy = h->var.ry - 1;
	h->spr->sprwidth = abs((int)(h->var.ry / (h->spr->transy)));
	h->spr->sprdrawstartx = -(h->spr->sprwidth) / 2 + h->spr->screenx;
	if (h->spr->sprdrawstartx < 0)
		h->spr->sprdrawstartx = 0;
	h->spr->sprdrawendx = h->spr->sprwidth / 2 + h->spr->screenx;
	if (h->spr->sprdrawendx >= h->var.rx)
		h->spr->sprdrawendx = h->var.rx - 1;
	h->spr->stripe = h->spr->sprdrawstartx;
}

void		manage_sprite(t_hook *h, int i, int *spr_ord)
{
	h->s_instampa = spr_ord[i];
	sprite_var(h, i, spr_ord);
	print_sprite(h);
}
