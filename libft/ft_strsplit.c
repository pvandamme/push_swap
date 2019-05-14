/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:01:48 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/07 21:49:41 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_parts(const char *s, char c)
{
	int		count;
	int		in_substring;

	in_substring = 0;
	count = 0;
	while (*s)
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int		ft_wlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_word;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	nb_word = ft_count_parts(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_count_parts(s, c) + 1))))
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s)
			s++;
		if (!(tab[i] = ft_strsub(s, 0, ft_wlen(s, c))))
			return (NULL);
		s = s + ft_wlen(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
