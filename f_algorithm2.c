/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_algorithm2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:22:13 by bcarreir          #+#    #+#             */
/*   Updated: 2022/04/19 19:25:42 by bcarreir         ###   ########.fr       */
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

t_node	*getaptr(t_stack *a, t_node *bptr)
{
	t_node *aptr;

	if (!a->head->next)
		return (a->head);
	if (bptr->index > a->tail->index && bptr->index < a->head->index)
		return (a->head);
	aptr = a->head;
	while (aptr)
	{
		if (aptr->prev)
			if (!aptr->next || (aptr->index > bptr->index && aptr->prev->index < bptr->index))
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
		// write (1, "aptr\n", 5);
		aptr = getaptr(a, bptr);
				// write (1, "c", 1);
		bcounter = ft_nodecounter(b, bptr, ft_findnext(bptr->index, bptr->index, b));
				// write (1, "f", 1);
		acounter = ft_nodecounter(a, aptr, ft_findnext(aptr->index, aptr->index, a));
				// write (1, "d", 1);
		if (acounter + bcounter < cheap || cheap == -1)
		{
			cheap = acounter + bcounter;
			chpptr = bptr;
		}
				// write (1, "g", 1);
		bptr = bptr->next;
				// write (1, "nexted\n", 7);
	}
				// write (1, "success", 7);
	return (chpptr);
}

char	*ft_algo2(t_stack *a, t_stack *b)
{
	int *seq;
	t_node	*ptr;
	t_node	*aptr;
	int i;

	i = 0;
	seq = ft_findsequence(a);
	if (!seq)
		return ("Error");

	while (ft_lstsize(a->head) != arrlen(seq)) //PB all but sequence
	{
		if (ft_isseq(seq, a->head->index))
			ft_ra(a);
		else
			ft_pb(a, b);
	}
		// write (1, "y", 1);
	while (b->head)
	{
		// write (1, "b", 1);
		if (b->head->next)
		{
			// write (1, "\ngonp\n", 6);
			ptr = ft_nextpush(a, b);
			// write (1, "\nexitnp\n", 8);
		}
		else if (!b->head->next)
		{
			ptr = b->head;
		}
			// write (1, "z", 1);
		aptr = getaptr(a, ptr);
		while(b->head != ptr)
		{
			if (ft_findnext(ptr->index, ptr->index, b))
				ft_rb(b);
			else
				ft_rrb(b);
		}
		while (a->head != aptr)
		{
			if (ft_findnext(aptr->index, aptr->index, a))
				ft_ra(a);
			else
				ft_rra(a);
		}
		ft_pa(b, a);
	}
	// ft_printlist(a,b);
	while (a->head->index != 0) //rotate or rev rotate dependeing on 0 idnex position in list. make ind 0 - head a
	{
		if (ft_findnext(0, 0, a))
			ft_ra(a);
		else
			ft_rra(a);
	}
		// ft_printlist(a, b);
	return("");
}