/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 22:35:02 by user42            #+#    #+#             */
/*   Updated: 2021/06/26 11:12:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_push_swap.h"

void	free_table(char **table)
{
	int		i;

	i = -1;
	while (table[++i])
		free(table[i]);
	free(table);
}

int	ft_istri(t_list *a)
{
	while (a)
	{
		if (a->next)
		{
			if ((a->content) > (a->next->content))
				return (0);
		}
		a = a->next;
	}
	return (1);
}

char	**table_to_table(int ac, char **av)
{
	char	**table;
	int		i;
	int		j;

	i = 0;
	j = -1;
	table = malloc (sizeof (char **) * (ac));
	if (!table)
		error_manager();
	while (i + 1 < ac)
	{
		table[i] = malloc (sizeof (char *) * ft_strlen(av[i + 1]) + 1);
		if (!table[i])
			error_manager();
		while (av[i + 1][++j])
			table[i][j] = av[i + 1][j];
		table[i][j] = '\0';
		j = -1;
		i++;
	}
	table[i] = NULL;
	return (table);
}

int	counter(char **table)
{
	int		i;

	i = 0;
	while (table[i])
		i++;
	i--;
	return (i);
}
