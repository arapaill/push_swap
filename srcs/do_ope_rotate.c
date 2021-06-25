/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ope_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:15:14 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 13:58:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	do_ra(t_list **list)
{
	write(1, "ra\n", 3);
	ft_rotate(list);
}

void	do_rb(t_list **list)
{
	write(1, "rb\n", 3);
	ft_rotate(list);
}

void	do_rra(t_list **list)
{
	write(1, "rra\n", 4);
	ft_double_rotate(list);
}

void	do_rrb(t_list **list)
{
	write(1, "rrb\n", 4);
	ft_double_rotate(list);
}
