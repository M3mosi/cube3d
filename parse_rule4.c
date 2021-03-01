/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rule4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:02:59 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:03:00 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		insert_rgb_c(char *temp, t_var *var)
{
	char	**values;

	values = ft_split(temp, ',');
	var->c[0] = ft_atoi(values[0]);
	var->c[1] = ft_atoi(values[1]);
	var->c[2] = ft_atoi(values[2]);
	free(temp);
	free(values[0]);
	free(values[1]);
	free(values[2]);
	free(values);
	if (var->c[0] > 255 || var->c[1] > 255 || var->c[2] > 255)
	{
		printf("Error\nNot RGB value\n");
		exit(0);
	}
}

int			is_comma(char c, int i, char *line, char *reg)
{
	if (c != ',')
		format_rule_err(line, reg);
	return (i + 1);
}

void		parse_rgb_c(char *line, char *reg, t_var *var)
{
	int		i;
	char	*temp;

	i = is_space(line, 2);
	if (!ft_isdigit(line[i]))
		format_rule_err(line, reg);
	temp = ft_strtrim(&line[i], " \t");
	i = is_digit_space(line, i);
	i = is_comma(line[i], i, line, reg);
	i = is_space(line, i);
	if (!ft_isdigit(line[i]))
		format_rule_err(line, reg);
	i = is_digit_space(line, i);
	i = is_comma(line[i], i, line, reg);
	i = is_space(line, i);
	if (!ft_isdigit(line[i]))
		format_rule_err(line, reg);
	i = is_digit_space(line, i);
	if (line[i] != '\0')
		format_rule_err(line, reg);
	insert_rgb_c(temp, var);
	if (reg[7] == '0')
		reg[7] = '1';
	else
		exist_rule_err(line, reg);
}

void		insert_rgb_f(char *temp, t_var *var)
{
	char	**values;

	values = ft_split(temp, ',');
	var->f[0] = ft_atoi(values[0]);
	var->f[1] = ft_atoi(values[1]);
	var->f[2] = ft_atoi(values[2]);
	free(temp);
	free(values[0]);
	free(values[1]);
	free(values[2]);
	free(values);
	if (var->f[0] > 255 || var->f[1] > 255 || var->f[2] > 255)
	{
		printf("Error\nNot RGB value\n");
		exit(0);
	}
}
