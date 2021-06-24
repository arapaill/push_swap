/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:25:22 by user42            #+#    #+#             */
/*   Updated: 2021/06/24 19:18:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_push_swap.h"


void    push_swap(t_list **list_a, t_info *info)
{
	if (ft_istri(*list_a))
    {
        free_list(*list_a);
		error_manager("\n");
    }
	info->size_a = ft_lstsize(*list_a);
    info->size_b = 0;
    if(info->size_a <= 5)
        hardcoding(info->size_a, list_a);
    else
        resolve(list_a, info);
	//print_list(*list_a);
}

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
char    **table_to_table(int ac, char **av)
{
    char    **table;
    int     i;
    int     j;

    i = 0;
    j = -1;
    table = malloc(sizeof(char**) * (ac));
	if(!table)
        error_manager("Malloc error");
    while (i + 1 < ac)
    {
        table[i] = malloc(sizeof(char *) * ft_strlen(av[i + 1]));
        if(!table[i])
            error_manager("Malloc error\n");
        while (av[i + 1][++j])
            table[i][j] = av[i + 1][j];
        j = -1;
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
    info = malloc(sizeof(t_info *));
    if(!info)
        error_manager("Malloc error\n");
    addstack(size, table, &list_a);
    push_swap(&list_a, info);
    exit(0);
}