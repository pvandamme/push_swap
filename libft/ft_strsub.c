/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 03:38:22 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/07 15:35:23 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(new_string = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	new_string[len] = '\0';
	while (len-- && s[start])
		new_string[i++] = s[start++];
	return (new_string);
}
