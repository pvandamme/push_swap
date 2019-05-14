/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 08:07:03 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/11 08:07:10 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_max(t_list **li_a, t_list **li_b, int m, t_info *info)
{
	int	f;

	f = 0;
	if ((*li_b)->content < m)
	{
		while ((*li_b)->content != m)
		{
			if ((*li_b)->next->content == m)
			{
				sb(*li_a, *li_b, info->vis);
				pa(li_a, li_b, info->vis);
				f = 1;
				break ;
			}
			if (info->flags == 1)
				rb(li_a, li_b, info->vis);
			else
				rrb(li_a, li_b, info->vis);
		}
	}
	if (!f)
		pa(li_a, li_b, info->vis);
}

static void		push_a(t_list **li_a, t_list **li_b, t_info *info, t_data *data)
{
	while (info->size_b)
	{
		data->flags_a = 0;
		data->flags_b = 0;
		data->max_b = find_max(*li_b, -2147483648);
		data->max_a = find_max(*li_b, data->max_b);
		if ((data->pos_a = find_pos(data->max_b, *li_b)) < info->size_b / 2)
			data->flags_a = 1;
		if (data->max_a != -2147483648 && (data->pos_b =
			find_pos(data->max_a, *li_b)) < info->size_b / 2)
			data->flags_b = 1;
		info->flags = data->flags_a;
		if (data->max_a != -2147483648 && data->flags_a == data->flags_b &&
				((data->pos_a > data->pos_b && data->flags_a) ||
				(data->pos_a < data->pos_b && !data->flags_a)))
		{
			push_max(li_a, li_b, data->max_a, info);
			push_max(li_a, li_b, data->max_b, info);
			sa(*li_a, *li_b, info->vis);
			info->size_b--;
		}
		else
			push_max(li_a, li_b, data->max_b, info);
		info->size_b--;
	}
}

static void		opti_rotation(int tmp, t_list **li_a, t_list **li_b,
				t_info **info)
{
	while (tmp && (*info)->size_a > 2)
	{
		if ((*li_a)->content <= (*info)->pivot)
		{
			pb(li_a, li_b, (*info)->vis);
			if ((*li_b)->content < find_median(*li_b, (*info)->size_b) &&
					(*info)->size_b > 1)
			{
				if ((*li_a)->content > (*info)->pivot)
					rr(li_a, li_b, (*info)->vis);
				else
					rb(li_a, li_b, (*info)->vis);
			}
			(*info)->size_b++;
			(*info)->size_a--;
		}
		else
			ra(li_a, li_b, (*info)->vis);
		tmp--;
	}
}

int				resolve(t_list **li_a, t_info *info)
{
	int		tmp;
	t_data	*data;
	t_list	*li_b;

	li_b = 0;
	if (!(data = malloc(sizeof(t_data))))
		return (0);
	if (is_sort(*li_a))
		return (1);
	info->size_a = find_size(*li_a);
	info->size_b = 0;
	while (info->size_a > 2)
	{
		info->pivot = find_median(*li_a, info->size_a);
		tmp = info->size_a;
		opti_rotation(tmp, li_a, &li_b, &info);
	}
	pb(li_a, &li_b, info->vis);
	pb(li_a, &li_b, info->vis);
	info->size_b += 2;
	push_a(li_a, &li_b, info, data);
	free(data);
	return (1);
}
