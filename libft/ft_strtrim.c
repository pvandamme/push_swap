/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:13:33 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/07 23:26:36 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;

	start = 0;
	if (!s)
		return (NULL);
	end = (int)ft_strlen(s);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while ((s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
			&& end > start)
		end--;
	return (ft_strsub(s, start, (end - start)));
}
