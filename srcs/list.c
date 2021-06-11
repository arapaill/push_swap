/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:06:57 by user42            #+#    #+#             */
/*   Updated: 2021/06/11 13:49:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_push_swap.h"

void		free_list(t_list *a)
{
	t_list *tmp;

	while (a)
	{
		tmp = a->next;
		a = NULL;
		free(a);
		a = tmp;
	}
}

t_list		*ft_ps_lstnew(int	content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if(!list)
		error_manager("Malloc error\n");
	list->content = content;
	list->next = NULL;
	return (list);
}	

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void		ft_ps_lstadd(t_list **alst, t_list *new)
{
	if (new == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
		ft_lstlast(*alst)->next = new;
}

void				print_list(t_list *a)
{
	t_list	*tmp;
	
	tmp = a;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			printf("%i",tmp->content);
			tmp = tmp->next;
		}
		printf("%i\n",(int)tmp->content);
	}
}