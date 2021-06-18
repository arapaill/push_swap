/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:25:22 by user42            #+#    #+#             */
/*   Updated: 2021/06/18 12:21:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_push_swap.h"


int		ft_istri(t_list *a)
{
	while (a)
	{
		if (a->next)
        {
			if ((a->content) > (a->next->content))
				return (0);
        }
		a = a->next;
	}
	return (1);
}

void	ft_istrione(int size, char **table)
{
	t_stack	*stack;
    
    stack = malloc(sizeof(t_stack *));
    if(!stack)
        error_manager("Malloc error\n");
	addstack(size, table, &stack->a);
	if (ft_istri(stack->a) == 1)
	{
        printf("is sorted\n");
        free_list(stack->a);
        exit(1);
	}
    free_list(stack->a);
}

char    **table_to_table(int ac, char **av)
{
    char    **table;
    int     i;
    int     j;

    i = 0;
    j = 0;
    table = malloc(sizeof(char**) * (ac));
	if(!table)
        error_manager("Malloc error");
    while (i + 1 < ac)
    {
        table[i] = malloc(sizeof(char *) * ft_strlen(av[i + 1]));
        if(!table[i])
            error_manager("Malloc error\n");
        while (av[i + 1][j])
        {
            table[i][j] = av[i + 1][j];
            j++;
        }
        j = 0;
        i++;
    }
    table[i] = 0;
    return(table);
}

int     counter(char **table)
{
    int     i;

    i = 0;
    while (table[i])
        i++;
    i--;
    return(i);
}

int     main(int ac, char **av)
{
    char    **table;
    t_info  *info;
    t_list  *list_a;
    int     size;

	if(ac == 1)
        error_manager("too few argument\n");
    else if(ac == 2)
    {
        space_check(av[1]);
        table = ft_split(av[1], ' ');
    }
    else
        table = table_to_table(ac, av);
    errors(table);
    size = counter(table);
    //printf("TEST 1\n");
    ft_istrione(size, table);
    info = malloc(sizeof(t_info *));
    if(!info)
        error_manager("Malloc error\n");
    addstack(size, table, &list_a);
    push_swap(&list_a, info);
    return(0);
}