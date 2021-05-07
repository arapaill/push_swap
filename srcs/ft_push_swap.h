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

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct      s_stack
{
	int             pos;
	int             size;
	struct s_stack	*next;
}                   t_stack;

/*
** Errors 
*/
void		error_checker(void);

/*
** Checker
*/

int		ft_strisnumber(char *str);

/* 
** Stack init
*/

void	init_stack_str(int argc, char **argv);

#endif