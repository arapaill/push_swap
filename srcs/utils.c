/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:34:29 by user42            #+#    #+#             */
/*   Updated: 2021/06/10 17:27:52 by user42           ###   ########.fr       */
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
	long long 	n;
	long long	min;

	min = 2147483647;
	n = 0;
	i = 0;
	neg = ispace(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n + (str[i] - '0');
		n = n * 10;
		i++;
		if (n >= (min + 1) && neg == 1)
			error_manager("error, number too small\n");
		else if (n >= min && neg == 0)
			error_manager("error, number too big\n");
	}
	n = n / 10;
	if (neg == 1)
		return (n * (-1));
	else
		return (n);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


