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

t_list				*addstack(int ac, char **av)
{
	t_list	*tmp;
	t_list	*list;
	int		content;

	tmp = NULL;
	list = NULL;
	while (ac >= 0)
	{
		content = ft_atoi(av[ac]);
		tmp = ft_ps_lstnew(content);
		ft_ps_lstadd(&list, tmp);
		tmp = NULL;
		ac--;
	}
	//print_list(list);
	return (list);
}
