/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_algorithm2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:22:13 by bcarreir          #+#    #+#             */
/*   Updated: 2022/04/18 18:26:29 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arrlen(int *arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	i++; // cause of 0
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

	best = (int *)ft_calloc(sizeof(int) * a->size);
	if (!best)
		return (NULL);
	cur = (int *)ft_calloc(sizeof(int) * a->size);
	if (!cur)
		return (NULL);
	i = 0;
	start = a->head;
	while (start)
	{
		cur[0] = start->index;
		ptr = start->next;
		i = 1;
		while (ptr)
		{
			if (ptr->index > cur[i - 1] || ptr->index == 0)
			{
				cur[i] = ptr->index;
				i++;
			}
			ptr = ptr->next;
		}
		if (arrlen(best) < arrlen(cur))
			ft_memcpy(best, cur, sizeof(int) * a->size);
		ft_bzero(cur, sizeof(int) * a->size);
		start = start->next;
	}
	free (cur);
	return (best);
}

void	ft_algo2(t_stack *a, t_stack *b)
{
	int *seq;

	seq = ft_findsequence(a);
	while (ft_lstsize(a) != arrlen(seq))
	{
		if (ft_isseq(seq, a->head->index))
			ft_ra(a);
		else
			ft_pb(a, b);
	}
	//add move counter to add b.head or b.tail to A.
}