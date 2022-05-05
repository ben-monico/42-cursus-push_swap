/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_operations_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:41:14 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/05 14:26:56 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node *node)
{
	int	aux;
	int	aux2;

	if (!node || !node->next)
		return ;
	aux = node->nb;
	aux2 = node->index;
	node->nb = node->next->nb;
	node->index = node->next->index;
	node->next->nb = aux;
	node->next->index = aux2;
}

void	ft_push(t_stack *stack, t_stack *stackaux)
{
	t_node	*aux;

	if (!stack->head)
		return ;
	aux = stack->head;
	if (stack->head->next)
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
	}
	else
		stack->head = NULL;
	if (stackaux->head)
	{
		aux->next = stackaux->head;
		stackaux->head->prev = aux;
	}
	else
		aux->next = NULL;
	stackaux->head = aux;
	stackaux->tail = ft_find_tail(stackaux->head);
}

void	ft_rotation(t_stack *stack)
{
	t_node	*aux;

	if (!stack->head->next)
		return ;
	aux = stack->head->next;
	aux->prev = NULL;
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->head->next = NULL;
	stack->tail = stack->head;
	stack->head = aux;
}

void	ft_rev_rotation(t_stack *stack)
{
	t_node	*aux;

	aux = stack->tail->prev;
	aux->next = NULL;
	stack->tail->next = stack->head;
	stack->tail->prev = NULL;
	stack->head->prev = stack->tail;
	stack->head = stack->tail;
	stack->tail = aux;
}

void	ft_sa(t_stack *a_stack)
{
	ft_putstr("sa\n");
	ft_swap(a_stack->head);
}
