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


int					find_max_skip(t_list *list, int skip)
{
	int	max;

	max = INT_MIN;
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


static void		push_max(t_list **list_a, t_list **list_b, t_info *info, int max)
{
	int	f;

	f = 0;
	if ((*list_b)->content < max)
	{
		while ((*list_b)->content != max)
		{
			if ((*list_b)->next->content == max)
			{
				do_sb(*list_b);
				do_pa(list_a, list_b);
				f = 1;
				break ;
			}
			if (info->flags == 1)
				do_rb(list_b);
			else
				do_rrb(list_b);
		}
	}
	if (!f)	
		do_pa(list_a, list_b);
}

int		find_pos(int n, t_list *list)
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


static void		push_a(t_list **list_a, t_list **list_b, t_info *info)
{
	while (info->size_b)
	{
		printf("TEST 1\n");
		print_all(*list_a, *list_b);
		info->flags_a = 0;
		info->flags_b = 0;
		info->max_b = find_max_skip(*list_b, INT_MIN);
		info->max_a = find_max_skip(*list_b, info->max_b);
		printf("TEST 2\n");
		print_all(*list_a, *list_b);
		if ((info->pos_a = find_pos(info->max_b, *list_b)) < info->size_b / 2)
			info->flags_a = 1;
		printf("TEST 3\n");
		print_all(*list_a, *list_b);
		if (info->max_a != INT_MIN && (info->pos_b =
			find_pos(info->max_a, *list_b)) < info->size_b / 2)
			info->flags_b = 1;
		printf("TEST 4\n");
		print_all(*list_a, *list_b);
		info->flags = info->flags_a;
		printf("TEST 5\n");
		print_all(*list_a, *list_b);
		if (info->max_a != INT_MIN && info->flags_a == info->flags_b &&
				((info->pos_a > info->pos_b && info->flags_a) ||
				(info->pos_a < info->pos_b && !info->flags_a)))
		{
			printf("TEST 6\n");
			print_all(*list_a, *list_b);
			push_max(list_a, list_b, info, info->max_a);
			printf("TEST 7\n");
			print_all(*list_a, *list_b);
			push_max(list_a, list_b, info, info->max_b);
			printf("TEST 8\n");
			print_all(*list_a, *list_b);
			do_sa(*list_a);
			printf("TEST 9\n");
			print_all(*list_a, *list_b);
			info->size_b--;
		}
		else
			push_max(list_a, list_b, info, info->max_b);
		info->size_b--;
	}
	printf("PUSH_A\n");
}

static void		opti_rotation(int tmp, t_list **list_a, t_list **list_b,
				t_info **info)
{
	while (tmp && (*info)->size_a > 2)
	{
		if ((*list_a)->content <= (*info)->median)
		{
			do_pb(list_a, list_b);
			if ((*list_b)->content < find_median(*list_b, (*info)->size_b) &&
					(*info)->size_b > 1)
			{
				if ((*list_a)->content > (*info)->median)
					do_rr(list_a, list_b);
				else
					do_rb(list_b);
			}
			(*info)->size_b++;
			(*info)->size_a--;
		}
		else
			do_ra(list_a);
		tmp--;
	}
}

int				resolve(t_list **list_a, t_list **list_b, t_info *info)
{
	int		tmp;

	while (info->size_a > 2)
	{
		info->median = find_median(*list_a, info->size_a);
		tmp = info->size_a;
		opti_rotation(tmp, list_a, list_b, &info);
	}
	do_pb(list_a, list_b);
	do_pb(list_a, list_b);
	info->size_b += 2;
	push_a(list_a, list_b, info);
	free(info);
	return (1);
}

void    push_swap(t_list **list_a, t_info *info)
{

	t_list *list_b;

	list_b = NULL;
	info->size_a = ft_lstsize(*list_a);
    info->size_b = 0;
    print_list(*list_a);
    if(info->size_a <= 5)
        hardcoding(info->size_a, list_a, &list_b);
    else
        resolve(list_a, &list_b, info);
	print_list(*list_a);
}