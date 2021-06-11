/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ope.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:15:14 by user42            #+#    #+#             */
/*   Updated: 2021/06/11 13:25:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	do_sa(t_list **list)
{
	printf("sa\n");
	ft_swap(list);
}

void	do_sb(t_list **list)
{
	printf("sb\n");
	ft_swap(list);
}

void	do_ra(t_list **list)
{
	printf("ra\n");
	ft_rotate(list);
}

void	do_rb(t_list **list)
{
	printf("rb\n");
	ft_rotate(list);
}

void	do_rra(t_list **list)
{
	printf("rra\n");
	ft_double_rotate(list);
}

void	do_rrb(t_list **list)
{
	printf("rrb\n");
	ft_double_rotate(list);
}