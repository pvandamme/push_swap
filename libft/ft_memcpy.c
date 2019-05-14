/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 23:52:48 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/06 23:40:34 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *tdst;
	char *tsrc;

	tdst = (char *)dst;
	tsrc = (char *)src;
	while (n--)
		*tdst++ = *tsrc++;
	return (dst);
}
