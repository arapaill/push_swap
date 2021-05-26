/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:43:16 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 14:01:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		error_manager(char *error)
{
	ft_putstr(error, 1);
	exit(2);
} 

void		ft_isint(char **av)
{
	int     j;
    int     i;

	j = 0;
    i = 1;
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] == '-')
				j++;
			if (ft_isdigit(av[i][j]) == 0)
				error_manager("Error : one argument or more are not int\n");
			j++;
		}
		j = 0;
		i++;
	}
}

void    	dual(char **av)
{
    int	i;
    int j;

    j = 1;
	i = 1;
	while (av[j])
	{
		while (av[i])
		{
			if (ft_strcmp(av[i], av[j]) == 0 && i != j)
				error_manager("Error : two arguments or more are the same\n");
			i++;
		}
		j++;
		i = 1;
	}
}

void    	 errors(char **av)
{
    int     i;
    int     error;

    dual(av);
    ft_isint(av); 
}