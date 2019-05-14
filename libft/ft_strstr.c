/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:40:04 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/06 17:48:53 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needdle)
{
	int		i;
	int		j;
	char	*pt;

	i = 0;
	pt = NULL;
	if (!(*needdle))
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needdle[0])
		{
			pt = (char *)haystack + i;
			j = 0;
			while (haystack[i + j] == needdle[j])
			{
				if (needdle[j + 1] == '\0')
					return (pt);
				j++;
			}
			pt = 0;
		}
		i++;
	}
	return (0);
}
