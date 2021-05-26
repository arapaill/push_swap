/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:06:57 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 14:30:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_push_swap.h"

void		free_list(t_list *a)
{
	t_list *tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

t_list		*ft_ps_lstnew(int content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
		if (content)
			list->content = content;
	return (list);
}

void		ft_ps_lstadd(t_list **alst, t_list *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}
