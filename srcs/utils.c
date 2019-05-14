/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 06:12:05 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/19 06:13:37 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sort(t_list *list_a)
{
	while (list_a->next)
	{
		if (list_a->content > list_a->next->content)
			return (0);
		list_a = list_a->next;
	}
	return (1);
}

int		find_size(t_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int		find_max(t_list *list, int skip)
{
	int	max;

	max = -2147483648;
	while (list->next)
	{
		if (list->content > max && list->content != skip)
			max = list->content;
		list = list->next;
	}
	if (list->content > max && list->content != skip)
		max = list->content;
	return (max);
}

int		find_min(t_list *list)
{
	int	min;

	min = 2147483647;
	while (list->next)
	{
		if (list->content < min)
			min = list->content;
		list = list->next;
	}
	if (list->content < min)
		min = list->content;
	return (min);
}

int		find_pos(int n, t_list *list)
{
	int	pos;

	pos = 0;
	while (list->content != n)
	{
		list = list->next;
		pos++;
	}
	return (pos);
}
