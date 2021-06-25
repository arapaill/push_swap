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
/*
** 
** void	print_all(t_list *a, t_list *b)
** {
** 	printf("list a :");
** 	print_list(a);
** 	printf("\n");
** 	printf("list b :");
** 	print_list(b);
** 	printf("\n");
** }
** 
** void	print_list(t_list *a)
** {
** 	t_list	*tmp;
** 
** 	tmp = a;
** 	if (tmp)
** 	{
** 		while (tmp && tmp->next)
** 		{
** 			printf("%i ", tmp->content);
** 			tmp = tmp->next;
** 		}
** 		printf("%i\n", tmp->content);
** 	}
** }
** 
*/
void	addstack(int size, char **table, t_list **list)
{
	t_list	*tmp;
	int		content;
	int		i;

	tmp = NULL;
	i = 0;
	while (i <= size)
	{
		content = ft_atoi(table[i]);
		tmp = ft_ps_lstnew(content);
		ft_ps_lstadd(list, tmp);
		free_list(tmp);
		i++;
	}
}
