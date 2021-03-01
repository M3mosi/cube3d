/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:04:56 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:04:57 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		call_func(t_hook *h, int x)
{
	ray_calc(h->sp, h->var, x);
	var_dda(h->sp);
	dda(h->sp, h->map);
	pwd_calc(h->sp);
	height_calc(h->sp, h->var);
	tex_coord(h->sp, h->var);
	print_wall(h, x);
	set_speed(h->sp);
}

void		ft_save_img(char *img, t_hook *h)
{
	int i;
	int fd;

	i = 0;
	fd = open("img.bmp", O_CREAT | O_WRONLY);
	while (img[i])
	{
		if (i % h->var.rx == 0)
			write(fd, &"\n", 1);
		write(fd, &img[i], 1);
		i++;
	}
	write(fd, 0, 1);
	close(fd);
}

void		raycasting2(t_hook *h)
{
	gunprinter(h);
	if (h->sp->shoot)
		shoot(h);
	h->sp->shoot = 0;
	if (h->sp->displayminimap)
		printmap(h);
	if (h->sp->life <= 0)
	{
		print_gameover(h);
	}
}

void		manage_bg(t_hook *h)
{
	if (h->var.swf && h->var.swc)
		print_floor(h);
	else
		print_flrgb(h);
}

int			raycasting(t_hook *h)
{
	int x;

	h->img.img = mlx_new_image(h->vars.mlx, h->var.rx, h->var.ry);
	h->img.addr = mlx_get_data_addr(h->img.img, &h->img.bits_per_pixel,
									&h->img.line_length, &h->img.endian);
	manage_bg(h);
	x = 0;
	while (x < h->var.rx)
	{
		call_func(h, x);
		x++;
	}
	movement_sprite(h);
	sprite_calc(h);
	raycasting2(h);
	if (h->sp->sw == 1)
	{
		screenshot(h->img, h->var, h);
		h->sp->sw = 0;
	}
	mlx_put_image_to_window(h->vars.mlx, h->vars.win, h->img.img, 0, 0);
	if (!(mlx_destroy_image(h->vars.mlx, h->img.img)))
		return (0);
	return (0);
}
