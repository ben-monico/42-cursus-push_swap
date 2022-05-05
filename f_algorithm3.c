/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_algorithm3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:37:51 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/05 14:27:31 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_smol_algo(t_stack *a, t_stack *b)
{
	while (ft_lstsize(a) > 3)
		ft_pb(a, b);
	if (!ft_circsort(a) && !ft_checksort(a))
		ft_sa(a);
	return ;
}

void	ft_fix_offset(t_stack *a)
{
	while (a->head->index != 0)
	{
		if (ft_get_rotdir(0, a))
			ft_ra(a);
		else
			ft_rra(a);
	}
	return ;
}
