/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 00:13:05 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/19 01:04:34 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print(t_list *list, int max, int min)
{
	if (list && list->content == max)
		ft_printf("\x1b[31m%d", list->content);
	else if (list && list->content == min)
		ft_printf("\x1b[32m%d", list->content);
	else if (list)
		ft_printf("\x1b[33m%d", list->content);
}

void		init_max(t_list *list, int *max, int *min)
{
	*max = find_max(list, -2147483648);
	*min = find_min(list);
}

void		visualizer(t_list *list_a, t_list *list_b)
{
	int	i;
	int	max_a;
	int	min_a;
	int	max_b;
	int	min_b;

	i = 0;
	if (list_a)
		init_max(list_a, &max_a, &min_a);
	if (list_b)
		init_max(list_b, &max_b, &min_b);
	while (list_a || list_b)
	{
		ft_printf("\x1b[36mPosition %d -> ", i++);
		print(list_a, max_a, min_a);
		list_a && list_a->content / 10 ? ft_putstr("\t\t") :
			ft_putstr("\t\t\t");
		print(list_b, max_b, min_b);
		ft_putchar('\n');
		if (list_a)
			list_a = list_a->next;
		if (list_b)
			list_b = list_b->next;
	}
	ft_putstr("\n\n");
}
