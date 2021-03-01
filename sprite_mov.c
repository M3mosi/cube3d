/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:06:02 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:06:02 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	follow_player(t_hook *h, double *movex, double *movey, int i)
{
	if (h->sprite[i]->y < h->sp->posy)
		*movey *= -(h->sprite[i]->y - h->sp->posy);
	else
		*movey *= -(h->sprite[i]->y - h->sp->posy);
	if (h->sprite[i]->x < h->sp->posx)
		*movex *= -(h->sprite[i]->x - h->sp->posx);
	else
		*movex *= -(h->sprite[i]->x - h->sp->posx);
	if ((int)h->sprite[i]->y == (int)h->sp->posy)
		*movey *= 0;
	if ((int)h->sprite[i]->x == (int)h->sp->posx)
		*movex *= 0;
}

double	distance_punti(double x1, double x2, double y1, double y2)
{
	return (sqrt((pow(x2 - x1, 2)) + (pow(y2 - y1, 2))));
}

int		check_pos_wall(t_sprite *spr, t_hook *h, double movex, double movey)
{
	double sicx;
	double sicy;

	sicy = 0.5;
	sicx = 0.5;
	if (h->map[(int)(spr->y + movey)][(int)(spr->x + movex)] == '1')
		return (0);
	if (h->map[(int)(spr->y + movey + sicy)][(int)(spr->x + movex)] == '1')
		return (0);
	if (h->map[(int)(spr->y + movey)][(int)(spr->x + movex + sicx)] == '1')
		return (0);
	return (1);
}

int		can_move(t_sprite *spr, t_hook *h, double movex, double movey)
{
	if (!spr->k)
		return (0);
	if (distance_punti(spr->x + movex, h->sp->posx, spr->y +
						movey, h->sp->posy) < 1)
		h->sp->life -= 1;
	if (check_pos_wall(spr, h, movex, movey))
	{
		if ((int)(spr->y + movey) == (int)h->sp->posy &&
					(int)(spr->x + movex) == (int)h->sp->posx)
			return (0);
		return (1);
	}
	else
		return (0);
	return (0);
}

void	movement_sprite(t_hook *h)
{
	int i;

	i = 0;
	while (h->sprite[i])
	{
		if (distance_punti(h->sprite[i]->x, h->sp->posx,
					h->sprite[i]->y, h->sp->posy) < 13)
		{
			h->sprite[i]->movex = 0.03;
			h->sprite[i]->movey = 0.03;
			follow_player(h, &h->sprite[i]->movex, &h->sprite[i]->movey, i);
		}
		if (can_move(h->sprite[i], h, h->sprite[i]->movex, h->sprite[i]->movey))
		{
			h->map[(int)h->sprite[i]->y][(int)h->sprite[i]->x] = '0';
			h->sprite[i]->x += h->sprite[i]->movex;
			h->sprite[i]->y += h->sprite[i]->movey;
			h->map[(int)h->sprite[i]->y][(int)h->sprite[i]->x] = '2';
		}
		i++;
	}
}
