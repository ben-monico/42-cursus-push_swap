/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:10:26 by bcarreir          #+#    #+#             */
/*   Updated: 2022/04/13 19:27:02 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// list to array. index array. push to list when they are the next index

int	ft_circsort(t_stack *astk, int mindex, int maxindex)
{
	t_node *ptr;

	ptr = astk->head;
	while (ptr)
	{
		if (ptr->index > mindex && ptr->index < maxindex)
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
	ptr = stack->head;
	while (ptr && (ptr->index != mindex + 1 || ptr->index != maxindex))
	{
		r++;
		ptr = ptr->next;
	}
	rr = 0;
	ptr = stack->tail;
	while (ptr && (ptr->index != mindex + 1 || ptr->index != maxindex))
	{
		rr++;
		ptr = ptr->prev;
	}
	if (r < rr)
		return (1); //rot
	return (0);		//rev rot
}

void	ft_sort(t_stack *astk, t_stack *bstk)
{
	t_node	*ptr;
	int		mindex;
	int		maxindex;

	mindex = 0;
	maxindex = astk->size - 1;

	//iterate back and forth to find biggest sequence including 0. push all except those
	//find cheapest next to push and ra or rra	
	ptr = ft_find_index(astk->head, 0);
	while (ptr) //push to b except for sequenced indexs.
	{
		if (ptr->index == mindex + 1)
			mindex++;
		ptr = ptr->next;
	}
	ptr = ft_find_index(astk->head, 0);
	maxindex++;
	while (ptr) //push to b except for sequenced indexs.
	{
		if (ptr->index == maxindex - 1)
			maxindex--;
		ptr = ptr->prev;
	}
	if (maxindex == astk->size)
		maxindex--;
	while (!ft_circsort(astk, mindex, maxindex)) //push to b except for sequenced indexs.
	{
		if (astk->head->index >= maxindex || astk->head->index <= mindex)
			ft_ra(astk);
		else
			ft_pb(astk, bstk);
	// ft_printlist(astk, bstk);
	}
	while (astk->head->index != maxindex)
	{
		if (ft_findnext(maxindex, maxindex, astk))
			ft_ra(astk);
		else
			ft_rra(astk);
	}
	// ft_printlist(astk, bstk);
	mindex++;
	maxindex--;
	while (bstk->head) //rotate or rev rotate stack b depending on next index returned
	{
		if (bstk->head->next && ft_findnext(mindex, maxindex, bstk)) // rotate until next
		{
			while (bstk->head->index != mindex && bstk->head->index != maxindex)
			{
				ft_rb(bstk);
				// ft_printlist(astk, bstk);
			}
		}
		else //rev rotate until next
		{
			while (bstk->head->index != mindex && bstk->head->index != maxindex)
			{
				ft_rrb(bstk);
				// ft_printlist(astk, bstk);
			}
		}
		ft_pa(bstk, astk);
		// ft_printlist(astk, bstk);
		if (astk->head->index == mindex)
		{
			ft_ra(astk); //check if findnext in b is worth doing rr
			// ft_printlist(astk, bstk);
			mindex++;
		}
		else
			maxindex--;
	}
	while (astk->head->index != 0) //rotate or rev rotate dependeing on 0 idnex position in list. make ind 0 - head astk
	{
		if (ft_findnext(0, 0, astk))
			ft_ra(astk);
		else
			ft_rra(astk);
		// ft_printlist(astk, bstk);
	}
	// ft_printlist(astk, bstk);
	return ;
}

void	ft_algorithm(t_stack *astk, t_stack *bstk)
{
	astk->tail = ft_find_tail(astk->head);
	// ft_putstr("| Init stacks |\n");
	// ft_printlist(astk, bstk);
	ft_setindex(astk);
	ft_sort(astk, bstk);
	return ;
}

int main(int argc, char **argv)
{
	t_ps	ps;

	if (argc == 1 || !(ps.a = ft_initstack(0)) || !(ps.b = ft_initstack(0)))
	{
		if (ps.a)
			free(ps.a);
		ft_putstr("Error\n");
		return (0);
	}	
	if (!(ft_parse_args(ps.a, argc, argv)))
	{
		ft_putstr("Parsing Error\n");
		free(ps.a);
		free(ps.b);
		return (0);
	}
	if (ft_checksort(ps.a) || !ps.a->head->next)
		return (0);
	ft_algorithm(ps.a, ps.b);
	ft_checksort(ps.a);
	return (0);
 	// system("leaks -- a.out");
}