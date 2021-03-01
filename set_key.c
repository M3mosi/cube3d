/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:05:25 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:05:27 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_lr(t_spawn *sp, double olddirx, double oldplanex)
{
	if (sp->lr == 1)
	{
		olddirx = sp->dirx;
		sp->dirx = sp->dirx * cos(-sp->rotspeed) - sp->diry
								* sin(-sp->rotspeed);
		sp->diry = olddirx * sin(-sp->rotspeed) + sp->diry * cos(-sp->rotspeed);
		oldplanex = sp->planex;
		sp->planex = sp->planex * cos(-sp->rotspeed) - sp->planey
					* sin(-sp->rotspeed);
		sp->planey = oldplanex * sin(-sp->rotspeed) + sp->planey
					* cos(-sp->rotspeed);
	}
	if (sp->lr == -1)
	{
		olddirx = sp->dirx;
		sp->dirx = sp->dirx * cos(sp->rotspeed) - sp->diry
					* sin(sp->rotspeed);
		sp->diry = olddirx * sin(sp->rotspeed) + sp->diry * cos(sp->rotspeed);
		oldplanex = sp->planex;
		sp->planex = sp->planex * cos(sp->rotspeed) - sp->planey
					* sin(sp->rotspeed);
		sp->planey = oldplanex * sin(sp->rotspeed) + sp->planey
					* cos(sp->rotspeed);
	}
}

void		set_fb(t_hook *h)
{
	if (h->sp->fb == 1)
	{
		if (check_mov(h->map[(int)(h->sp->posy + h->sp->diry *
						h->sp->movspeed)][(int)(h->sp->posx)]))
			h->sp->posy += h->sp->diry * h->sp->movspeed;
		if (check_mov(h->map[(int)(h->sp->posy)][(int)(h->sp->posx +
						h->sp->dirx * h->sp->movspeed)]))
			h->sp->posx += h->sp->dirx * h->sp->movspeed;
	}
	if (h->sp->fb == -1)
	{
		if (check_mov(h->map[(int)(h->sp->posy - h->sp->diry *
						h->sp->movspeed)][(int)(h->sp->posx)]))
			h->sp->posy -= h->sp->diry * h->sp->movspeed;
		if (check_mov(h->map[(int)(h->sp->posy)][(int)(h->sp->posx
								- h->sp->dirx * h->sp->movspeed)]))
			h->sp->posx -= h->sp->dirx * h->sp->movspeed;
	}
}

void		set_sm(t_hook *h)
{
	if (h->sp->sm == 1)
	{
		if (check_mov(h->map[(int)(h->sp->posy)][(int)(h->sp->posx
								- h->sp->diry * h->sp->movspeed)]))
			h->sp->posx -= h->sp->diry * h->sp->movspeed;
		if (check_mov(h->map[(int)(h->sp->posy + h->sp->dirx *
						h->sp->movspeed)][(int)(h->sp->posx)]))
			h->sp->posy += h->sp->dirx * h->sp->movspeed;
	}
	if (h->sp->sm == -1)
	{
		if (check_mov(h->map[(int)(h->sp->posy)][(int)(h->sp->posx
								+ h->sp->diry * h->sp->movspeed)]))
			h->sp->posx += h->sp->diry * h->sp->movspeed;
		if (check_mov(h->map[(int)(h->sp->posy - h->sp->dirx *
						h->sp->movspeed)][(int)(h->sp->posx)]))
			h->sp->posy -= h->sp->dirx * h->sp->movspeed;
	}
}

void		set_jump(t_spawn *sp)
{
	if (sp->jump == 1)
	{
		if (!sp->appo)
			sp->appo = 1;
		if ((sp->appo * 2) < 200 && sp->swjp == 0)
			sp->appo += 30;
		else if ((sp->appo * 2) > 200 && sp->swjp == 0)
			sp->swjp = 1;
		if ((sp->appo / 2) <= 0 && sp->swjp == 1)
		{
			sp->jump = 0;
			sp->swjp = 0;
			sp->appo = 1;
		}
		else if ((sp->appo / 2) > 0 && sp->swjp == 1)
			sp->appo = sp->appo - 30;
	}
	if (sp->jump == -1)
		sp->appo = -30;
}

int			set_key_render(t_hook *h)
{
	double olddirx;
	double oldplanex;

	olddirx = 0.0;
	oldplanex = 0.0;
	set_lr(h->sp, olddirx, oldplanex);
	set_fb(h);
	set_sm(h);
	set_jump(h->sp);
	if (h->sp->sprint == 1)
		h->sp->movspeed = 0.13;
	raycasting(h);
	return (0);
}
