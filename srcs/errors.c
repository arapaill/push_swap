/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:43:16 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 15:56:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	error_manager(void)
{
	ft_putstr("Error\n", 1);
	exit(2);
}

void	ft_isint(char **table)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (table[i])
	{
		while (table[i][j])
		{
			if (table[i][j] == '-' || table[i][j] == '+')
				j++;
			if (ft_isdigit(table[i][j]) == 0)
			{
				free_table(table);
				error_manager();
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	dual(char **table)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (table[j])
	{
		while (table[i])
		{
			if (ft_strcmp(table[i], table[j]) == 0 && i != j)
			{
				free_table(table);
				error_manager();
			}
			i++;
		}
		j++;
		i = 0;
	}
}

void	space_check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' '
			&& str[i] != '-' && str[i] != '+')
		{
			free(str);
			error_manager();
		}
		i++;
	}
}

void	errors(char **table)
{
	ft_isint(table);
	dual(table);
}
