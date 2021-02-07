/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:57:41 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/05 10:43:46 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void		print_background(t_var var, t_data img)
{
	int x;
	int y;

	x = 0;
	while (x < var.rx)
	{
		y = 0;
		while (y < var.ry / 2)
			my_mlx_pixel_put(&img, x, y++, create_trgb(0, var.c[0],
							var.c[1], var.c[2]));
		x++;
	}
	x = 0;
	while (x < var.rx)
	{
		y = var.ry / 2;
		while (y < var.ry)
			my_mlx_pixel_put(&img, x, y++, create_trgb(0, var.f[0],
							var.f[1], var.f[2]));
		x++;
	}
}

void		printmap(t_hook *h)
{
	int i;
	int k;

	i = 0;
	while (h->map[i])
	{
		k = 0;
		while (h->map[i][k])
		{
			if (i != (int)h->sp->posy || k != (int)h->sp->posx)
				printf("%c", h->map[i][k]);
			else
				printf("%c", ' ');
			k++;
		}
		printf("\n");
		i++;
	}
	printf("\n\n");
}

int			unset_key(int keycode, t_hook *h)
{
	double olddirx;
	double oldplanex;

	if (keycode == 123)
		h->sp->lr = 0;
	if (keycode == 124)
		h->sp->lr = 0;
	if (keycode == 13)
		h->sp->fb = 0;
	if (keycode == 257)
	{
		h->sp->jump = 0;
		h->sp->appo = 0;
	}
	if (keycode == 12)
		h->sp->sprint = 0;
	return (0);
}

int			set_key(int keycode, t_hook *h)
{
	double olddirx;
	double oldplanex;

	if (keycode == 123)
		h->sp->lr = 1;
	if (keycode == 124)
		h->sp->lr = -1;
	if (keycode == 13)
		h->sp->fb = 1;
	if (keycode == 49)
		h->sp->jump = 1;
	if (keycode == 257)
		h->sp->jump = -1;
	if (keycode == 12)
		h->sp->sprint = 1;
	if (keycode == 53)
		exit(0);
	return (0);
}

int			set_key_render(t_hook *h)
{
	double olddirx;
	double oldplanex;

	if (h->sp->lr == 1)
	{
		olddirx = h->sp->dirx;
		h->sp->dirx = h->sp->dirx * cos(-h->sp->rotspeed) - h->sp->diry
					* sin(-h->sp->rotspeed);
		h->sp->diry = olddirx * sin(-h->sp->rotspeed) + h->sp->diry
					* cos(-h->sp->rotspeed);
		oldplanex = h->sp->planex;
		h->sp->planex = h->sp->planex * cos(-h->sp->rotspeed) - h->sp->planey
					* sin(-h->sp->rotspeed);
		h->sp->planey = oldplanex * sin(-h->sp->rotspeed) + h->sp->planey
					* cos(-h->sp->rotspeed);
	}
	if (h->sp->lr == -1)
	{
		olddirx = h->sp->dirx;
		h->sp->dirx = h->sp->dirx * cos(h->sp->rotspeed) - h->sp->diry
					* sin(h->sp->rotspeed);
		h->sp->diry = olddirx * sin(h->sp->rotspeed) + h->sp->diry
					* cos(h->sp->rotspeed);
		oldplanex = h->sp->planex;
		h->sp->planex = h->sp->planex * cos(h->sp->rotspeed) - h->sp->planey
					* sin(h->sp->rotspeed);
		h->sp->planey = oldplanex * sin(h->sp->rotspeed) + h->sp->planey
					* cos(h->sp->rotspeed);
	}
	if (h->sp->fb == 1)
	{
		//printmap(h);
		if (h->map[(int)(h->sp->posy + h->sp->diry * h->sp->movspeed)][(int)(h->sp->posx)] != '1')
			h->sp->posy += h->sp->diry * h->sp->movspeed;
		if (h->map[(int)(h->sp->posy)][(int)(h->sp->posx + h->sp->dirx * h->sp->movspeed)] != '1')
			h->sp->posx += h->sp->dirx * h->sp->movspeed;
	}
	if (h->sp->jump == 1)
	{
		if (!h->sp->appo)
			h->sp->appo = 1;
		if ((h->sp->appo * 2) < 400 && h->sp->swjp == 0)
			h->sp->appo += 30;
		else if ((h->sp->appo * 2) > 200 && h->sp->swjp == 0)
			h->sp->swjp = 1;
		if ((h->sp->appo / 2) <= 0 && h->sp->swjp == 1)
		{
			h->sp->jump = 0;
			h->sp->swjp = 0;
			h->sp->appo = 1;
		}
		else if ((h->sp->appo / 2) > 0 && h->sp->swjp == 1)
			h->sp->appo = h->sp->appo - 30;
	}
	if (h->sp->jump == -1)
	{
		h->sp->appo = -50;
	}
	if (h->sp->sprint == 1)
	{
		h->sp->rotspeed = 0.3;
		h->sp->movspeed = 0.5;
	}
	raycasting(h);
	return (0);
}

void		rendering(char **map, t_var var)
{
	t_vars	vars;
	t_data	img;
	t_spawn	sp;
	t_hook	h;

	init_spawn(map, &sp);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, var.rx, var.ry, "Cub3D");
	img.img = mlx_new_image(vars.mlx, var.rx, var.ry);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	print_background(var, img);
	h = hook_init(map, var, sp, vars);
	h.img = img;
	h.vars = vars;
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, set_key, &h);
	mlx_hook(vars.win, 3, 1L << 1, unset_key, &h);
	mlx_loop_hook(vars.mlx, set_key_render, &h);
	mlx_loop(vars.mlx);
	map = NULL;
}
