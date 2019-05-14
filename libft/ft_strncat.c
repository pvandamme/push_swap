/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:02:59 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/06 16:37:48 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i])
		i++;
	while (*s2 && n--)
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}
