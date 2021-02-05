/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:23:52 by forsili           #+#    #+#             */
/*   Updated: 2021/01/14 12:23:55 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	char1;
	unsigned char	char2;
	size_t			i;

	i = 0;
	while (i < n)
	{
		char1 = ((unsigned char *)s1)[i];
		char2 = ((unsigned char *)s2)[i];
		if (char1 != char2)
			return ((int)char1 - (int)char2);
		i++;
	}
	return (0);
}
