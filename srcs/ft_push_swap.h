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
# include <string.h>

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

typedef	struct		s_info
{
	int				median;
	int				size_b;
	int				size_a;
	int				flags;

}					t_info;

typedef	struct		s_data
{
	int				max_a;
	int				max_b;
	int				flags_a;
	int				flags_b;
	int				pos_a;
	int				pos_b;
}					t_data;

/*
** main
*/
int		ft_istri(t_list *a);


/*
** Errors 
*/
void    			errors(char **table);
void				error_manager(char *error);
void				space_check(char *str);

/*
** utils
*/
void				ft_putstr(char *s, int fd);
int					ft_isdigit(int c);
int					ft_strcmp(char *s1, char *s2);
long long			ft_atoi(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *str);
void				lib_swap(int *a, int *b);

/* 
** Stack init
*/

void				init_stack_str(int argc, char **argv);
void				addstack(int size, char **table, t_list **list);

/*
** list
*/

void				free_list(t_list *a);
t_list				*ft_ps_lstnew(int	content);
void				ft_ps_lstadd(t_list **alst, t_list *new);
void				print_list(t_list *a);
void				print_all(t_list *a, t_list *b);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);

/*
** operations
*/

void				ft_swap(t_list *list);
void				do_ss(t_list **list_a, t_list **list_b);
void				ft_rotate(t_list **list);
void				do_rrr(t_list **list_a, t_list **list_b);
void				do_rr(t_list **list_a, t_list **list_b);
void				ft_double_rotate(t_list **list);
void				do_pa(t_list **list_a, t_list  **list_b);
void				do_pb(t_list **list_a, t_list  **list_b);
void				do_sa(t_list *list);
void				do_sb(t_list *list);
void				do_ra(t_list **list);
void				do_rb(t_list **list);
void				do_rra(t_list **list);
void				do_rrb(t_list **list);


/*
** push_swap
*/
void    push_swap(t_list **list_a, t_info *info);
void    hardcoding(int size, t_list **list_a);

/*
** find_median
*/

int			find_median(t_list *list, int size);
#endif