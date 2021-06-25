/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:25:22 by user42            #+#    #+#             */
/*   Updated: 2021/06/24 22:35:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_push_swap.h"

void	push_swap(t_list **list_a, t_info *info)
{
	if (ft_istri(*list_a))
	{
		free_list(*list_a);
		error_manager("\n");
	}
	info->size_a = ft_lstsize(*list_a);
	info->size_b = 0;
	if (info->size_a <= 5)
		hardcoding(info->size_a, list_a);
	else
		resolve(list_a, info);
}

int	main(int ac, char **av)
{
	char	**table;
	t_info	*info;
	t_list	*list_a;
	int		size;

	if (ac == 1)
		error_manager("too few argument\n");
	else if (ac == 2)
	{
		space_check(av[1]);
		table = ft_split(av[1], ' ');
	}
	else
		table = table_to_table(ac, av);
	errors(table);
	size = counter(table);
	info = malloc (sizeof (t_info *));
	if (!info)
		error_manager("Malloc error\n");
	addstack(size, table, &list_a);
	push_swap(&list_a, info);
	exit(0);
}
