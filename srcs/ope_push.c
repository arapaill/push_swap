/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:11:02 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 11:21:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_a(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	if (!(*list_b))
		return ;
	tmp = *list_b;
	*list_b = (*list_b)->next;
	tmp->next = *list_a;
	*list_a = tmp;
}

void	push_b(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	if (!(*list_a))
		return ;
	tmp = *list_a;
	*list_a = (*list_a)->next;
	tmp->next = *list_b;
	*list_b = tmp;
}

void	do_pa(t_list **list_a, t_list **list_b)
{
	push_a(list_a, list_b);
	printf("pa\n");
}

void	do_pb(t_list **list_a, t_list **list_b)
{
	push_b(list_a, list_b);
	printf("pb\n");
}
