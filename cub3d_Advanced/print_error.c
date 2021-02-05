/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:00:24 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/31 19:31:43 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	format_rule_err(char *line, char *reg)
{
	perror("Error\nWrong rules format");
	free(line);
	free(reg);
	exit(0);
}

void	miss_rule_err(char *reg)
{
	perror("Error\nMissing rules");
	free(reg);
	exit(0);
}

void	exist_rule_err(char *line, char *reg)
{
	perror("Error\nRule already exists");
	free(line);
	free(reg);
	exit(0);
}

void	forb_rule_err(char *line, char *reg)
{
	perror("Error\nRule forbidden");
	free(line);
	free(reg);
	exit(0);
}

void	invalid_map_err(char **map)
{
	perror("Error\nInvalid Map");
	free(map);
	exit(0);
}
