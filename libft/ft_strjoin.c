/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:56:30 by forsili           #+#    #+#             */
/*   Updated: 2021/01/14 12:56:32 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	char	*out;

	i = 0;
	k = 0;
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	if (!(out = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char))))
		return (0);
	while (s1[k])
	{
		out[i] = ((char *)s1)[k];
		k++;
		i++;
	}
	k = 0;
	while (s2[k])
	{
		out[i++] = ((char *)s2)[k++];
	}
	out[i] = 0;
	return (out);
}
