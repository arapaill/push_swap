/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 09:55:39 by marvin            #+#    #+#             */
/*   Updated: 2021/04/20 09:55:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


long int    find_max_skip(t_list *list, int skip)
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
				do_sb(*li_b);
				do_pa(li_a, li_b);
				f = 1;
				break ;
			}
			if (info->flags == 1)
				do_rb(li_b);
			else
				do_rrb(li_b);
		}
	}
	if (!f)
		do_pa(li_a, li_b);
}

int	find_pos(int n, t_list *list)
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

static void		push_a(t_list **li_a, t_list **li_b, t_info *info, t_data *data)
{
	while (info->size_b)
	{
		data->flags_a = 0;
		data->flags_b = 0;
		data->max_b = find_max_skip(*li_b, -2147483648);
		data->max_a = find_max_skip(*li_b, data->max_b);
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
			do_sa(*li_a);
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
		if ((*li_a)->content <= (*info)->median)
		{
			do_pb(li_a, li_b);
			if ((*li_b)->content < find_median(*li_b, (*info)->size_b) &&
					(*info)->size_b > 1)
			{
				if ((*li_a)->content > (*info)->median)
					do_rr(li_a, li_b);
				else
					do_rb(li_b);
			}
			(*info)->size_b++;
			(*info)->size_a--;
		}
		else
			do_ra(li_a);
		tmp--;
	}
}

int				resolve(t_list **list_a, t_info *info)
{
	int		tmp;
	t_list	*list_b;
	t_data 	*data;

	list_b = 0;
	printf("TEST\n");
	if (!(data = malloc(sizeof(t_data))))
		return (0);
	while (info->size_a > 2)
	{
		info->median = find_median(*list_a, info->size_a);
		tmp = info->size_a;
		opti_rotation(tmp, list_a, &list_b, &info);
	}
	do_pb(list_a, &list_b);
	do_pb(list_a, &list_b);
	info->size_b += 2;
	push_a(list_a, &list_b, info, data);
	return (1);
}

void    push_swap(t_list **list_a, t_info *info)
{
	if (ft_istri(*list_a))
		return ;
	info->size_a = ft_lstsize(*list_a);
    info->size_b = 0;
    print_list(*list_a);
    if(info->size_a <= 5)
        hardcoding(info->size_a, list_a);
    else
        resolve(list_a, info);
	print_list(*list_a);
}