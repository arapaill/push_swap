/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:05:16 by user42            #+#    #+#             */
/*   Updated: 2021/06/24 17:28:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_push_swap.h"

void		sort_tab(int *tab, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (tab[j] > tab[j + 1])
				lib_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

int			find_median(t_list *list, int size)
{
	int		i;
	int		*tab;

	i = 0;
	tab = malloc(sizeof(int) * size);
	while (list->next)
	{
		tab[i] = list->content;
		list = list->next;
		i++;
	}
	sort_tab(tab, size);
	i = 0;
	while (i < size / 2)
		i++;
	i = tab[i];
	free(tab);
	return (i);
}