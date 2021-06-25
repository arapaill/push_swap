/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:25:22 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 15:52:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_push_swap.h"

void	push_swap(t_list **list_a, t_info *info)
{
	printf("TEST 1\n");
	if (list_a && ft_istri(*list_a))
	{
		free_list(*list_a);
		free(info);
		exit(0);
	}
	printf("TEST 2\n");
	info->size_a = ft_lstsize(*list_a);
	printf("TEST 3\n");
	info->size_b = 0;
	printf("TEST 4\n");
	if (list_a && info->size_a <= 5)
		hardcoding(info->size_a, list_a);
	else if (list_a)
		resolve(list_a, info);
	printf("TEST 5\n");
}

int	main(int ac, char **av)
{
	char	**table;
	t_info	*info;
	t_list	*list_a;
	int		size;

	if (ac == 1)
		exit(0);
	else if (ac == 2)
	{
		space_check(av[1]);
		table = ft_split(av[1], ' ');
	}
	else
		table = table_to_table(ac, av);
	errors(table);
	size = counter(table);
	addstack(size, table, &list_a);
	free_table(table);
	info = malloc (sizeof (t_info *));
	if (!info)
		error_manager();
	push_swap(&list_a, info);
	free(info);
	exit(0);
}
