/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:03:31 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:03:32 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		pwd_calc(t_spawn *sp)
{
	if (sp->side == 0 || sp->side == 2)
		sp->perpwalldist = (sp->mapx - sp->posx +
							(1 - sp->stepx) / 2) / sp->raydirx;
	else
		sp->perpwalldist = (sp->mapy - sp->posy +
							(1 - sp->stepy) / 2) / sp->raydiry;
}

void		height_calc(t_spawn *sp, t_var var)
{
	sp->lineheight = (int)(var.ry / sp->perpwalldist);
	sp->drawstart = -sp->lineheight / 2 + var.ry / 2;
	if (sp->drawstart < 0 - sp->appo)
		sp->drawstart = 0 - sp->appo;
	sp->drawend = sp->lineheight / 2 + var.ry / 2;
	if (sp->drawend >= var.ry - sp->appo)
		sp->drawend = var.ry - sp->appo;
}

void		set_speed(t_spawn *sp)
{
	if (sp->sprint && sp->jump != -1)
	{
		sp->movspeed = 0.13;
		sp->rotspeed = 0.09;
	}
	else if (sp->jump == -1)
	{
		sp->movspeed = 0.03;
		sp->rotspeed = 0.02;
	}
	else
	{
		sp->movspeed = 0.07;
		sp->rotspeed = 0.09;
	}
}

void		draw_dot(t_hook *h, int x, int y, int color)
{
	char	b;
	char	g;
	char	r;
	int		i;

	if (color == 256 * 256 * 256 + 256 * 256 + 256)
		return ;
	b = color % 256;
	g = (color / 256) % 256;
	r = (color / 256 / 256) % 256;
	i = (h->img.line_length * y) + (x * ((double)h->img.bits_per_pixel / 8));
	h->img.addr[i] = b;
	h->img.addr[i + 1] = g;
	h->img.addr[i + 2] = r;
	h->img.addr[i + 3] = 200 - (h->sp->life * 2);
}

int			getcolor(t_tex *tex, int x, int y, int fade)
{
	int	color;
	int	c;

	fade /= 8;
	c = (y * tex->width + x) * 4;
	color = tex->buff[c];
	if (color == -120 && tex->buff[c + 1] == 0 && tex->buff[c + 2] == -104)
		return (256 * 256 * 256 + 256 * 256 + 256);
	color += tex->buff[c + 1] * 256;
	color += tex->buff[c + 2] * 256 * 256;
	return (color);
}
