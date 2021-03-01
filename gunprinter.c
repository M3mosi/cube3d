/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gunprinter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:01:18 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:01:19 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		print_level2(t_hook *h, int y, int x, int z)
{
	z = 0;
	while (z < 5)
	{
		y = 5;
		while (y < 20)
		{
			draw_dot(h, x, y, create_trgb(0, 255, 0, 0));
			y++;
		}
		z++;
		x--;
	}
	z = 0;
	while (z < 5)
	{
		y = 5;
		while (y < 20)
		{
			y++;
		}
		z++;
		x--;
	}
	return (x);
}

void	print_level(t_hook *h)
{
	int x;
	int y;
	int j;
	int z;

	x = h->var.rx - 5;
	y = 15;
	j = h->level;
	z = 0;
	while (j > 0)
	{
		x = print_level2(h, y, x, z);
		j--;
	}
}

int		resizer(t_hook *h, int mod)
{
	int x;
	int n;
	int i;

	x = h->var.rx / 7;
	i = 1;
	n = 0;
	while (n < (x * 2))
	{
		n = 64 * i;
		i++;
	}
	if (!mod)
		return (n / 2);
	return (i - 1);
}

void	gunrender(t_hook *h)
{
	int x;
	int y;
	int color;
	int texn;

	texn = 7;
	if (h->sp->shoot)
		texn = 8;
	x = -resizer(h, 0);
	while (x < resizer(h, 0))
	{
		y = -resizer(h, 0);
		while (y < resizer(h, 0))
		{
			color = getcolor(h->tex[texn],
							(x + resizer(h, 0)) / resizer(h, 1),
							(y + resizer(h, 0)) / resizer(h, 1), 0);
			if (color != -3351495)
				draw_dot(h, (h->var.rx / 2) + x + (h->var.rx / 6),
						(h->var.ry - resizer(h, 0)) + y, color);
			y++;
		}
		x++;
	}
}

void	gunprinter(t_hook *h)
{
	if (h->var.ry > 100)
	{
		print_life(h);
		print_level(h);
		gunrender(h);
	}
	if (h->var.ry > 15)
		mirino(h);
}
