/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:26:53 by marvin            #+#    #+#             */
/*   Updated: 2021/04/20 10:26:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct		s_stack
{
	t_list			*a;
	t_list			*b;
}					t_stack;

/*
** Errors 
*/
void    	errors(char **av);
void		error_manager(char *error);
void		space_check(char *str);

/*
** utils
*/
void	ft_putstr(char *s, int fd);
int		ft_isdigit(int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);

/* 
** Stack init
*/

void		init_stack_str(int argc, char **argv);
t_list		*addstack(int ac, char **av);

/*
** list
*/

void		free_list(t_list *a);
t_list		*ft_ps_lstnew(int content);
void		ft_ps_lstadd(t_list **alst, t_list *new);
void				print_list(t_list *a);
#endif