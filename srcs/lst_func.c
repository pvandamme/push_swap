/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 07:18:36 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/29 15:07:15 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_link(t_list **list, int n)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *list;
	new = malloc(sizeof(t_list));
	if (new)
	{
		new->content = n;
		new->next = NULL;
		if (*list)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
		{
			*list = new;
			return ;
		}
	}
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		if (tmp)
		free(tmp);
	}
	list = NULL;
}

int		free_all(t_list *list, t_info *info)
{
	free_list(list);
	free(info);
	write(2, "Error\n", 6);
	return (0);
}
