/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:37:11 by user42            #+#    #+#             */
/*   Updated: 2021/06/14 17:02:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(t_list **list)
{
	if (!(*list))
		return ;
	if ((*list)->next)
		lib_swap(&(*list)->content, &(*list)->next->content);
}

void	do_ss(t_stack **stack)
{
	ft_swap(&(*stack)->a);
	ft_swap(&(*stack)->b);
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
	*list = tmp;
}

void	do_rr(t_stack **stack)
{
	ft_rotate(&(*stack)->a);
	ft_rotate(&(*stack)->b);
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


void	do_rrr(t_stack **stack)
{
	ft_double_rotate(&(*stack)->a);
	ft_double_rotate(&(*stack)->b);
	printf("rrr\n");
}

void	do_pa(t_stack **stack)
{
    t_list *tmp;
    
	if (!(*stack)->b)
		return ;
	tmp = (*stack)->b;
	(*stack)->b = (*stack)->b->next;
	tmp->next = (*stack)->a;
	(*stack)->a = tmp;
	printf("pa\n");
}

void	do_pb(t_stack **stack)
{
     t_list *tmp;
    
	if (!(*stack)->a)
		return ;
	tmp = (*stack)->a;
	(*stack)->a = (*stack)->a->next;
	tmp->next = (*stack)->b;
	(*stack)->b = tmp;
	printf("pb\n");
}