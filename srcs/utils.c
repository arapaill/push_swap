/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:34:29 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 14:20:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_push_swap.h"

void	ft_putstr(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	while (*s)
		write(fd, s++, 1);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (s1[0] == '\0' || s2[0] == '\0')
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		if (!s1[i] && s2[i])
			return (-1);
		if (s1[i] && !s2[i])
			return (-1);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int		ft_sign(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && (str[i] < 49 || str[i] > 57))
	{
		if (str[i] == 45 && ft_isdigit(str[i + 1]) != 0)
		{
			return (-1);
		}
		else if ((str[i] == 45 || str[i] == 43) &&
				(str[i + 1] == 45 || str[i + 1] == 43))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int				ft_atoi(const char *str)
{
	int i;
	int res;
	int sign;

	sign = ft_sign(str);
	res = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '-' || str[i] == '+'
			|| str[i] == ' ')
	{
		if ((str[i] == '-' || str[i] == '+') && str[i + 1] == ' ')
			return (0);
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}