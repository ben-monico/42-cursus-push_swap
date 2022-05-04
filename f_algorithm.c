/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:17:33 by benmonico         #+#    #+#             */
/*   Updated: 2022/05/04 18:47:44 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotcrl(t_stack *a, t_stack *b, t_node *bptr, t_node *aptr)
{
	while (b->head != bptr)
	{
		if (ft_get_rotdir(bptr->index, b))
		{
			if (ft_get_rotdir(aptr->index, a) && a->head != aptr)
				ft_rr(a,b);
			else
				ft_rb(b);
		}
		else
		{
			if (!ft_get_rotdir(aptr->index, a) && a->head != aptr)
				ft_rrr(a,b);
			else
				ft_rrb(b);
		}
	}
	return ;
}

static void	ft_rotnpush(t_stack *a, t_stack *b)
{
	t_node	*bptr;
	t_node	*aptr;

	while (b->head)
	{
		if (b->head->next)
			bptr = ft_get_cheapest(a, b, b->head);
		else if (!b->head->next)
			bptr = b->head;
		aptr = getaptr(a, bptr);
		ft_rotcrl(a, b, bptr, aptr);
		while (a->head != aptr)
		{
			if (ft_get_rotdir(aptr->index, a))
				ft_ra(a);
			else
				ft_rra(a);
		}
		ft_pa(b, a);
	}
	return ;
}

int	ft_get_rotdir(int index, t_stack *stack)
{
	t_node	*ptr;
	int		r;
	int		rr;

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
	return (r < rr);
}

static void	ft_push_algo(t_stack *a, t_stack *b, int *seq)
{
	int amount;

	amount = a->size;
	if (a->size > 50)
		amount = a->size * 0.5;
	if (a->size > 200)
		amount = a->size * 0.175;
	while (ft_lstsize(a) != arrlen(seq))
	{
		if (ft_isseq(seq, a->head->index) || a->head->index < ft_lstsize(a) - amount)
			ft_ra(a);
		else
			ft_pb(a, b);
	}
	return ;
}

int	ft_algorithm(t_stack *a, t_stack *b)
{
	int *seq;

	seq = ft_findsequence(a, a->head);
	if (!seq)
		return (0);
	if (a->size <= 5)
		ft_smol_algo(a, b);
	else
		ft_push_algo(a, b, seq);
	free(seq);
	ft_rotnpush(a, b);
	ft_fix_offset(a);
	return (1);	
}
