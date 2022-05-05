/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utils_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:31:13 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/05 14:45:55 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_circsort(t_stack *a)
{
	t_node	*ptr;
	int		max;
	int		min;

	ptr = a->head;
	max = ft_maxind(a);
	min = ft_minind(a);
	while (ptr)
	{
		if (ptr->next && ptr->index == max && ptr->next->index != min)
			return (0);
		else if (ptr->next)
		{	
			if (ptr->index != max && ptr->index > ptr->next->index)
				return (0);
		}
		else if (ptr == a->tail && ptr->index > a->head->index)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	ft_maxind(t_stack *stack)
{
	t_node	*aptr;
	int		maxindex;

	if (!stack->head->next)
		return (stack->head->index);
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
		return (stack->head->index);
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

int	arrlen(int *arr)
{
	int	i;

	i = 0;
	if (arr[0] == 0 && arr[1])
		i++;
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
		if (index == arr[i])
			return (1);
		i++;
	}
	return (0);
}
