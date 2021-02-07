/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonegiovo <simonegiovo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:18:39 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/07 18:29:28 by simonegiovo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ray_calc(t_spawn *sp, t_var var, int x)
{
	sp->camerax = 2 * x / (double)var.rx - 1;
	sp->raydirx = sp->dirx + sp->planex * -sp->camerax;
	sp->raydiry = sp->diry + sp->planey * -sp->camerax;
}

void		var_dda(t_spawn *sp)
{
	sp->mapy = (int)sp->posy;
	sp->mapx = (int)sp->posx;
	sp->deltadistx = fabs(1 / sp->raydirx);
	sp->deltadisty = fabs(1 / sp->raydiry);
	sp->hit = 0;
	if (sp->raydirx < 0)
	{
		sp->stepx = -1;
		sp->sidedistx = (sp->posx - sp->mapx) * sp->deltadistx;
	}
	else
	{
		sp->stepx = 1;
		sp->sidedistx = (sp->mapx + 1.0 - sp->posx) * sp->deltadistx;
	}
	if (sp->raydiry < 0)
	{
		sp->stepy = -1;
		sp->sidedisty = (sp->posy - sp->mapy) * sp->deltadisty;
	}
	else
	{
		sp->stepy = 1;
		sp->sidedisty = (sp->mapy + 1.0 - sp->posy) * sp->deltadisty;
	}
}

void		dda(t_spawn *sp, char **map)
{
	while (sp->hit == 0)
	{
		if (sp->sidedistx < sp->sidedisty)
		{
			sp->sidedistx += sp->deltadistx;
			sp->mapx += sp->stepx;
			if (sp->stepx == 1)
				sp->side = 0;
			else if (sp->stepx == -1)
				sp->side = 2;
		}
		else if (sp->sidedistx > sp->sidedisty)
		{
			sp->sidedisty += sp->deltadisty;
			sp->mapy += sp->stepy;
			if (sp->stepy == 1)
				sp->side = 1;
			else if (sp->stepy == -1)
				sp->side = 3;
		}
		if (map[sp->mapy][sp->mapx] == '1')
			sp->hit = 1;
	}
}

int	check_circle(t_spawn *sp, char **map)
{
	double x;
	double y;
	double dist;

	printf("x %f y %f \n", sp->posx, sp->posy);
	if (sp->posx > sp->sidedistx)
		x = (double)sp->posx - (sp->sidedistx - sp->deltadistx + (sp->deltadistx / 2));
	else
		x = (sp->sidedistx - sp->deltadistx + (sp->deltadistx / 2)) - (double)sp->posx;
	if (sp->posy > sp->sidedisty)
		y = (double)sp->posy - (sp->sidedisty - sp->deltadisty +(sp->deltadisty / 2));
	else
		y = (sp->sidedisty - sp->deltadisty +(sp->deltadisty / 2)) - (double)sp->posy;
	if (y > (sp->mapy + 0-5))
	{
		if (x > ((double)sp->mapx + 0.5))
			dist = sqrt((pow(y - ((double)sp->mapy + 0.5), 2)) + (pow(x - ((double)sp->mapx + 0.5), 2)));
		else
			dist = sqrt((pow(y - ((double)sp->mapy + 0.5), 2)) + (pow(((double)sp->mapx + 0.5) - x ,2)));
	}
	else if (y > ((double)sp->mapy + 0-5))
	{
		if (x > ((double)sp->mapx +0.5))
			dist = sqrt((pow(((double)sp->mapy + 0.5) - y, 2)) + (pow(x - ((double)sp->mapx + 0.5), 2)));
		else
			dist = sqrt((pow(((double)sp->mapy + 0.5) - y, 2)) + (pow(((double)sp->mapx + 0.5) - x, 2)));
	}
	printf("x %f y %f mx %d my %d dist %f\n", x, y, sp->mapx, sp->mapy, dist);
	if (dist <= 1)
		return (1);
	return (0);
}

void		dda_sprite(t_spawn *sp, char **map)
{

	sp->hit_sprite = 0;
	while (sp->hit_sprite == 0)
	{
		if (sp->sidedistx < sp->sidedisty)
		{
			sp->sidedistx += sp->deltadistx;
			sp->mapx += sp->stepx;
			if (sp->stepx == 1)
				sp->side = 0;
			else if (sp->stepx == -1)
				sp->side = 2;
		}
		else if (sp->sidedistx > sp->sidedisty)
		{
			sp->sidedisty += sp->deltadisty;
			sp->mapy += sp->stepy;
			if (sp->stepy == 1)
				sp->side = 1;
			else if (sp->stepy == -1)
				sp->side = 3;
		}
		if (map[sp->mapy][sp->mapx] == '2')
		{
			//printf("%f \n");
			if (check_circle(sp, map))
				sp->hit_sprite = 1;
		}
		if (map[sp->mapy][sp->mapx] == '1')
			sp->hit_sprite = -1;
	}
}

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
	if (sp->drawstart < 0)
		sp->drawstart = 0;
	sp->drawend = sp->lineheight / 2 + var.ry / 2;
	if (sp->drawend >= var.ry)
		sp->drawend = var.ry;
}

void		tex_coord(t_spawn *sp, t_var var)
{
	if (sp->side == 0 || sp->side == 2)
		sp->wallx = sp->posy + sp->perpwalldist * sp->raydiry;
	else
		sp->wallx = sp->posx + sp->perpwalldist * sp->raydirx;
	sp->wallx -= floor((sp->wallx));
	sp->texx = (int)(sp->wallx * (double)64);
	if ((sp->side == 0 || sp->side == 2) && sp->raydirx > 0)
		sp->texx = 64 - sp->texx - 1;
	if ((sp->side == 1 || sp->side == 3) && sp->raydiry < 0)
		sp->texx = 64 - sp->texx - 1;
	sp->step = 1.0 * 64 / sp->lineheight;
	sp->texpos = (sp->drawstart - var.ry / 2 + sp->lineheight / 2) * sp->step;
}

void	set_speed(t_spawn *sp)
{
	sp->movspeed = 0.07;
	sp->rotspeed = 0.07;
}

void	draw_dot(t_hook *h, int x, int y, int color)
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
}

int		getcolor(t_tex *tex, int x, int y, int fade)
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

void		print_sprite(t_hook *h, int x)
{
	int	y;
	int	temp;
	int	color;

	if (h->map[h->sp->mapy][h->sp->mapx] == '2')
	{
		y = h->sp->drawstart;
		while (y <= h->sp->drawend)
		{
			h->sp->texpos += h->sp->step;
			
			h->sp->texy = (int)h->sp->texpos & (h->tex[4]->height - 1);
			draw_dot(h, x, y + h->sp->appo, getcolor(h->tex[4],
				h->sp->texx, h->sp->texy, h->sp->perpwalldist));
			y++;
		}
	}
}

void		print_wall2(t_hook *h, int x)
{
	int	y;
	int	temp;
	int	color;

	if (h->map[h->sp->mapy][h->sp->mapx] == '1')
	{
		y = h->sp->drawstart;
		while (y <= h->sp->drawend)
		{
			h->sp->texpos += h->sp->step;
			if (h->sp->side == 0)
			{
				h->sp->texy = (int)h->sp->texpos & (h->tex[0]->height - 1);
				color = ((h->tex)[0])->buff[(int)(h->tex[0]->height * h->sp->texy + h->sp->texx)];
				draw_dot(h, x, y + h->sp->appo, getcolor(h->tex[0],
					h->sp->texx, h->sp->texy, h->sp->perpwalldist));
			}
			else if (h->sp->side == 1)
			{
				h->sp->texy = (int)h->sp->texpos & (h->tex[1]->height - 1);
				color = ((h->tex)[1])->buff[(int)(h->tex[1]->height * h->sp->texy + h->sp->texx)];
				draw_dot(h, x, y + h->sp->appo, getcolor(h->tex[1],
					h->sp->texx, h->sp->texy, h->sp->perpwalldist));
			}
			else if (h->sp->side == 2)
			{
				h->sp->texy = (int)h->sp->texpos & (h->tex[2]->height - 1);
				color = ((h->tex)[2])->buff[(int)(h->tex[2]->height * h->sp->texy + h->sp->texx)];
				draw_dot(h, x, y + h->sp->appo, getcolor(h->tex[2],
					h->sp->texx, h->sp->texy, h->sp->perpwalldist));
			}
			else if (h->sp->side == 3)
			{
				h->sp->texy = (int)h->sp->texpos & (h->tex[3]->height - 1);
				color = ((h->tex)[3])->buff[(int)(h->tex[3]->height * h->sp->texy + h->sp->texx)];
				draw_dot(h, x, y + h->sp->appo, getcolor(h->tex[3],
					h->sp->texx, h->sp->texy, h->sp->perpwalldist));
			}
			y++;
		}
	}
}

void		print_wall(t_hook *h, int x)
{
	int y;
	int temp;

	if (h->map[h->sp->mapy][h->sp->mapx] == '2')
	{
		y = h->sp->drawstart;
		while (y <= h->sp->drawend)
		{	
			my_mlx_pixel_put(&h->img, x, y, create_trgb(0, 153, 255, 235));
			y++;
		}
	}
}

int			raycasting(t_hook *h)
{
	int x;
	int sw;
	int ds;
	int de;

	x = 0;
	ds = 0;
	de = 0;
	sw = 0;
	h->img.img = mlx_new_image(h->vars.mlx, h->var.rx, h->var.ry);
	h->img.addr = mlx_get_data_addr(h->img.img, &h->img.bits_per_pixel,
									&h->img.line_length, &h->img.endian);
	print_background(h->var, h->img);
	while (x < h->var.rx)
	{
		ray_calc(h->sp, h->var, x);
		var_dda(h->sp);
		dda(h->sp, h->map);
		pwd_calc(h->sp);
		height_calc(h->sp, h->var);
		tex_coord(h->sp, h->var);
		print_wall2(h, x);
		var_dda(h->sp);
		dda_sprite(h->sp, h->map);
		pwd_calc(h->sp);
		if (sw == 0)
		{
			height_calc(h->sp, h->var);
			ds = h->sp->drawstart;
			de = h->sp->drawend;
		}
		tex_coord(h->sp, h->var);
		if (h->sp->hit_sprite == 1 && sw == 0)
			sw = 1;
		if (h->sp->hit_sprite == 1)
		{
			h->sp->drawstart = ds;
			h->sp->drawend = de;
			print_sprite(h, x);
		}
		else
			sw = 0;
		ray_calc(h->sp, h->var, x);
		if (!h->sp->sprint)
			set_speed(h->sp);
		x++;
	}
	mlx_put_image_to_window(h->vars.mlx, h->vars.win, h->img.img, 0, 0);
	if (!(mlx_destroy_image(h->vars.mlx, h->img.img)))
		return (0);
	return (0);
}
