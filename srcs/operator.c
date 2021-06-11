/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:37:11 by user42            #+#    #+#             */
/*   Updated: 2021/06/11 13:52:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(t_list **list)
{
	int		tmp;

	tmp = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = tmp;
}

void	do_ss(t_stack **stack)
{
	ft_swap(&(*stack)->a);
	ft_swap(&(*stack)->b);
	printf("ss\n");
}

void	ft_rotate(t_list **list)
{
	int		tmp;
	int		tmp2;
	t_list	*head;

	head = *list;
	tmp = head->content;
	(*list)->content = ft_lstlast(*list)->content;
	while ((*list)->next != NULL)
    {
        (*list) = (*list)->next;
        tmp2 = (*list)->content;
        (*list)->content = tmp;
        tmp = tmp2;
    }
    (*list) = head;
}

void	do_rr(t_stack **stack)
{
	ft_rotate(&(*stack)->a);
	ft_rotate(&(*stack)->b);
	printf("rr\n");
}

void	ft_double_rotate(t_list **list)
{
	t_list	*head;
	t_list	*tmp;

	if((*list) && (*list)->next)
	{
		head = (*list);
		while ((*list)->next->next)
			(*list) = (*list)->next;
		tmp = (*list)->next;
		(*list)->next = NULL;
		(*list) = head;
		tmp->next = (*list);
		(*list) = tmp;
	}
}


void	do_rrr(t_stack **stack)
{
	ft_double_rotate(&(*stack)->a);
	ft_double_rotate(&(*stack)->b);
	printf("rrr\n");
}

void	do_pa(t_stack **stack)
{
	t_list	*tmp;

	if((*stack)->b)
	{
		tmp = (*stack)->b->next;
		(*stack)->b->next = (*stack)->a;
		(*stack)->a = (*stack)->b;
		(*stack)->b = tmp;
	}
	printf("pa\n");
}

void	do_pb(t_stack **stack)
{
	t_list	*tmp;

	if((*stack)->a)
	{
		tmp = (*stack)->a->next;
		(*stack)->a->next = (*stack)->b;
		(*stack)->b = (*stack)->a;
		(*stack)->a = tmp;
	}
	printf("pb\n");
}