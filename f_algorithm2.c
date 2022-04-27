/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_algorithm2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:22:13 by bcarreir          #+#    #+#             */
/*   Updated: 2022/04/26 16:40:59 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	arrlen(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	i++; // cause of index 0
	while (arr[i])
		i++;
	return (i);
}

int	ft_isseq(int *arr, int index)
{
	int	i;

	i = 0;
	while (i < arrlen(arr))
	{
		if (index ==  arr[i])
			return (1);
		i++;
	}
	return (0);
}

int	*ft_findsequence(t_stack *a)
{
	t_node	*ptr;
	t_node	*start;
	int	*best;
	int	*cur;
	int	i;
	int	zero;

	zero = 0;

	best = (int *)ft_calloc(a->size, sizeof(int));
	if (!best)
		return (NULL);
	cur = (int *)ft_calloc(a->size, sizeof(int));
	if (!cur)
		return (NULL);
	start = a->head;
	while (start)
	{
		cur[0] = start->index;
		ptr = start->next;
		i = 1;
		while (ptr)
		{
			if ((zero == 0 && (ptr->index > cur[i - 1] || ptr->index == 0)) ||
				(zero == 1 && ptr->index > cur[i - 1] && ptr->index < cur[0]))
			{
				if (ptr->index == 0)
					zero = 1;
				cur[i] = ptr->index;
				i++;
			}
			ptr = ptr->next;
		}
		if (arrlen(best) < arrlen(cur))
			ft_memcpy(best, cur, (sizeof(int) * a->size));
		ft_bzero(cur, sizeof(int) * a->size);
		start = start->next;
	}
	free (cur);
	return (best);
}

int	ft_maxind(t_stack *stack)
{
	t_node	*aptr;
	int		maxindex;

	if (!stack->head->next)
		return(stack->head->index);
	maxindex = 0;
	aptr = stack->head;
	while (aptr)
	{
		if (aptr->index > maxindex)
			maxindex = aptr->index;
		aptr = aptr->next;
	}
	return (maxindex);
}

t_node	*getaptr(t_stack *a, t_node *bptr)
{
	t_node *aptr;
	int	maxindex;

	maxindex = ft_maxind(a);
	if (maxindex < bptr->index && a->tail->index == maxindex)
		return (a->head);
	aptr = a->head;
	if (bptr->index > a->tail->index && bptr->index < aptr->index)
		return (a->head);
	while (aptr->next)
	{
		if (aptr->prev)
			if ((aptr->index > bptr->index && aptr->prev->index < bptr->index) ||
				(maxindex < bptr->index && aptr->prev->index == maxindex))
				break;
		aptr = aptr->next;
	}
	return (aptr);
}

int	ft_nodecounter(t_stack *stack, t_node *ptr, int i)
{
	t_node	*aux;
	int		count;
	
	count = 0;
	if (i == 1)
		aux = stack->head;
	else
	{
		aux = stack->tail;
		count++;
	}
	while (ptr && aux && aux != ptr)
	{
		if (i == 1)
			aux = aux->next;
		else
			aux = aux->prev;
		count++;
	}
	return (count);
}

t_node	*ft_nextpush(t_stack *a, t_stack *b)
{
	t_node	*bptr;
	t_node 	*aptr;
	t_node	*chpptr;
	int		bcounter;
	int		acounter;
	int		cheap;

	bcounter = 0;
	acounter = 0;
	cheap = -1;
	bptr = b->head;
	chpptr = bptr;

	while (bptr)
	{
		aptr = getaptr(a, bptr);
		bcounter = ft_nodecounter(b, bptr, ft_findnext(bptr->index, bptr->index, b));
		acounter = ft_nodecounter(a, aptr, ft_findnext(aptr->index, aptr->index, a));
		if (acounter + bcounter < cheap || cheap == -1)
		{
			cheap = acounter + bcounter;
			chpptr = bptr;
		}
		bptr = bptr->next;
	}
	return (chpptr);
}

t_node	*ft_get_next_unseq(t_stack *a, int *seq)
{
	t_node	*ptrh;
	t_node	*ptrt;

	ptrh = a->head;
	ptrt = a->tail;
	while (ptrh && ptrt)
	{
		if (!ft_isseq(seq, ptrh->index))
			return (ptrh);
		if (!ft_isseq(seq, ptrt->index))
			return(ptrt);
		ptrh = ptrh->next;
		ptrt = ptrt->prev;
	}
	return (NULL);
}

char	*ft_algo2(t_stack *a, t_stack *b)
{
	t_node	*ptr;
	t_node	*aptr;
	// t_node	*next;
	int *seq;
	int	z;
	int	y;
	// int	maxindb;

	if (a->head->nb > a->head->next->nb)
		ft_sa(a);
	seq = ft_findsequence(a);
	if (!seq)
		return ("Error");
	while (ft_lstsize(a->head) != arrlen(seq)) //PB all but sequence
	{
		while (ft_isseq(seq, a->head->index))
		{
			z = 0;
			y = 0;
			if (ft_checksort(a) && !b->head)
				return ("");
			// if (b->head)
			// 	maxindb = ft_maxind(b);
			if (b->head && b->head->next)
			{
				z = seq[0] - b->head->index;
				y = seq[0] - b->head->next->index;
			
				if (z < 0)
					z = -z;
				if (y < 0)
					y = -y;
			}
			if (z > y)
				ft_rr(a,b);
			else
				ft_ra(a);
		}
			ft_pb(a, b);
	}
	free(seq);
	while (b->head) //get ptr to PA and rb or rrb 
	{
		if (b->head->next)
			ptr = ft_nextpush(a, b);
		else if (!b->head->next)
			ptr = b->head;
		aptr = getaptr(a, ptr);
		while(b->head != ptr)
		{
			if (ft_findnext(ptr->index, ptr->index, b))
			{
				if (ft_findnext(aptr->index, aptr->index, a) && a->head != aptr)
					ft_rr(a,b); 
				else
					ft_rb(b);
			}
			else
			{
				if (!ft_findnext(aptr->index, aptr->index, a) && a->head != aptr)
					ft_rrr(a,b);
				else
					ft_rrb(b);
			}
		}
		while (a->head != aptr) //ra or rra to insert ptr
		{
			if (ft_findnext(aptr->index, aptr->index, a))
				ft_ra(a);
			else
				ft_rra(a);
		}
		ft_pa(b, a);
	}
	// ft_printlist(a,b);
	while (a->head->index != 0) //LASTrotate or rev rotate dependeing on 0 idnex position in list. make ind 0 - head a
	{
		if (ft_findnext(0, 0, a))
			ft_ra(a);
		else
			ft_rra(a);
	}
		// ft_printlist(a, b);
	return("");
}