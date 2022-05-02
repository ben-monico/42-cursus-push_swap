/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_algorithm2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:22:13 by bcarreir          #+#    #+#             */
/*   Updated: 2022/04/28 19:00:40 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	arrlen(int *arr, int size)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	if (arr[size - 1] == -1)
	{
		i++; // cause of index 0
		while (arr[i])
			i++;
	}
	return (i);
}

int	ft_isseq(int *arr, int index, int size)
{
	int	i;

	i = 0;
	while (i < arrlen(arr, size))
	{
		if (index ==  arr[i])
			return (1);
		i++;
	}
	return (0);
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

int	ft_minind(t_stack *stack)
{
	t_node	*aptr;
	int		minindex;

	if (!stack->head->next)
		return(stack->head->index);
	aptr = stack->head;
	minindex = aptr->index;
	while (aptr)
	{
		if (aptr->index < minindex)
			minindex = aptr->index;
		aptr = aptr->next;
	}
	return (minindex);
}

t_node	*ft_findnextmin(t_node *ptr)
{
	t_node	*nextmin;
	int		min;

	min = ptr->index;
	nextmin = ptr;
	while (ptr)
	{
		if (ptr->index < min)
		{
			min = ptr->index;
			nextmin = ptr;
		}
		ptr = ptr->next;
	}
	return (nextmin);
}

int	ft_nbrs_nbtwn(t_stack *stack, int min, int prvidx, int nxtidx)
{
	t_node	*pp;
	int		c;

	if (prvidx == 0)
		return (0);
	c = 0;
	pp = ft_get_node(stack, prvidx)->next;
	while (pp->index != nxtidx)
	{
		if (pp->index > min)
		{
			min = pp->index;
			c++;
		}
		pp = pp->next;
	}
	if (c >= 2)
		return (1);
	return (0);
}

int	*ft_findsequence2(t_stack *a) // best, missing arrlen
{
	t_node	*ptr;
	t_node	*start;
	int	*best;
	int	*cur;
	int	i;
	int	z;

	z = 0;

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
			if (ptr->index > cur[i - 1])
			{
				cur[i] = ptr->index;
				if (i >= 2)
				{
					if (ft_nbrs_nbtwn(a, cur[i - 2], cur[i - 1], cur[i])) //add bool for continue outer loop
					{
						i--;
						ptr = ft_get_node(a, cur[i])->next;
						continue ;
					}
				}
				i++;
			}
			ptr = ptr->next;
		}
		if (arrlen(best, a->size) < arrlen(cur, a->size))
		{
			ft_memcpy(best, cur, (sizeof(int) * a->size));
			best[a->size - 1] = 0;
		}
		ft_bzero(cur, sizeof(int) * a->size);
		cur[0] = start->index;
		ptr = start->next;
		i = 1;
		while (ptr)
		{

			if ((z == 0 && (ptr->index > cur[i - 1] || ptr->index == 0)) ||
				(z == 1 && ptr->index > cur[i - 1] && ptr->index < cur[0]))
			{
				if (ptr->index == 0)
				{
					best[a->size - 1] = -1;	
					z = 1;
				}
				cur[i] = ptr->index;
				if (i >= 2)
				{
					if (ft_nbrs_nbtwn(a, cur[i - 2], cur[i - 1], cur[i])) //add bool for continue outer loop
					{
						i--;
						ptr = ft_get_node(a, cur[i])->next;
						continue ;
					}
				}
				i++;
			}
			ptr = ptr->next;
		}
		if (arrlen(best, a->size) < arrlen(cur, a->size))
			ft_memcpy(best, cur, (sizeof(int) * a->size));
		ft_bzero(cur, sizeof(int) * a->size);
		start = start->next;
	}
	free (cur);
	return (best);
}

int	*ft_findsequence3(t_stack *a) //let it choose between having 0 or not
{
	t_node	*ptr;
	t_node	*start;
	int	*best;
	int	*cur;
	int	i;
	int	z;

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
			if (ptr->index > cur[i - 1])
			{
				cur[i] = ptr->index;
				i++;
			}
			ptr = ptr->next;
		}
		if (arrlen(best, a->size) < arrlen(cur, a->size))
			ft_memcpy(best, cur, (sizeof(int) * a->size));
		ft_bzero(cur, sizeof(int) * a->size);
		cur[0] = start->index;
		ptr = start->next;
		i = 1;
		z = 0;
		while (ptr)
		{
			if ((z == 0 && (ptr->index > cur[i - 1] || ptr->index == 0)) ||
				(z == 1 && ptr->index > cur[i - 1] && ptr->index < cur[0]))
			{
				if (ptr->index == 0)
					z = 1;
				cur[i] = ptr->index;
				i++;
			}
			ptr = ptr->next;
		}
		if (arrlen(best, a->size) < arrlen(cur, a->size))
			ft_memcpy(best, cur, (sizeof(int) * a->size));
		ft_bzero(cur, sizeof(int) * a->size);
		start = start->next;
	}
	free (cur);
	return (best);
}

int	*ft_findsequence(t_stack *a)
{
	t_node	*ptr;
	t_node	*start;
	int	*best;
	int	*cur;
	int	i;
	int	z;

	z = 0;

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
			if ((z == 0 && (ptr->index > cur[i - 1] || ptr->index == 0)) ||
				(z == 1 && ptr->index > cur[i - 1] && ptr->index < cur[0]))
			{
				if (ptr->index == 0)
					z = 1;
				cur[i] = ptr->index;
				i++;
			}
			ptr = ptr->next;
		}
		if (arrlen(best, a->size) < arrlen(cur, a->size))
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
	int	maxindex;
	int	minindex;

	maxindex = ft_maxind(a);
	minindex = ft_minind(a);
	if (bptr->index < minindex)
	{
		aptr = ft_get_node(a, minindex);
		return (aptr);
	}
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

t_node	*ft_get_next_unseq(t_stack *a, int *seq, int size)
{
	t_node	*ptrh;
	t_node	*ptrt;

	ptrh = a->head;
	ptrt = a->tail;
	while (ptrh && ptrt)
	{
		if (!ft_isseq(seq, ptrh->index, size))
			return (ptrh);
		if (!ft_isseq(seq, ptrt->index, size))
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
	int	size;
	size = a->size;

	seq = ft_findsequence2(a);
	if (!seq)
		return ("Error");
	while (ft_lstsize(a->head) != arrlen(seq, size)) //PB all but sequence
	{
		while (ft_isseq(seq, a->head->index, size))
		{
			if (ft_checksort(a) && !b->head)
				return ("");
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