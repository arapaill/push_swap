/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:37:11 by user42            #+#    #+#             */
/*   Updated: 2021/06/03 14:53:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(t_list *list)
{
	t_list	*tmp;

	while (list && list->next)
	{
		tmp = list->next;
		list->next = list->next->next;
		tmp->next = list;
		list = tmp;
	}
}

void	ft_swap_a_b(t_stack *stack)
{
	ft_swap(stack->a);
	ft_swap(stack->b);
}

void	ft_rotate(t_list *list)
{
	t_list	*tmp;
	t_list *head;
	
	if(list && list->next)
	{
		tmp = list;
		list = list->next;
		head = list;
		tmp->next = NULL;
		while (list->next)
			list = list->next;
		list->next = tmp;
		list = head;
		
	}
}

void	ft_rotate_a_b(t_stack *stack)
{
	ft_rotate(stack->a);
	ft_rotate(stack->b);
}

void	ft_double_rotate(t_list *list)
{
	t_list	*head;
	t_list	*tmp;

	if(list && list->next)
	{
		head = list;
		while (list->next->next)
			list = list->next;
		tmp = list->next;
		list->next = NULL;
		list = head;
		tmp->next = list;
		list = tmp;
	}
}


void	ft_double_rotate_a_b(t_stack *stack)
{
	ft_double_rotate(stack->a);
	ft_double_rotate(stack->b);
}

void	ft_push_a(t_stack *stack)
{
	t_list	*tmp;

	if(stack->b)
	{
		tmp = stack->b->next;
		stack->b->next = stack->a;
		stack->a = stack->b;
		stack->b = tmp;
	}
}

void	ft_push_b(t_stack *stack)
{
	t_list	*tmp;

	if(stack->a)
	{
		tmp = stack->a->next;
		stack->a->next = stack->b;
		stack->b = stack->a;
		stack->a = tmp;
	}
}