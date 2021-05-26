/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:06:57 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 17:56:53 by user42           ###   ########.fr       */
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
	if(!list)
		error_manager("Malloc error\n");
	else if (content)
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

void				print_list(t_list *a)
{
	t_list	*tmp;
	
	tmp = a;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			printf("%i\n", tmp->content);
			tmp = tmp->next;
		}
		printf("%i\n", tmp->content);
		//printf("'%-10s' (%2i) -> %25p\n", (char*)tmp_sys_infos.list_input->content->value, tmp_sys_infos.list_input->content->type, tmp_sys_infos.list_input->next);
	}
}