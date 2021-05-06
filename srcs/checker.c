/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 09:55:41 by marvin            #+#    #+#             */
/*   Updated: 2021/04/20 09:55:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		error_checker()
{
	write(1, "KO", 3);
		exit;
}

int		ft_strisnumber(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	while (i < j)
	{
		if (ft_isalnum(str[i]) != 0)
			return (1);
		i++;
	}
	return(0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		nb;

	i = 0;
	if( argc < 2)
		return (error_checker());
	while(i < argc)
	{
		if(ft_strisnumber(argv[i]) != 0)
			return (error_checker());
		nb = ft_atoi(argv[i]);
	}
	write(1, "OK", 3);
	return(0);
}