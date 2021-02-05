/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:19:05 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/31 18:36:21 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exist_file_err(void)
{
	perror("Error\nMap missing");
	exit(0);
}

void	name_file_err(char *str)
{
	char	*temp;

	temp = 0;
	temp = str;
	if (!(temp = ft_strnstr(temp, ".cub", ft_strlen(temp))))
	{
		perror("Error\nWrong file extension");
		exit(0);
	}
	else if (ft_strlen(temp) > 4)
	{
		perror("Error\nWrong file extension");
		exit(0);
	}
}
