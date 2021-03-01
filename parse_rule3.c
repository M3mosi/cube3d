/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rule3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:02:49 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:02:50 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		insert_value(char *temp, t_var *var)
{
	char	**values;

	values = ft_split(temp, ' ');
	var->rx = ft_atoi(values[0]);
	var->ry = ft_atoi(values[1]);
	free(temp);
	free(values[0]);
	free(values[1]);
	free(values);
	if (var->ry > 1395)
		var->ry = 1395;
	if (var->rx > 2560)
		var->rx = 2560;
}

void		parse_value(char *line, char *reg, t_var *var)
{
	int		i;
	char	*temp;

	i = 2;
	while (ft_isspace(line[i]))
		i++;
	if (!ft_isdigit(line[i]))
		format_rule_err(line, reg);
	temp = ft_strtrim(&line[i], " \t");
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	if (!ft_isdigit(line[i]))
		format_rule_err(line, reg);
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] != '\0')
		format_rule_err(line, reg);
	insert_value(temp, var);
	(reg[0] == '0') ? reg[0] = '1' : exist_rule_err(line, reg);
}

int			is_digit_space(char *line, int i)
{
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

int			is_space(char *line, int i)
{
	while (ft_isspace(line[i]))
		i++;
	return (i);
}
