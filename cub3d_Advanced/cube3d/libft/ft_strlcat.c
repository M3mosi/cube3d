/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:57:40 by forsili           #+#    #+#             */
/*   Updated: 2021/01/13 11:57:44 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	char			*p_dest;
	size_t			n;
	size_t			dlen;
	size_t			i;

	p_dest = dest;
	i = 0;
	n = size;
	while (n-- != 0 && *p_dest != '\0')
		p_dest++;
	dlen = p_dest - dest;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src + i));
	while (*(src + i))
	{
		if (n != 1)
		{
			*p_dest++ = *(src + i);
			n--;
		}
		i++;
	}
	*p_dest = '\0';
	return (dlen + i);
}
