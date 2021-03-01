/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:00:42 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:00:43 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_floceal2(t_floceal *fl, int cellx, int celly)
{
	fl->floorx += fl->floorstepx;
	fl->floory += fl->floorstepy;
	fl->cbpatt = (int)(cellx + celly) & 1;
}

void		set_floceal(t_hook *h, int y)
{
	h->floceal->raydirya = -h->sp->diry - h->sp->planey;
	h->floceal->raydirxa = -h->sp->dirx - h->sp->planex;
	h->floceal->raydiryb = -h->sp->diry + h->sp->planey;
	h->floceal->raydirxb = -h->sp->dirx + h->sp->planex;
	h->floceal->p = y - h->var.ry / 2;
	h->floceal->posz = 0.5 * h->var.ry;
	h->floceal->rowdistance = -h->floceal->posz / h->floceal->p;
	h->floceal->floorstepx = h->floceal->rowdistance *
			(h->floceal->raydirxb - h->floceal->raydirxa) /
												h->var.rx;
	h->floceal->floorstepy = h->floceal->rowdistance *
		(h->floceal->raydiryb - h->floceal->raydirya) / h->var.rx;
	h->floceal->floorx = h->sp->posx + h->floceal->rowdistance *
											h->floceal->raydirxa;
	h->floceal->floory = h->sp->posy + h->floceal->rowdistance *
											h->floceal->raydirya;
}

void		print_background2(t_hook *h, t_var var,
							unsigned int **buffer)
{
	int x;
	int y;

	x = 0;
	while (x < var.rx)
	{
		y = 0;
		while (y < var.ry)
		{
			draw_dot(h, x, y, buffer[y][x]);
			y++;
		}
		x++;
	}
}

void		print_flrgb(t_hook *h)
{
	int				y;
	int				x;
	int				end;
	unsigned int	**buffer;

	buffer = buff_alloc(h->var.rx, h->var.ry);
	y = 0 - h->sp->appo;
	end = h->var.ry - h->sp->appo;
	while (y < end)
	{
		x = 0;
		while (x < h->var.rx)
		{
			if ((y + h->sp->appo) >= 0 && y < (h->var.ry / 2))
				buffer[y + h->sp->appo][x] = create_trgb(0, h->var.c[0],
				h->var.c[1], h->var.c[2]);
			if ((y + h->sp->appo) < h->var.ry && y > (h->var.ry / 2))
				buffer[y + h->sp->appo][x] = create_trgb(0, h->var.f[0],
				h->var.f[1], h->var.f[2]);
			x++;
		}
		y++;
	}
	print_background2(h, h->var, buffer);
	buff_free(buffer, h->var.ry);
}
