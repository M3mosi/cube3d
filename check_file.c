/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:59:32 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 11:59:35 by sgiovo           ###   ########.fr       */
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
