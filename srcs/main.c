/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:25:22 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 14:50:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_push_swap.h"


int		ft_istri(t_list *a)
{
	while (a)
	{
		if (a->next)
			if ((a->content) > (a->next->content))
				return (0);
		a = a->next;
	}
	return (1);
}

void	ft_istrione(int ac, char **av)
{
	t_stack	stack;
    
	stack.a = addstack(ac, av);
	stack.b = NULL;
	if (ft_istri(stack.a) == 1)
	{
		free_list(stack.a);
		free_list(stack.b);
		exit (1);
	}
    free_list(stack.a);
	free_list(stack.b);
}


int     main(int ac, char **av)
{
	if(ac == 1)
        error_manager("too few argument");
    errors(av);
    ft_istrione(ac, av);
    //push_swap(ac, av);
    return(0);
}