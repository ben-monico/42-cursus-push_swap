/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utils_list_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:05:28 by bcarreir          #+#    #+#             */
/*   Updated: 2022/04/20 17:20:31 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_node *ptr)
{
	int	lstsize;
	
	lstsize = 0;
	ptr = ft_find_head(ptr);
	while (ptr)
	{
		lstsize++;
		ptr = ptr->next;
	}
	return (lstsize);
}

void	ft_printlist(t_stack *a, t_stack *b)
{
	t_node *aptr;
	t_node *bptr;

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

t_node	*ft_find_index(t_node *ptr, int ind)
{
	ptr = ft_find_head(ptr);
	while (ptr->index != ind)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

void	ft_setindex(t_stack *stack)
{
	t_node *ptr;
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * (stack->size));
	if (!arr)
		return ;
	ptr = stack->head;
	i = 0;
	while (ptr)
	{
		arr[i] = ptr->nb;
		ptr = ptr->next;
		i++;
	}
	//
	// ft_putstr("array: ");
	// i = 0;
	// while (i < stack->size)
	// {
	// 	ft_putnbr(arr[i]);
	// 	i++;
	// }
	//
	i = 0;
	while (i < stack->size)
	{
		if (i < stack->size - 1 && arr[i] > arr[i + 1])
		{
			ft_swap_int(&arr[i], &arr[i + 1]);
			i = 0;
			continue;
		}
		i++;
	}
	//
	// ft_putstr("\n sorted array: ");
	// i = 0;
	// while (i < stack->size)
	// {
	// 	ft_putnbr(arr[i]);
	// 	i++;
	// }
	// ft_putstr("\nindexs: ");
	// ptr = stack->head;
	// while (ptr)
	// {
	// 	ft_putnbr(ptr->index);
	// 	ptr = ptr->next;
	// }
	//
	ptr = stack->head;
	while (ptr)
	{
		i = 0;
		while (arr[i] != ptr->nb)
			i++;
		ptr->index = i;
		ptr = ptr->next;
	}
	//
	// ft_putstr("\nindexs sorted: ");
	// ptr = stack->head;
	// while (ptr)
	// {
	// 	ft_putnbr(ptr->index);
	// 	ptr = ptr->next;
	// }
	//
	return ;
}