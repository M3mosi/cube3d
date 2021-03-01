/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:02:13 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:02:14 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ar_length(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char			**minimap_init(char **minimap, char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (!(minimap[i] = (char *)malloc((((int)ft_strlen(map[i]) + 1)
													* sizeof(char)))))
			exit(0);
		i++;
	}
	minimap[i] = 0;
	return (minimap);
}

void			tex_control(t_hook *h, int swc, int swf)
{
	if ((swc && swf))
	{
		if (!(h->tex[5]) || !(h->tex[6]))
		{
			printf("Error\nTexture doesn't exist\n");
			free_tex(h);
			exit(0);
		}
	}
	if (!(h->tex[0]) || !(h->tex[1]) || !(h->tex[2]) ||
		!(h->tex[3]) || !(h->tex[4]) || !(h->tex[7]) ||
		!(h->tex[8]) || !(h->tex[9]) || !(h->tex[10]))
	{
		printf("Error\nTexture doesn't exist\n");
		free_tex(h);
		exit(0);
	}
}

void			set_text(t_hook *h, t_var var, t_vars vars)
{
	int			width;
	int			height;

	h->tex[0] = mlx_xpm_file_to_image(vars.mlx, var.ea, &width, &height);
	h->tex[1] = mlx_xpm_file_to_image(vars.mlx, var.so, &width, &height);
	h->tex[2] = mlx_xpm_file_to_image(vars.mlx, var.no, &width, &height);
	h->tex[3] = mlx_xpm_file_to_image(vars.mlx, var.we, &width, &height);
	h->tex[4] = mlx_xpm_file_to_image(vars.mlx, var.s, &width, &height);
	if (var.swf && var.swc)
	{
		h->tex[5] = mlx_xpm_file_to_image(vars.mlx, var.fpat,
														&width, &height);
		h->tex[6] = mlx_xpm_file_to_image(vars.mlx, var.cpat,
														&width, &height);
	}
	h->tex[7] = mlx_xpm_file_to_image(vars.mlx, "./texture/gunn_shoot.xpm",
														&width, &height);
	h->tex[8] = mlx_xpm_file_to_image(vars.mlx, "./texture/gunn.xpm",
														&width, &height);
	h->tex[9] = mlx_xpm_file_to_image(vars.mlx, "./texture/zombic.xpm",
														&width, &height);
	h->tex[10] = mlx_xpm_file_to_image(vars.mlx, "./texture/gameover.xpm",
														&width, &height);
	tex_control(h, var.swc, var.swf);
}
