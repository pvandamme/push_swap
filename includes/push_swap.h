/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 02:52:59 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/29 15:14:59 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct		s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef	struct		s_info
{
	int				pivot;
	int				size_b;
	int				size_a;
	int				flags;
	int				vis;
}					t_info;

typedef	struct		s_data
{
	int				max_a;
	int				max_b;
	int				flags_a;
	int				flags_b;
	int				pos_a;
	int				pos_b;
}					t_data;

int					resolve(t_list **list_a, t_info *info);
int					free_all(t_list *list, t_info *info);
void				visualizer(t_list *list_a, t_list *list_b);
void				short_resolve(t_list **list_a, t_info *info);
int					find_min(t_list *list);
int					find_max(t_list *list, int skip);
int					find_pos(int n, t_list *list);
int					find_size(t_list *list);
void				free_list(t_list *list);
void				sa(t_list *list_a, t_list *list_b, int p);
void				sb(t_list *list_a, t_list *list_b, int p);
void				ss(t_list *list_a, t_list *list_b, int p);
void				pa(t_list **list_a, t_list **list_b, int p);
void				pb(t_list **list_a, t_list **list_b, int p);
void				ra(t_list **list_a, t_list **list_b, int p);
void				rb(t_list **list_a, t_list **list_b, int p);
void				rr(t_list **list_a, t_list **list_b, int p);
void				rra(t_list **list_a, t_list **list_b, int p);
void				rrb(t_list **list_a, t_list **list_b, int p);
void				rrr(t_list **list_a, t_list **list_b, int p);
void				print_list(t_list *list);
int					get_pivot(t_list *list);
int					is_sort(t_list *list_a);
int					find_median(t_list *list_b, int size);
void				add_link(t_list **list, int n);
t_list				*create_list(int ac, char **av, t_info **info);

#endif
