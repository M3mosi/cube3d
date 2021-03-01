/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_move3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:06:20 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:06:20 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_move1(double *movex, double *movey)
{
	*movex *= 1;
	*movey *= 1;
}

void		set_move2(double *movex, double *movey)
{
	*movex *= 1;
	*movey *= -1;
}

void		set_move3(double *movex, double *movey)
{
	*movex *= -1;
	*movey *= 1;
}

void		set_move4(double *movex, double *movey)
{
	*movex *= -1;
	*movey *= -1;
}
