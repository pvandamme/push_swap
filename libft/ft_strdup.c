/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:40:40 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/06 14:56:35 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if (!(s2 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
