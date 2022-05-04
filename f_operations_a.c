/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_operations_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:41:14 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/04 13:26:19 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node *node)
{
	int	aux;
	int	aux2;

	if (!node || !node->next)
		return;
	aux = node->nb;
	aux2 = node->index;
	node->nb = node->next->nb;
	node->index = node->next->index;
	node->next->nb = aux;
	node->next->index = aux2;
}

void	ft_push(t_stack *stack, t_stack *stackaux)
{
	t_node *aux;
	if (!stack->head)
		return;
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
	t_node *aux;

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
	t_node *aux;

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

void	ft_sb(t_stack *b_stack)
{
	ft_putstr("sb\n");
	ft_swap(b_stack->head);
}

void	ft_ss(t_stack *a_stack, t_stack *b_stack)
{
	ft_putstr("ss\n");
	ft_sa(a_stack);
	ft_sb(b_stack);
}

void	ft_pa(t_stack *b_stack, t_stack *a_stack)
{
	ft_putstr("pa\n");
	ft_push(b_stack, a_stack);
}

void	ft_pb(t_stack *a_stack, t_stack *b_stack)
{
	ft_putstr("pb\n");
	ft_push(a_stack, b_stack);
}

void	ft_ra(t_stack *a_stack)
{
	ft_putstr("ra\n");
	ft_rotation(a_stack);
}

void	ft_rb(t_stack *b_stack)
{
	ft_putstr("rb\n");
	ft_rotation(b_stack);
}

void	ft_rr(t_stack *a_stack, t_stack *b_stack)
{
	ft_putstr("rr\n");
	ft_rotation(a_stack);
	ft_rotation(b_stack);
}

void	ft_rra(t_stack *a_stack)
{
	ft_putstr("rra\n");
	ft_rev_rotation(a_stack);
}

void	ft_rrb(t_stack *b_stack)
{
	ft_putstr("rrb\n");
	ft_rev_rotation(b_stack);
}

void	ft_rrr(t_stack *a_stack, t_stack *b_stack)
{
	ft_putstr("rrr\n");
	ft_rev_rotation(a_stack);
	ft_rev_rotation(b_stack);
}


// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.