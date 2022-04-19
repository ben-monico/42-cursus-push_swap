/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:17:33 by benmonico         #+#    #+#             */
/*   Updated: 2022/04/19 19:17:40 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// list to array. index array. push to list when they are the next index

int	ft_only_seq(t_stack *a, int mindex, int maxindex)
{
	t_node *ptr;

	ptr = a->head;
	while (ptr)
	{
		if (maxindex != 0 && ptr->index > mindex && ptr->index < maxindex)
			return (0);
		else if (maxindex == 0 && ptr->index > mindex)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	ft_findnext(int	mindex, int maxindex, t_stack *stack) // find cheapest next index to push
{
	t_node *ptr;
	int	r;
	int	rr;

	r = 0;
	if (!stack->head || !stack->head->next)
		return (0);
	ptr = stack->head;
	while (ptr && ptr->index != mindex && ptr->index != maxindex)
	{
		r++;
		ptr = ptr->next;
	}
	rr = 1;
	ptr = stack->tail;
	while (ptr && ptr->index != mindex && ptr->index != maxindex)
	{
		rr++;
		ptr = ptr->prev;
	}
	if (r < rr)
		return (1); //rot
	return (0);		//rev rot
}

void	ft_sort(t_stack *a, t_stack *b)
{
	t_node	*ptr;
	int		mindex;
	int		maxindex;

	mindex = 0;
	maxindex = a->size - 1;

	//iterate back and forth to find biggest sequence including 0. push all except those
	//find cheapest next to push and ra or rra	
	ptr = ft_find_index(a->head, 0);
	while (ptr) //push to b except for sequenced indexs.
	{
		if (ptr->index == mindex + 1)
			mindex++;
		ptr = ptr->next;
	}
	ptr = ft_find_index(a->head, 0);
	maxindex++;
	while (ptr) //push to b except for sequenced indexs.
	{
		if (ptr->index == maxindex - 1)
			maxindex--;
		ptr = ptr->prev;
	}
	if (maxindex == a->size)
		maxindex = 0;
	while (!ft_only_seq(a, mindex, maxindex)) //push to b except for sequenced indexs.
	{
		if ((maxindex != 0 && a->head->index >= maxindex) || a->head->index <= mindex)
				ft_ra(a);
		else
			ft_pb(a, b);
	// ft_printlist(a, b);
	}
	while (a->head->index != maxindex)
	{
		if (ft_findnext(maxindex, maxindex, a))
			ft_ra(a);
		else
			ft_rra(a);
	}
	// ft_printlist(a, b);
	if (maxindex == 0)
		maxindex = a->size;
	maxindex--;
	mindex++;
	while (b->head) //rotate or rev rotate stack b depending on next index returned
	{
		if (b->head->next && ft_findnext(mindex, maxindex, b)) // rotate until next
		{
			while (b->head->index != mindex && b->head->index != maxindex)
			{
				ft_rb(b);
				// ft_printlist(a, b);
			}
		}
		else//rev rotate until next
		{
			while (b->head->index != mindex && b->head->index != maxindex)
			{
				ft_rrb(b);
				// ft_printlist(a, b);
			}
		}
		ft_pa(b, a);
		// ft_printlist(a, b);
		if (a->head->index == mindex)
		{
			ft_ra(a); //check if findnext in b is worth doing rr
			// ft_printlist(a, b);
			mindex++;
		}
		else
			maxindex--;
	}
	while (a->head->index != 0) //rotate or rev rotate dependeing on 0 idnex position in list. make ind 0 - head a
	{
		if (ft_findnext(0, 0, a))
			ft_ra(a);
		else
			ft_rra(a);
		// ft_printlist(a, b);
	}
	// ft_printlist(a, b);
	return ;
}