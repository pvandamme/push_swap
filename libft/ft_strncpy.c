/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:46:48 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/07 21:51:39 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *tdst;

	tdst = dst;
	while (len--)
	{
		if (*src)
			*tdst++ = *src++;
		else
			*tdst++ = '\0';
	}
	return (dst);
}
