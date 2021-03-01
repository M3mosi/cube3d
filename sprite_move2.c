/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:06:12 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:06:13 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_move5(double *movex, double *movey)
{
	*movex *= 1;
	*movey *= 0;
}

void		set_move6(double *movex, double *movey)
{
	*movex *= -1;
	*movey *= 0;
}

void		set_move7(double *movex, double *movey)
{
	*movex *= 0;
	*movey *= -1;
}

void		set_move8(double *movex, double *movey)
{
	*movex *= 0;
	*movey *= 1;
}

void		random_gen(double *movex, double *movey)
{
	int n;

	n = rand() % 80;
	if (n <= (80 / 8))
		set_move1(movex, movey);
	else if (n > 10 && n <= 20)
		set_move2(movex, movey);
	else if (n > 20 && n <= 30)
		set_move3(movex, movey);
	else if (n > 30 && n <= 40)
		set_move4(movex, movey);
	else if (n > 40 && n <= 50)
		set_move5(movex, movey);
	else if (n > 50 && n <= 60)
		set_move6(movex, movey);
	else if (n > 60 && n <= 70)
		set_move7(movex, movey);
	else if (n > 70 && n <= (80))
		set_move8(movex, movey);
}
