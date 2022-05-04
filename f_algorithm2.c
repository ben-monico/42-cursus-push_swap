/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_algorithm2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:22:13 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/04 16:48:14 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	ft_nodecounter(t_stack *stack, t_node *ptr, int i)
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

t_node	*ft_get_cheapest(t_stack *a, t_stack *b, t_node *bptr)
{
	t_node 	*aptr;
	t_node	*chpptr;
	int		bcounter;
	int		acounter;
	int		cheap;

	bcounter = 0;
	acounter = 0;
	cheap = -1;
	chpptr = bptr;
	while (bptr)
	{
		aptr = getaptr(a, bptr);
		bcounter = ft_nodecounter(b, bptr, ft_get_rotdir(bptr->index, b));
		acounter = ft_nodecounter(a, aptr, ft_get_rotdir(aptr->index, a));
		if (acounter + bcounter < cheap || cheap == -1)
		{
			cheap = acounter + bcounter;
			chpptr = bptr;
		}
		bptr = bptr->next;
	}
	return (chpptr);
}
