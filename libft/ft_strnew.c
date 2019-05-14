/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 02:21:42 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/07 02:31:18 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_string;

	if (!(new_string = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(new_string, size + 1);
	return (new_string);
}
