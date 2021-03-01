/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:03:07 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:03:07 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	miss_rule_err(char *reg)
{
	printf("Error\nMissing rules\n");
	free(reg);
	exit(0);
}

void	exist_rule_err(char *line, char *reg)
{
	printf("Error\nRule already exists\n");
	free(line);
	free(reg);
	exit(0);
}

void	forb_rule_err(char *line, char *reg)
{
	printf("Error\nRule forbidden\n");
	free(line);
	free(reg);
	exit(0);
}

void	invalid_map_err(char **map)
{
	int i;

	i = 0;
	printf("Error\nInvalid Map\n");
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	exit(0);
}

void	floceal_err(char *reg)
{
	printf("Error\nYou can't manage floor and ceiling in different mode\n");
	free(reg);
	exit(0);
}
