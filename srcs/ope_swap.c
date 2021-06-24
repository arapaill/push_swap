/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:08:42 by user42            #+#    #+#             */
/*   Updated: 2021/06/24 21:18:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	lib_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap(t_list *list)
{
	if (!list)
		return ;
	if (list->next)
		lib_swap(&list->content, &list->next->content);
}

void	do_ss(t_list **list_a, t_list **list_b)
{
	ft_swap(*list_a);
	ft_swap(*list_b);
	printf("ss\n");
}

void	do_sa(t_list *list)
{
	printf("sa\n");
	ft_swap(list);
}

void	do_sb(t_list *list)
{
	printf("sb\n");
	ft_swap(list);
}
