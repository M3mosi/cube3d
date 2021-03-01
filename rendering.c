/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:05:08 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:05:09 by sgiovo           ###   ########.fr       */
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

int			check_mov(char c)
{
	if (c != '1' && c != '2')
		return (1);
	return (0);
}

void		hook_init2(t_sprite **s, t_data img, t_vars vars, t_hook *h)
{
	t_spr		*sprt;

	if (!(sprt = malloc(sizeof(t_spr))))
		return ;
	h->spr = sprt;
	h->sprite = s;
	h->img = img;
	h->vars = vars;
	h->nsprite = count_sprite(h->map);
	h->level = 1;
}

void		rendering(char **map, t_var var, int sw)
{
	t_vars		vars;
	t_data		img;
	t_spawn		sp;
	t_hook		h;
	t_sprite	**s;

	s = NULL;
	s = init_spawn(map, &sp, s);
	sp.sw = sw;
	if (!(sp.zbuff = malloc(sizeof(double) * (var.rx + 1))))
		return ;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, var.rx, var.ry, "Cub3D");
	img.img = mlx_new_image(vars.mlx, var.rx, var.ry);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	h = hook_init(map, var, sp, vars);
	hook_init2(s, img, vars, &h);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, set_key, &h);
	mlx_hook(vars.win, 3, 1L << 1, unset_key, &h);
	mlx_hook(vars.win, 17, 0, close_win, &h);
	mlx_loop_hook(vars.mlx, set_key_render, &h);
	mlx_loop(vars.mlx);
	free_all(&h);
}
