/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:26:36 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/31 11:21:26 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_algo(t_list **list_a, t_info *info)
{
	if (find_size(*list_a) > 8)
	{
		if (!(resolve(list_a, info)))
			return (0);
	}
	else
		short_resolve(list_a, info);
	if (info->vis == 2)
	{
		ft_printf("\x1b[36mSort stack : \n\n");
		visualizer(*list_a, 0);
		ft_printf("\x1b[36mEnd of visualization\n");
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_list	*list_a;
	t_info	*info;

	if (ac < 2 || (ac < 3 && !ft_strcmp(av[1], "-v")))
		return (0);
	if (!(info = malloc(sizeof(t_info))))
		return (0);
	info->vis = 1;
	if (!(list_a = create_list(ac, av, &info)))
	{
		free(info);
		return (write(2, "Error\n", 6));
	}
	if (info->vis == 2)
	{
		ft_printf("\x1b[36m\nStart Visualization...\n\nStart Stack : \n\n");
		visualizer(list_a, 0);
	}
	find_algo(&list_a, info);
	free_list(list_a);
	free(info);
	return (0);
}
