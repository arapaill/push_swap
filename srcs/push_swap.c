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

void    case_3(t_stack **stack)
{
    while (!ft_istri((*stack)->a))
    {
        if((*stack)->a->content > (*stack)->a->next->content)
            do_sa(&(*stack)->a);
        if(!ft_istri((*stack)->a))
            do_ra(&(*stack)->a);
    }
}

long int    find_min(t_list **list)
{
    t_list *begin;
    int      ret;

    ret = (int)(*list)->content;
    begin = (*list);
    while ((*list) != NULL)
    {
        if ((*list)->content < ret)
            ret = (int)(*list)->content;
        (*list) = (*list)->next;
    }
    (*list) = begin;
    return (ret);
}

long int    find_max(t_list **list)
{
    t_list *begin;
    int      ret;

    ret = (int)(*list)->content;
    begin = (*list);
    while ((*list) != NULL)
    {
        if ((*list)->content > ret)
            ret = (int)(*list)->content;
        (*list) = (*list)->next;
    }
    (*list) = begin;
    return (ret);
}


void    case_4(t_stack **stack)
{
    int min;

    min = find_min(&(*stack)->a);
    while ((int)(*stack)->a->content != min)
        do_ra(&(*stack)->a);
    do_pb(stack);
    case_3(stack);
    do_pa(stack);
    do_ra(&(*stack)->a);
}


void    case_5(t_stack **stack)
{
	long int	max;

	while (ft_lstsize((*stack)->a) != 3)
	{
		max = find_max(&(*stack)->a);
		while ((*stack)->a->content != max)
			do_ra(&(*stack)->a);
		if ((*stack)->a->content == max)
			do_pb(stack);
	}
	case_3(stack);
    if ((*stack)->b->content > (*stack)->b->next->content)
		do_sb(&(*stack)->b);
	do_pa(stack);
	do_pa(stack);
	return ;
}

void    hardcoding(int size, t_stack **stack)
{
    if(size == 1)
        do_sa(&(*stack)->a);
    else if(size == 2)
        case_3(stack);
    else if(size == 3)
        case_4(stack);
    else if (size == 4)
        case_5(stack);
}

int					find_max_skip(t_list *list, int skip)
{
	int	max;

	max = -2147483648;
	while (list->next && list->next->content)
	{
		if (list->content > max && list->content != skip)
			max = list->content;
		list = list->next;
	}
	if (list->content > max && list->content != skip)
		max = list->content;
	return (max);
}


static void		push_max(t_stack **stack, t_info *info, int max)
{
	int	f;

	f = 0;
	if ((*stack)->b->content < max)
	{
		while ((*stack)->b->content != max)
		{
			if ((*stack)->b->next->content == max)
			{
				do_sb(&(*stack)->b);
				do_pa(stack);
				f = 1;
				break ;
			}
			if (info->flags == 1)
				do_rb(&(*stack)->b);
			else
				do_rrb(&(*stack)->b);
		}
	}
	if (!f)	
		do_pa(stack);
}

int		find_pos(int n, t_list *list)
{
	int	pos;

	pos = 0;
	while (list->next && list->content != n)
	{
		list = list->next;
		pos++;
	}
	return (pos);
}

static void		push_a(t_stack **stack, t_info *info)
{
	while (info->size_b)
	{
		info->flags_a = 0;
		info->flags_b = 0;
		info->max_b = find_max_skip((*stack)->b, INT_MIN);
		info->max_a = find_max_skip((*stack)->b, info->max_b);
		if ((info->pos_a = find_pos(info->max_b, (*stack)->b)) < info->size_b / 2)
			info->flags_a = 1;
		if (info->max_a != INT_MIN && (info->pos_b =
			find_pos(info->max_a, (*stack)->b)) < info->size_b / 2)
			info->flags_b = 1;
		info->flags = info->flags_a;
		if (info->max_a != INT_MIN && info->flags_a == info->flags_b &&
				((info->pos_a > info->pos_b && info->flags_a) ||
				(info->pos_a < info->pos_b && !info->flags_a)))
		{
			push_max(stack, info, info->max_a);
			push_max(stack, info, info->max_b);
			do_sa(&(*stack)->a);
			info->size_b--;
		}
		else
			push_max(stack, info, info->max_b);
		info->size_b--;
	}
	printf("PUSH_A\n");
}

static void		opti_rotation(int tmp ,t_stack **stack, t_info **info)
{
	while (tmp && (*info)->size_a > 2)
	{
		if ((*stack)->a->content <= (*info)->median)
		{
			do_pb(stack);
			if ((*stack)->b->content < find_median((*stack)->b, (*info)->size_b) &&
					(*info)->size_b > 1)
			{
				if ((*stack)->a->content > (*info)->median)
					do_rr(stack);
				else
					do_rb(&(*stack)->b);
			}
			(*info)->size_b++;
			(*info)->size_a--;
		}
		else
			do_ra(&(*stack)->a);
		tmp--;
	}
}

int				resolve(t_stack **stack, t_info *info)
{
	int		tmp;
    int     size_b;

    info->size_a = ft_lstsize((*stack)->a);
    info->size_b = 0;
	while (info->size_a > 2)
	{
		info->median = find_median((*stack)->a, info->size_a);
		tmp = info->size_a;
		opti_rotation(tmp, stack, &info);
	}
	do_pb(stack);
	do_pb(stack);
	info->size_b += 2;
	push_a(stack, info);
	print_list((*stack)->a);
	return (1);
}

void    push_swap(int size, char **table)
{
    t_stack	*stack;
    t_info  *info;

    info = malloc(sizeof(t_info *));
    stack = malloc(sizeof(t_stack *));
    if(!stack || !info)
        error_manager("Malloc error\n");
    addstack(size, table, &stack->a);
    print_list(stack->a);
    if(size <= 4)
        hardcoding(size, &stack);
    else
        resolve(&stack, info);
}