/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:17:33 by benmonico         #+#    #+#             */
/*   Updated: 2022/05/04 13:37:35 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// list to array. index array. push to list when they are the next index

int	ft_get_rotdir(int	index, t_stack *stack) // find cheapest next index to push
{
	t_node *ptr;
	int	r;
	int	rr;

	r = 0;
	if (!stack->head || !stack->head->next)
		return (0);
	ptr = stack->head;
	while (ptr && ptr->index != index)
	{
		r++;
		ptr = ptr->next;
	}
	rr = 1;
	ptr = stack->tail;
	while (ptr && ptr->index != index)
	{
		rr++;
		ptr = ptr->prev;
	}
	if (r < rr)
		return (1); //rot
	return (0);		//rev rot
}
