/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 02:55:54 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/31 11:12:53 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_arg(char *s, int i)
{
	int	len;

	while (s[i])
	{
		len = 0;
		if (((!ft_isdigit(s[i]) && (s[i] != '-' && s[i] != '+')) ||
				(s[i] == '-' && (!ft_isdigit(s[i + 1]))) || ((s[i] == '-'
				|| s[i] == '+') && (s[i + 1] == '+' || s[i + 1] == '-'))))
			return (0);
		while (ft_isdigit(s[i]))
		{
			len++;
			if (len == 10 && ((s[i] > '7' || ft_isdigit(s[i + 1])) &&
						s[i - len] != '-'))
				return (0);
			if (len == 10 && ((s[i] > '8' || ft_isdigit(s[i + 1])) &&
						s[i - len] == '-'))
				return (0);
			i++;
		}
		if (((s[i] == ' ' || ((s[i] == '-') && ft_isdigit(s[i + 1])) ||
						((s[i] == '+') && ft_isdigit(s[i + 1]))) && s[i + 1]))
			i++;
	}
	return (1);
}

static int		check_dup(t_list *list)
{
	int		n;
	t_list	*tmp;

	n = list->content;
	tmp = list;
	while (list->next)
	{
		list = list->next;
		if (list->content == n)
			return (0);
	}
	if (tmp->next)
		if (!(check_dup(tmp->next)))
			return (0);
	return (1);
}

static t_list	*fill_list(t_info *info, t_list *list, int ac, char **av)
{
	int	i;
	int	j;

	if (info->vis == 2)
		i = 2;
	else
		i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			add_link(&list, ft_atoi(&av[i][j]));
			while (ft_isdigit(av[i][j]) || av[i][j] == '-' ||
					av[i][j] == '+' ||
					(av[i][j - 1] == '-' && av[i][j] == 'v'))
				j++;
			if (av[i][j] == ' ')
				j++;
		}
		i++;
	}
	return (list);
}

t_list			*create_list(int ac, char **av, t_info **info)
{
	t_list	*list;
	int		i;

	i = 1;
	list = NULL;
	if (av[i][0] == '-' && av[i][1] == 'v')
	{
		(*info)->vis = 2;
		i++;
	}
	while (i < ac)
	{
		if (!(check_arg(av[i], 0)) || !av[1][0])
			return (0);
		i++;
	}
	list = fill_list(*info, list, ac, av);
	if (!(check_dup(list)))
	{
		free_list(list);
		return (NULL);
	}
	return (list);
}
