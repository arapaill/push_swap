/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:06:22 by user42            #+#    #+#             */
/*   Updated: 2021/06/24 17:54:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int		ispace(const char *str, int *j)
{
	int						i;
	int						neg;

	i = 0;
	neg = 0;
	while (str[i] == '\0' ||
			str[i] == '\t' ||
			str[i] == '\n' ||
			str[i] == '\v' ||
			str[i] == '\f' ||
			str[i] == '\r' ||
			str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	*j = i;
	return (neg);
}

long long			ft_atoi(const char *str)
{
	int			i;
	int			neg;
	unsigned long long 	n;
	unsigned long long	min;

	min = 2147483648;
	n = 0;
	i = 0;
	neg = ispace(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n + (str[i] - '0');
		n = n * 10;
		i++;
	}
	n = n / 10;
	if (n >= (min + 1) && neg == 1)
	error_manager("error, number too small\n");
	else if (n >= min && neg == 0)
		error_manager("error, number too big\n");
	if (neg == 1)
		return (n * (-1));
	else
		return (n);
}