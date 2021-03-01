/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:00:47 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:00:48 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_hook *h)
{
	int i;

	i = 0;
	free(h->sp->zbuff);
	free(h->sprite);
	while (i < 10)
		free(h->tex[i++]);
	i = 0;
	while (h->map[i])
		free(h->map[i++]);
	i = 0;
	while (h->minimap[i])
		free(h->minimap[i++]);
}

void	free_sc(t_hook *h)
{
	int i;

	i = 0;
	free(h->sp->zbuff);
	free(h->sprite);
	while (i < 10)
		free(h->tex[i++]);
	i = 0;
	while (h->map[i])
		free(h->map[i++]);
	i = 0;
	while (h->minimap[i])
		free(h->minimap[i++]);
}

void	free_tex(t_hook *h)
{
	int i;

	i = 0;
	free(h->sprite);
	while (i < 10)
		free(h->tex[i++]);
}
