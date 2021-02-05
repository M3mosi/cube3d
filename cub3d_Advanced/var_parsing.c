/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:36:33 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/31 12:50:44 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		reg_init(char *reg)
{
	int		i;
	char	*temp;

	i = 0;
	temp = reg;
	while (i < 9)
	{
		*temp = '0';
		temp++;
		i++;
	}
	*temp = 0;
}

int			check_rule(char *reg)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (reg[i] == '0')
			return (0);
		i++;
	}
	return (1);
}

void		parse_rule(char **line, char **reg, t_var *var)
{
	if ((*line)[0] == 'N' && (*line)[1] == 'O' && (*line)[2] == ' ')
		parse_template_no(*line, *reg, var);
	else if ((*line)[0] == 'S' && (*line)[1] == 'O' && (*line)[2] == ' ')
		parse_template_so(*line, *reg, var);
	else if ((*line)[0] == 'W' && (*line)[1] == 'E' && (*line)[2] == ' ')
		parse_template_we(*line, *reg, var);
	else if ((*line)[0] == 'E' && (*line)[1] == 'A' && (*line)[2] == ' ')
		parse_template_ea(*line, *reg, var);
	else if ((*line)[0] == 'R' && (*line)[1] == ' ')
		parse_value(*line, *reg, var);
	else if ((*line)[0] == 'S' && (*line)[1] == ' ')
		parse_template_s(*line, *reg, var);
	else if ((*line)[0] == 'F' && (*line)[1] == ' ')
		parse_rgb_f(*line, *reg, var);
	else if ((*line)[0] == 'C' && (*line)[1] == ' ')
		parse_rgb_c(*line, *reg, var);
	else if ((*line)[0] == 0)
	{
	}
	else
		forb_rule_err(*line, *reg);
}

void		var_parsing(int fd, t_var *var)
{
	char	*reg;
	char	*line;
	int		ret;

	ret = 1;
	reg = malloc(sizeof(char) * 9);
	reg_init(reg);
	while (!check_rule(reg) && ret > 0)
	{
		ret = get_next_line(fd, &line);
		parse_rule(&line, &reg, var);
		free(line);
	}
	if (!check_rule(reg))
		miss_rule_err(reg);
	free(reg);
}
