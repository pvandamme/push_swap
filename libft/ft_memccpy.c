/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 00:35:30 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/06 13:55:12 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	while (n--)
	{
		*(char *)dst++ = *(char *)src;
		if (*(unsigned char *)src++ == (unsigned char)c)
			return (dst);
	}
	return (NULL);
}
