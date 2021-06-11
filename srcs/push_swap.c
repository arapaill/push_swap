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
    while ((*list)->next != NULL)
    {
        if ((*list)->content < ret)
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
    do_pb(&(*stack));
    case_3(stack);
    do_pa(&(*stack));
    do_ra(&(*stack)->a);
}


void    hardcoding(int size, t_stack **stack)
{
    if(size == 1)
        do_sa(&(*stack)->a);
    else if(size == 2)
        case_3(stack);
    else if(size == 3)
        case_4(stack);
    //else if (size == 4)
       // case_5(stack);
}

void    push_swap(int size, char **table)
{
    t_stack	*stack;
    
    stack = malloc(sizeof(t_stack *));
    if(!stack)
        error_manager("Malloc error\n");
    addstack(size, table, &stack->a);
    print_list(stack->a);
    if(size <= 4)
        hardcoding(size, &stack);
    print_list(stack->a);
}