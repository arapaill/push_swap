/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:37:11 by user42            #+#    #+#             */
/*   Updated: 2021/06/18 14:30:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(t_list *list)
{
	if (!list)
		return ;
	if (list->next)
		lib_swap(&list->content, &list->next->content);
}

void	do_ss(t_list **list_a, t_list **list_b)
{
	ft_swap(*list_a);
	ft_swap(*list_b);
	printf("ss\n");
}

void	ft_double_rotate(t_list **list)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*list) || !(*list)->next)
		return ;
	tmp = *list;
	cp = *list;
	while (tmp->next)
	{
		if (tmp->next->next)
			cp = cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *list;
	*list= tmp;
}

void	do_rr(t_list **list_a, t_list **list_b)
{
	ft_rotate(list_a);
	ft_rotate(list_b);
	printf("rr\n");
}

void	ft_rotate(t_list **list)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*list) || !((*list)->next))
		return ;
	tmp = *list;
	cp = (*list)->next;
	while ((*list)->next)
		*list = (*list)->next;
	(*list)->next = tmp;
	tmp->next = NULL;
	*list = cp;
}


void	do_rrr(t_list **list_a, t_list **list_b)
{
	ft_double_rotate(list_a);
	ft_double_rotate(list_b);
	printf("rrr\n");
}

void	do_pa(t_list **list_a, t_list  **list_b)
{
	t_list	*tmp;

	if (!(*list_b))
		return ;
	tmp = *list_b;
	*list_b = (*list_b)->next;
		tmp->next = *list_a;
	*list_a = tmp;
	printf("pa\n");
}

void	do_pb(t_list **list_a, t_list  **list_b)
{
	t_list	*tmp;

	if (!(*list_a))
		return ;
	tmp = *list_a;
	*list_a = (*list_a)->next;
	tmp->next = *list_b;
	*list_b = tmp;
	printf("pb\n");
}