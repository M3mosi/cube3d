/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:00:34 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:00:36 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				print_background(t_hook *h, t_var var,
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

void				ft_helper(t_hook *h, int y, unsigned int **buffer, int x)
{
	int tx;
	int ty;
	int cellx;
	int celly;

	while (x < h->var.rx)
	{
		cellx = (int)(h->floceal->floorx);
		celly = (int)(h->floceal->floory);
		tx = (int)(64 * (h->floceal->floorx - cellx)) & (63);
		ty = (int)(64 * (h->floceal->floory - celly)) & (63);
		set_floceal2(h->floceal, cellx, celly);
		if (h->floceal->cbpatt == 0)
			h->floceal->floortex = 4;
		h->floceal->ceiltex = 6;
		h->floceal->color = h->tex[0]->buff[64 * ty + tx];
		h->floceal->color = h->tex[0]->buff[64 * ty + tx];
		if ((y + h->sp->appo) < (h->var.ry) && (y + h->sp->appo) >= (0))
			buffer[y + h->sp->appo][x] = getcolor(h->tex[5], tx, ty, 64);
		if ((h->var.ry + h->sp->appo - y - 1) < (h->var.ry) &&
			(h->var.ry + h->sp->appo - y - 1) >= (0))
			buffer[h->var.ry + h->sp->appo - y - 1][x] =
					getcolor(h->tex[6], tx, ty, 64);
		x++;
	}
}

unsigned int		**buff_alloc(int x, int y)
{
	unsigned int	**buff;
	int				i;

	if (!(buff = ft_calloc((y + 1), sizeof(unsigned int *))))
		return (NULL);
	i = 0;
	while (i < y)
		if (!(buff[i++] = ft_calloc((x + 1), sizeof(unsigned int))))
			return (NULL);
	buff[i] = 0;
	return (buff);
}

void				buff_free(unsigned int **buff, int y)
{
	int				i;

	i = 0;
	while (i < y)
	{
		free(buff[i]);
		i++;
	}
	free(buff);
}

void				print_floor(t_hook *h)
{
	int				y;
	int				end;
	unsigned int	**buffer;

	buffer = buff_alloc(h->var.rx, h->var.ry);
	y = 0;
	end = (h->sp->appo >= 0) ?
			h->var.ry + h->sp->appo : h->var.ry + h->sp->appo * -2;
	while (y < end)
	{
		set_floceal(h, y);
		ft_helper(h, y, buffer, 0);
		y++;
	}
	print_background(h, h->var, buffer);
	buff_free(buffer, h->var.ry);
}
