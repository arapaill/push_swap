/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:26:08 by marvin            #+#    #+#             */
/*   Updated: 2021/04/20 13:26:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	init_stack(t_stack *stack)
{
	stack = malloc(sizeof(t_stack));
	if(!stack)
		error_manager("Malloc error");
	stack->a = malloc(sizeof(t_list ));
	if(!stack->a)
		error_manager("Malloc error");
	stack->b = malloc(sizeof(t_list ));
	if(!stack->b)
		error_manager("Malloc error");
}

void		addstack(int size, char **table, t_list **list)
{
	t_list	*tmp;
	int		content;
	int		i;

	tmp = NULL;
	i = 0;
	printf("size : %i\n", size);
	while (i <= size)
	{
		content = ft_atoi(table[i]);
		tmp = ft_ps_lstnew(content);
		ft_ps_lstadd(list, tmp);
		free_list(tmp);
		i++;
	}
	print_list((*list));
}
