/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:10:26 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/05 15:06:47 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	if (!ft_setindex(a) || !ft_algorithm(a, b))
		ft_putstr("Error\n");
	return ;
}

void	ft_fill_qsort_arr(int *arr, t_stack *stack, t_node *ptr)
{
	int	i;

	ptr = stack->head;
	i = 0;
	while (ptr)
	{
		arr[i] = ptr->nb;
		ptr = ptr->next;
		i++;
	}
	i = 0;
	while (i < stack->size)
	{
		if (i < stack->size - 1 && arr[i] > arr[i + 1])
		{
			ft_swap_int(&arr[i], &arr[i + 1]);
			i = 0;
			continue ;
		}
		i++;
	}
	return ;
}

int	ft_setindex(t_stack *stack)
{
	t_node	*ptr;
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * (stack->size));
	if (!arr)
		return (0);
	ptr = stack->head;
	ft_fill_qsort_arr(arr, stack, ptr);
	while (ptr)
	{
		i = 0;
		while (arr[i] != ptr->nb)
			i++;
		ptr->index = i;
		ptr = ptr->next;
	}
	free(arr);
	return (1);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc == 1)
		return (0);
	ps.a = ft_initstack(0);
	ps.b = ft_initstack(0);
	if (!ps.a || !ps.b || !ft_parse_args(ps.a, argc, argv))
	{
		ft_putstr("Error\n");
		if (ps.a)
			free(ps.a);
		if (ps.b)
			free(ps.b);
		return (0);
	}
	if (ft_checksort(ps.a) || !ps.a->head->next)
		return (0);
	ft_sort(ps.a, ps.b);
	ft_lstclear(&ps.a->head);
	free(ps.a);
	free(ps.b);
	return (0);
}
