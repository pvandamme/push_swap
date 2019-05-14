/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 01:07:33 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/29 15:23:23 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **list_a, t_list **list_b, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*list_a) || !(*list_a)->next)
		return ;
	tmp = *list_a;
	cp = *list_a;
	while (tmp->next)
	{
		if (tmp->next->next)
			cp = cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *list_a;
	*list_a = tmp;
	if (p == 1)
		write(1, "rra\n", 4);
	if (p == 2)
	{
		ft_putstr("\x1b[36mExecute rra:\n\n");
		visualizer(*list_a, *list_b);
	}
}

void	rrb(t_list **list_a, t_list **list_b, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*list_b) || !(*list_b)->next)
		return ;
	tmp = *list_b;
	cp = *list_b;
	if (!(*list_b))
		return ;
	while (tmp->next)
	{
		if (tmp->next->next)
			cp = cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *list_b;
	*list_b = tmp;
	if (p == 1)
		write(1, "rrb\n", 4);
	if (p == 2)
	{
		ft_putstr("\x1b[36mExecute rrb:\n\n");
		visualizer(*list_a, *list_b);
	}
}

void	rrr(t_list **list_a, t_list **list_b, int p)
{
	rra(list_a, list_b, 0);
	rrb(list_a, list_b, 0);
	if (p == 1)
		write(1, "rrr\n", 4);
	if (p == 2)
	{
		ft_putstr("\x1b[36mExecute rrr:\n\n");
		visualizer(*list_a, *list_b);
	}
}
