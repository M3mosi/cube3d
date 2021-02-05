/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:56:22 by forsili           #+#    #+#             */
/*   Updated: 2021/01/13 13:56:24 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	char	char1;
	char	char2;

	while (n-- > 0)
	{
		char1 = *s1++;
		char2 = *s2++;
		if (char1 != char2)
			return ((unsigned char)char1 - (unsigned char)char2);
		if (char1 == '\0')
			return (0);
	}
	return (0);
}
