/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:45:53 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/06 17:54:02 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needdle, size_t len)
{
	size_t	i;
	int		j;
	char	*pt;

	i = 0;
	pt = 0;
	if (!(*needdle))
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needdle[0])
		{
			pt = (char *)haystack + i;
			j = 0;
			while (haystack[i + j] == needdle[j] && i + j < len)
			{
				if (needdle[j + 1] == '\0')
					return (pt);
				j++;
			}
			pt = 0;
		}
		i++;
	}
	return (NULL);
}
