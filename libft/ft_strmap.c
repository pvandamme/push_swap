/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 02:55:56 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/07 21:51:57 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*new_string;
	size_t		len;
	int			i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(new_string = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	new_string[len] = '\0';
	i = -1;
	while (s[++i])
		new_string[i] = (*f)(s[i]);
	return (new_string);
}
