/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:48:36 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/02 14:24:03 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_var		var_init(void)
{
	t_var var;

	var.rx = -1;
	var.ry = -1;
	var.no = NULL;
	var.so = NULL;
	var.we = NULL;
	var.ea = NULL;
	var.s = NULL;
	var.f[0] = -1;
	var.f[1] = -1;
	var.f[2] = -1;
	var.fpat = NULL;
	var.c[0] = -1;
	var.c[1] = -1;
	var.c[2] = -1;
	var.cpat = NULL;
	return (var);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_var	var;
	char	**map;

	if (argc < 2)
		exist_file_err();
	name_file_err(argv[1]);
	var = var_init();
	fd = open(argv[1], O_RDONLY);
	var_parsing(fd, &var);
	map = map_parsing(fd);
	rendering(map, var);
	close(fd);
	return (0);
}
