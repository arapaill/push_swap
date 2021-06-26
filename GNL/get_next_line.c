/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 07:18:19 by user42            #+#    #+#             */
/*   Updated: 2021/06/26 11:40:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_index(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] != (char)c)
		return (-1);
	return (i);
}

int	get_line(char *str, char **line, int i)
{
	int		len;

	*line = ft_substr(str, 0, i);
	++i;
	len = ft_strlen_gnl(str + i) + 1;
	ft_memmove(str, str + i, len);
	return (1);
}

int	dup_n_free(char	**str, char	**line, int ret)
{
	if (*str)
	{
		*line = ft_strdup(*str);
		free(*str);
		return (ret);
	}
	free(*str);
	*line = ft_strdup("");
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*str = NULL;
	int				ret;
	int				i;

	if (str)
		i = find_index(str, '\n');
	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (str && i != -1)
		return (get_line(str, line, i));
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
		i = find_index(str, '\n');
		if (i != -1)
			return (get_line(str, line, i));
		ret = read(fd, buff, BUFFER_SIZE);
	}
	return (dup_n_free(&str, line, ret));
}
