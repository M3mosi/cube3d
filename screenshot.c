/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:05:19 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:05:19 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		print_ver(t_data img, t_var var, int fd)
{
	int		y;
	int		x;
	int		save;

	y = var.ry - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < var.rx)
		{
			save = (*(int *)(img.addr + (y * img.line_length + (x * 4))));
			write(fd, &save, 4);
			x++;
		}
		y--;
	}
}

void		set_info(t_data img, int fd, t_var var)
{
	int info_size;
	int plane_num;
	int img_size;
	int color;

	info_size = 40;
	plane_num = 1;
	color = 0;
	img_size = var.rx * (var.ry - 1) * 4;
	write(fd, &info_size, 4);
	write(fd, &var.rx, 4);
	write(fd, &var.ry, 4);
	write(fd, &plane_num, 2);
	write(fd, &img.bits_per_pixel, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &img_size, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
}

void		screenshot(t_data img, t_var var, t_hook *h)
{
	int fd;
	int file_size;
	int first_pix;

	fd = open("cub3d.bmp", O_CREAT | O_RDWR, 0700);
	file_size = 54 + (var.rx * var.ry) * 4;
	first_pix = 54;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	set_info(img, fd, var);
	print_ver(img, var, fd);
	close(fd);
	free_sc(h);
	exit(0);
}
