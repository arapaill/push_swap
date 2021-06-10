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

void    case_2(t_stack **stack)
{
    ft_swap(&(*stack)->a);
}

void    case_3(t_stack **stack)
{
    while (!ft_istri((*stack)->a))
    {
        if((*stack)->a->content > (*stack)->a->next->content)
            ft_swap(&(*stack)->a);
        if(!ft_istri((*stack)->a))
            ft_rotate(&(*stack)->a);
    }
    print_list((*stack)->a);
}

void    hardcoding(int size, t_stack **stack)
{
    if(size == 1)
        case_2(stack);
    else if(size == 2)
        case_3(stack);
   // else if(size == 3)
       // case_4(stack);
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