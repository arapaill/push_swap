/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 22:29:03 by user42            #+#    #+#             */
/*   Updated: 2021/06/28 15:02:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_2(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(line, "rr")))
	{
		ft_rotate(list_a);
		ft_rotate(list_b);
	}
	else if (!(ft_strcmp(line, "rra")))
		ft_double_rotate(list_a);
	else if (!(ft_strcmp(line, "rrb")))
		ft_double_rotate(list_b);
	else if (!(ft_strcmp(line, "rrr")))
	{
		ft_double_rotate(list_a);
		ft_double_rotate(list_b);
	}
	else
		return (0);
	return (1);
}

int	check(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(line, "sa")))
		ft_swap(*list_a);
	else if (!(ft_strcmp(line, "sb")))
		ft_swap(*list_b);
	else if (!(ft_strcmp(line, "ss")))
	{
		ft_swap(*list_a);
		ft_swap(*list_b);
	}
	else if (!(ft_strcmp(line, "pa")))
		push_a(list_a, list_b);
	else if (!(ft_strcmp(line, "pb")))
		push_b(list_a, list_b);
	else if (!(ft_strcmp(line, "ra")))
		ft_rotate(list_a);
	else if (!(ft_strcmp(line, "rb")))
		ft_rotate(list_b);
	else if (!check_2(line, list_a, list_b))
		return (0);
	return (1);
}

int	checker(t_list **list_a, t_list **list_b)
{
	int		ret;
	char	*line;

	ret = get_next_line(0, &line);
	while (ret > 0)
	{
		if (ret == -1)
		{
			free(line);
			return (0);
		}
		if (!(check(line, list_a, list_b)))
		{
			free(line);
			error_manager();
		}
		free(line);
		ret = get_next_line(0, &line);
	}
	free(line);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	char	**table;

	list_b = 0;
	if (ac == 1)
		error_manager();
	else if (ac == 2)
	{
		space_check(av[1]);
		table = ft_split(av[1], ' ');
	}
	else
		table = table_to_table(ac, av);
	errors(table);
	addstack(counter(table), table, &list_a);
	checker(&list_a, &list_b);
	if (ft_istri(list_a) && !ft_lstsize(list_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(list_a);
	free_table(table);
	exit(0);
}
