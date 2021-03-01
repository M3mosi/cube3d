/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:03:12 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:03:13 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	format_rule_err(char *line, char *reg)
{
	printf("Error\nWrong rules format\n");
	free(line);
	free(reg);
	exit(0);
}

void	extension_err(char *line, char *reg)
{
	printf("Error\nNot valid texture extension\n");
	free(line);
	free(reg);
	exit(0);
}

void	file_err(void)
{
	printf("Error\nFile doesn't exist\n");
	exit(0);
}
