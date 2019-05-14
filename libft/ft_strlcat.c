/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:38:24 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/07 02:03:37 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		t1;

	t1 = 0;
	i = 0;
	while (dst[t1] && t1 < dstsize)
		t1++;
	while (src[i] && t1 + i + 1 < dstsize)
	{
		dst[t1 + i] = src[i];
		i++;
	}
	if (t1 < dstsize)
		dst[t1 + i] = '\0';
	return (t1 + ft_strlen(src));
}
