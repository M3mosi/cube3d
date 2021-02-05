/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:12:34 by forsili           #+#    #+#             */
/*   Updated: 2021/01/15 15:12:36 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lista;

	if (!lst || !(*lst) || !del)
		return ;
	while ((*lst) && lst)
	{
		lista = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lista;
	}
}
