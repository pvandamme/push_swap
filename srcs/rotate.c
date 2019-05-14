/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:44:02 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/29 15:22:21 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **list_a, t_list **list_b, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*list_a) || !((*list_a)->next))
		return ;
	tmp = *list_a;
	cp = (*list_a)->next;
	while ((*list_a)->next)
		*list_a = (*list_a)->next;
	(*list_a)->next = tmp;
	tmp->next = NULL;
	*list_a = cp;
	if (p == 1)
		write(1, "ra\n", 3);
	if (p == 2)
	{
		ft_putstr("\x1b[36mExecute ra:\n\n");
		visualizer(*list_a, *list_b);
	}
}

void	rb(t_list **list_a, t_list **list_b, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*list_b) || !(*list_b)->next)
		return ;
	tmp = *list_b;
	cp = (*list_b)->next;
	while ((*list_b)->next)
		*list_b = (*list_b)->next;
	(*list_b)->next = tmp;
	tmp->next = NULL;
	*list_b = cp;
	if (p == 1)
		write(1, "rb\n", 3);
	if (p == 2)
	{
		ft_putstr("\x1b[36mExecute rb:\n\n");
		visualizer(*list_a, *list_b);
	}
}

void	rr(t_list **list_a, t_list **list_b, int p)
{
	ra(list_a, list_b, 0);
	rb(list_b, list_b, 0);
	if (p == 1)
		write(1, "rr\n", 3);
	if (p == 2)
	{
		ft_putstr("\x1b[36mExecute rr:\n\n");
		visualizer(*list_a, *list_b);
	}
}
