/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:06:57 by user42            #+#    #+#             */
/*   Updated: 2021/06/26 11:51:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_push_swap.h"

t_list	*ft_ps_lstnew(int content)
{
	t_list	*list;

	list = (t_list *)malloc (sizeof (t_list));
	if (!list)
	{
		free_list(list);
		error_manager();
	}
	list->content = content;
	list->next = NULL;
	return (list);
}	

void	free_list(t_list *a)
{
	t_list	*tmp;

	while (a)
	{
		tmp = a->next;
		a = NULL;
		free(a);
		a = tmp;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_ps_lstadd(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (!(*alst))
		*alst = new;
	else
		ft_lstlast(*alst)->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
