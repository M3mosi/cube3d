/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:03:17 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:03:18 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		max_line(t_hook *h)
{
	int i;
	int max;

	max = 0;
	i = 0;
	while (h->map[i])
	{
		if ((int)ft_strlen(h->map[i]) > max)
			max = (int)ft_strlen(h->map[i]);
		i++;
	}
	return (max);
}

void	color_calc(t_hook *h, int x[2], int y[2])
{
	if (h->map[x[1]][y[1]] == '0' || h->map[x[1]][y[1]] == 'N' ||
		h->map[x[1]][y[1]] == 'W' ||
		h->map[x[1]][y[1]] == 'E' || h->map[x[1]][y[1]] == 'S')
		my_mlx_pixel_put(&h->img, y[0], x[0], create_trgb(200, 64,
							64, 64));
	else if (h->map[x[1]][y[1]] == '2')
		my_mlx_pixel_put(&h->img, y[0], x[0], create_trgb(0, 255,
							102, 255));
	if (y[1] == (int)h->sp->posx && x[1] == (int)h->sp->posy)
		my_mlx_pixel_put(&h->img, y[0], x[0], create_trgb(0, 0,
							255, 255));
}

void	put_img_minimap(t_hook *h)
{
	int x[2];
	int y[2];
	int sizex[2];
	int sizey[2];

	x[0] = 0;
	x[1] = 0;
	sizex[0] = 4;
	sizey[0] = 4;
	sizex[1] = (sizex[0] * ar_length(h->map));
	sizey[1] = sizey[0] * (max_line(h) / 2);
	while (x[0] < sizex[1])
	{
		y[0] = ((h->var.rx / 2) - sizey[1]);
		y[1] = 0;
		while (y[0] < ((h->var.rx / 2) + sizey[1]))
		{
			if ((y[0] % sizey[0]) == 0 && h->map[x[1]][y[1] + 1])
				y[1]++;
			color_calc(h, x, y);
			y[0]++;
		}
		((x[0] % sizey[0]) == 0 && h->map[x[1] + 1]) ? x[1]++ : x[1];
		x[0]++;
	}
}

void	printmap(t_hook *h)
{
	put_img_minimap(h);
}
