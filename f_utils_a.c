/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utils_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:05:28 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/04 18:41:17 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *stack)
{
	t_node	*ptr;
	int		lstsize;

	lstsize = 0;
	ptr = stack->head;
	while (ptr)
	{
		lstsize++;
		ptr = ptr->next;
	}
	return (lstsize);
}

void	ft_printlist(t_stack *a, t_stack *b)
{
	t_node	*aptr;
	t_node	*bptr;

	aptr = a->head;
	bptr = b->head;
	ft_putstr("__________\nA	B\n----------\n");
	while (aptr || bptr)
	{
		if (aptr)
			ft_putnbr(aptr->nb);
		ft_putstr("	");
		if (bptr)
			ft_putnbr(bptr->nb);
		ft_putstr("\n");
		if (aptr)
			aptr = aptr->next;
		if (bptr)
			bptr = bptr->next;
	}
	ft_putstr("__________\n");
	return ;
}

int	ft_checksort(t_stack *stack)
{
	t_node	*ptr;

	ptr = stack->head;
	while (ptr)
	{
		if (ptr->next && ptr->nb > ptr->next->nb)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

t_node	*ft_get_node(t_stack *stack, int ind)
{
	t_node	*ptr;

	ptr = stack->head;
	while (ptr->index != ind)
	{
		ptr = ptr->next;
	}
	return (ptr);
}
