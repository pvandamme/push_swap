/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:54:17 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/06 18:15:08 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
		if (!*s1++ || !*s2++)
			return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
