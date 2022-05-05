/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_operations_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:25:21 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/05 14:25:44 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_stack *b_stack)
{
	ft_putstr("rb\n");
	ft_rotation(b_stack);
}

void	ft_rr(t_stack *a_stack, t_stack *b_stack)
{
	ft_putstr("rr\n");
	ft_rotation(a_stack);
	ft_rotation(b_stack);
}

void	ft_rra(t_stack *a_stack)
{
	ft_putstr("rra\n");
	ft_rev_rotation(a_stack);
}

void	ft_rrb(t_stack *b_stack)
{
	ft_putstr("rrb\n");
	ft_rev_rotation(b_stack);
}

void	ft_rrr(t_stack *a_stack, t_stack *b_stack)
{
	ft_putstr("rrr\n");
	ft_rev_rotation(a_stack);
	ft_rev_rotation(b_stack);
}
