/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_operations_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:27:14 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/05 14:25:13 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_stack *b_stack)
{
	ft_putstr("sb\n");
	ft_swap(b_stack->head);
}

void	ft_ss(t_stack *a_stack, t_stack *b_stack)
{
	ft_putstr("ss\n");
	ft_sa(a_stack);
	ft_sb(b_stack);
}

void	ft_pa(t_stack *b_stack, t_stack *a_stack)
{
	ft_putstr("pa\n");
	ft_push(b_stack, a_stack);
}

void	ft_pb(t_stack *a_stack, t_stack *b_stack)
{
	ft_putstr("pb\n");
	ft_push(a_stack, b_stack);
}

void	ft_ra(t_stack *a_stack)
{
	ft_putstr("ra\n");
	ft_rotation(a_stack);
}
