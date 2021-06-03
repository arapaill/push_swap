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

t_list				*addstack(int size, char **table)
{
	t_list	*tmp;
	t_list	*list;
	int		content;

	tmp = NULL;
	list = NULL;
	while (size >= 0)
	{
		content = ft_atoi(table[size]);
		tmp = ft_ps_lstnew(content);
		ft_ps_lstadd(&list, tmp);
		tmp = NULL;
		size--;
	}
	//print_list(table);
	return (list);
}
