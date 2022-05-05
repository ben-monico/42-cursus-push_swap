/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sequence.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:33:56 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/05 14:23:52 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_nbrs_nbtwn(t_stack *stack, int min, int ind, int max)
{
	t_node	*ptr;
	int		c;

	c = 0;
	if (ft_get_node(stack, ind) == stack->tail)
		ptr = stack->head;
	else
		ptr = ft_get_node(stack, ind)->next;
	while (ptr->index != max)
	{
		if (ptr->index > min && ptr->index < max)
		{
			min = ptr->index;
			c++;
		}
		if (ptr == stack->tail)
			ptr = stack->head;
		else
			ptr = ptr->next;
	}
	if (c >= 2)
		return (1);
	return (0);
}

static t_node	*ft_continueloop(int i, t_stack *a, int *cur, t_node *ptr)
{
	if (i >= 2)
	{
		if (ft_nbrs_nbtwn(a, cur[i - 2], cur[i - 1], cur[i]))
		{
			i--;
			if (ft_get_node(a, cur[i]) == a->tail)
				ptr = a->head;
			else
				ptr = ft_get_node(a, cur[i])->next;
			return (ptr);
		}
	}
	return (NULL);
}

static int	*ft_get_seq(t_stack *a, int *cur, t_node *s, t_node *ptr)
{
	t_node	*aux;
	int		i;

	i = 1;
	while (ptr != s)
	{
		if (ptr->index > cur[i - 1])
		{
			cur[i] = ptr->index;
			aux = ft_continueloop(i, a, cur, ptr);
			if (aux)
			{
				ptr = aux;
				i--;
				continue ;
			}
			i++;
		}
		if (ptr == a->tail)
			ptr = a->head;
		else
			ptr = ptr->next;
	}
	return (cur);
}

static void	ft_compare_clean_arr(int *best, int *cur, t_stack *a)
{
	if (arrlen(best) < arrlen(cur))
		ft_memcpy(best, cur, (sizeof(int) * a->size + 1));
	ft_bzero(cur, sizeof(int) * (a->size + 1));
	return ;
}

int	*ft_findsequence(t_stack *a, t_node *start)
{
	t_node	*ptr;
	int		*best;
	int		*cur;

	best = (int *)ft_calloc(a->size + 1, sizeof(int));
	cur = (int *)ft_calloc(a->size + 1, sizeof(int));
	if (!cur || !best)
		return (NULL);
	while (start)
	{
		cur[0] = start->index;
		if (start == a->tail)
			ptr = a->head;
		else
			ptr = start->next;
		ft_get_seq(a, cur, start, ptr);
		ft_compare_clean_arr(best, cur, a);
		start = start->next;
	}
	free (cur);
	return (best);
}
