/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_less_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:07:07 by user42            #+#    #+#             */
/*   Updated: 2021/06/22 16:03:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    case_3(t_list **list_a)
{
    while (!ft_istri(*list_a))
    {
        if((*list_a)->content > (*list_a)->next->content)
            do_sa(*list_a);
        if(!ft_istri(*list_a))
            do_rra(list_a);
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


void    case_4(t_list **list_a, t_list **list_b)
{
    int min;

    min = find_min(list_a);
    while ((*list_a)->content != min)
        do_ra(list_a);
    do_pb(list_a, list_b);
    case_3(list_a);
    do_pa(list_a, list_b);
    if(!ft_istri(*list_a))
         do_rra(list_a);
}

void    case_5(t_list **list_a, t_list **list_b)
{
	long int	max;

	while (ft_lstsize(*list_a) != 3)
	{
		max = find_max(list_a);
		while ((*list_a)->content != max)
			do_ra(list_a);
		if ((*list_a)->content == max)
			do_pb(list_a, list_b);
	}
	case_3(list_a);
    if ((*list_b)->content > (*list_b)->next->content)
		do_sb(*list_b);
	do_pa(list_a, list_b);
	do_pa(list_a, list_b);

	return ;
}

void    hardcoding(int size, t_list **list_a)
{
    t_list *list_b;

    list_b = 0;
    printf("size : %i\n", size);
    if(size == 2)
        do_sa(*list_a);
    else if(size == 3)
        case_3(list_a);
    else if(size == 4)
        case_4(list_a, &list_b);
    else if (size == 5)
        case_5(list_a, &list_b);
}
