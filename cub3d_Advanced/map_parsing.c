/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:49:31 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/02 10:21:10 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		**ft_lstiter_mod(t_list *lst, char **map)
{
	t_list	*lstiter;
	int		i;

	i = 0;
	if (lst != NULL)
	{
		lstiter = lst;
		while (lstiter != NULL)
		{
			map[i] = lstiter->content;
			lstiter = lstiter->next;
			i++;
		}
		map[i] = 0;
	}
	return (map);
}

void		ft_lstadd_back_mod(t_list **alst, char *line)
{
	t_list *lastelem;

	if (*alst == NULL)
	{
		*alst = ft_lstnew(line);
	}
	else
	{
		lastelem = ft_lstlast(*alst);
		if (lastelem != NULL)
			lastelem->next = ft_lstnew(line);
	}
}

int			take_line(t_list **lst, int fd)
{
	int		i;
	char	*line;
	int		ret;
	int		flag;

	i = 1;
	ret = 1;
	flag = 0;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (line[0] == 0 && flag == 0)
			continue ;
		flag = 1;
		i++;
		ft_lstadd_back_mod(lst, line);
	}
	return (i);
}

void		ft_lstclear_mod(t_list **lst)
{
	t_list *tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

char		**map_parsing(int fd)
{
	t_list	*lst;
	char	**map;

	lst = 0;
	if (!(map = malloc(sizeof(char *) * (take_line(&lst, fd) + 1))))
		return (NULL);
	map = ft_lstiter_mod(lst, map);
	ft_lstclear_mod(&lst);
	check_map(map);
	return (map);
}
