/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:57:52 by forsili           #+#    #+#             */
/*   Updated: 2021/01/13 12:57:55 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned long long	i;
	char				*out;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			out = &((char *)s)[i];
			return (out);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		out = &((char *)s)[i];
		return (out);
	}
	return (0);
}
