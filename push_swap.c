/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmonico <benmonico@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:10:26 by bcarreir          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/04/12 19:57:43 by bcarreir         ###   ########.fr       */
=======
/*   Updated: 2022/04/13 04:01:14 by benmonico        ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// list to array. index array. push to list when they are the next index

int	*ft_findnext(int	mindex, int maxindex, t_stack *bstk) // find cheapest next index to push
{
	t_node *ptr;
	int	r;
	int	rr;

	r = 0;
	ptr = bstk->head;
	while (ptr && (ptr->index != mindex + 1 || ptr->index != maxindex))
	{
		r++;
		ptr = ptr->next;
	}
	rr = 0;
	ptr = bstk->tail;
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
	t_node	*bptr;
	int		mindex;
	int		maxindex;

	mindex = 0;
	ptr = astk->head;
	maxindex = ptr->index;
	//iterate back and forth to find biggest sequence including 0. push all except those
	//find cheapest next to push and ra or rra	
	while (ptr || (ptr->index == 0 && mindex > 0)) //push to b except for sequenced indexs.
	{
		if (ptr->index == mindex)
		{
			ft_ra(astk);
			mindex++;
		}
		else
			ft_pb(astk, bstk);
		if (ptr->index > maxindex)
			maxindex = ptr->index;
		ptr = ptr->next;
	}
	while (bstk->head) //rotate or rev rotate stack b depending on next index returned
	{
		bptr = bstk->head;
		if (ft_findnext(mindex, maxindex, bstk)) // rotate until next
			while (bptr && (bptr->index != mindex + 1 || bptr->index != maxindex))
				ft_rb(bstk);
		else //rev rotate until next
		{
			bptr = bstk->tail;
			while (bptr && (bptr->index != mindex + 1 || bptr->index != maxindex))
				ft_rrb(bstk);
		}
		ft_pa(bstk, astk);
		if (astk->head == mindex + 1)
		{
			ft_ra(astk); //check if findnext in b is worth doing rr
			mindex++;
		}
		else
			maxindex--;
	}
	while (astk->head->index != 0) //rotate or rev rotate dependeing on 0 idnex position in list. make ind 0 - head astk
	{
		
	}
	return ;
}

void	ft_algorithm(t_stack *astk, t_stack *bstk)
{
	astk->tail = ft_find_tail(astk->head);
	ft_putstr("| Init stacks |\n");
	ft_printlist(astk, bstk);
	ft_putnbr(astk->size);
	ft_putstr(" = ps.a size\n");
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
 	// system("leaks -- a.out");
}