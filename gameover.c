/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:00:52 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:00:53 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		print_img(t_hook *h)
{
	int x;
	int y;
	int color;

	x = -resizer(h, 0);
	while (x < resizer(h, 0))
	{
		y = -resizer(h, 0);
		while (y < resizer(h, 0))
		{
			color = getcolor(h->tex[10],
							(x + resizer(h, 0)) / resizer(h, 1),
							(y + resizer(h, 0)) / resizer(h, 1), 0);
			if (color != -3351495)
				draw_dot(h, (h->var.rx / 2) + x,
						((h->var.ry / 2)) + y, color);
			y++;
		}
		x++;
	}
}

void		print_end(t_hook *h, int x)
{
	int y;

	y = 0;
	while (y < h->var.ry)
	{
		draw_dot(h, x, y, create_trgb(0, 128,
		0, 0));
		y++;
	}
}

int			print_gameover(t_hook *h)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < h->var.rx)
	{
		y = 0;
		while (y < h->var.ry)
		{
			draw_dot(h, x, y, create_trgb(0, 128,
			0, 0));
			y++;
		}
		x++;
	}
	print_img(h);
	print_level(h);
	return (0);
}
