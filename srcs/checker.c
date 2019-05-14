/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 04:17:26 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/31 11:13:16 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	split(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(line, "ra")))
		ra(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "rb")))
		rb(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "rr")))
		rr(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "sa")))
		sa(*list_a, *list_b, 0);
	else if (!(ft_strcmp(line, "sb")))
		sb(*list_b, *list_b, 0);
	else if (!(ft_strcmp(line, "ss")))
		ss(*list_a, *list_b, 0);
	else if (!(ft_strcmp(line, "rra")))
		rra(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "rrb")))
		rrb(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "rrr")))
		rrr(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "pa")))
		pa(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "pb")))
		pb(list_a, list_b, 0);
	else
		return (0);
	return (1);
}

int			checker(t_list **list_a, t_list **list_b)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ret == -1)
		{
			free(line);
			return (0);
		}
		if (!(split(line, list_a, list_b)))
		{
			free(line);
			return (0);
		}
		free(line);
	/*	ft_putstr("list_a : \n");
		print_list(*list_a);
		ft_putstr("list_b : \n");
		print_list(*list_b);*/
	}
	return (1);
}

int			main(int ac, char **av)
{
	int		ret;
	t_info	*info;
	t_list	*list_a;
	t_list	*list_b;

	if (ac < 2 || (ac < 3 && !ft_strcmp(av[1], "-v")))
		return (0);
	if (!(info = malloc(sizeof(t_info))))
		return (0);
	if (!(list_a = create_list(ac, av, &info)))
		return (free_all(list_a, info));
	if ((ret = checker(&list_a, &list_b)) == 0)
		return (free_all(list_a, info));
	if (list_a && is_sort(list_a) && !list_b)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	if (list_b)
		free_list(list_b);
	free_list(list_a);
	free(info);
	return (0);
}
