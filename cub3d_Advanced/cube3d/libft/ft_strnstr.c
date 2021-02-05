/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:44:17 by forsili           #+#    #+#             */
/*   Updated: 2021/01/13 13:44:19 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check(const char *haystack, const char *needle, size_t i, size_t len)
{
	size_t	k;
	size_t	j;
	size_t	count;

	k = 0;
	j = i;
	count = 0;
	while (needle[k] && j < len)
	{
		if (haystack[i + k] == needle[k])
			count++;
		j++;
		k++;
	}
	if (count == k && k == ft_strlen(needle))
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t				i;
	char				*out;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (i < len)
	{
		if (haystack[i] == needle[0])
		{
			if (check(haystack, needle, i, len))
			{
				out = &((char *)haystack)[i];
				return (out);
			}
		}
		i++;
	}
	return (0);
}
