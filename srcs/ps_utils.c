/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:59:51 by user42            #+#    #+#             */
/*   Updated: 2021/06/24 21:21:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long int	find_max_skip(t_list *list, int skip)
{
	int		max;

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

int	find_pos(int n, t_list *list)
{
	int		pos;

	pos = 0;
	while (list->content != n)
	{
		list = list->next;
		pos++;
	}
	return (pos);
}

long int	find_max(t_list **list)
{
	t_list	*begin;
	int		ret;

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

long int	find_min(t_list **list)
{
	t_list	*begin;
	int		ret;

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
