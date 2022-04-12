/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_operations_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmonico <benmonico@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:41:14 by bcarreir          #+#    #+#             */
/*   Updated: 2022/04/09 00:43:27 by benmonico        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node *node)
{
	int	aux;

	if (!node || node->next == NULL)
		return;
	aux = node->nb;
	node->nb = node->next->nb;
	node->next->nb = aux;
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
	aux->next = stackaux->head;
	stackaux->head = aux;
	if (stackaux->head->next)
		stackaux->head->next->prev = stackaux->head;
	else
		stackaux->head->next = NULL;
}

void	ft_rotation(t_stack *stack)
{
	t_node *aux;

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
	stack->head->prev = stack->tail;
	stack->tail->prev = NULL;
	stack->tail->next = stack->head;
	stack->head = stack->tail;
	stack->tail = aux;
	stack->tail->next = NULL;
}

void	ft_sa(t_stack *a_stack)
{
	ft_swap(a_stack->head);
	ft_putstr("sa\n");
}

void	ft_sb(t_stack *b_stack)
{
	ft_swap(b_stack->head);
	ft_putstr("sb\n");
}

void	ft_ss(t_stack *a_stack, t_stack *b_stack)
{
	ft_sa(a_stack);
	ft_sb(b_stack);
	ft_putstr("ss\n");
}

void	ft_pa(t_stack *b_stack, t_stack *a_stack)
{
	ft_push(b_stack, a_stack);
	ft_putstr("pa\n");
}

void	ft_pb(t_stack *a_stack, t_stack *b_stack)
{
	ft_push(a_stack, b_stack);
	ft_putstr("pb\n");
}

void	ft_ra(t_stack *a_stack)
{
	ft_rotation(a_stack);
	ft_putstr("ra\n");
}

void	ft_rb(t_stack *b_stack)
{
	ft_rotation(b_stack);
	ft_putstr("rb\n");
}

void	ft_rr(t_stack *a_stack, t_stack *b_stack)
{
	ft_ra(a_stack);
	ft_rb(b_stack);
	ft_putstr("rr\n");
}

void	ft_rra(t_stack *a_stack)
{
	ft_rev_rotation(a_stack);
	ft_putstr("rra\n");
}

void	ft_rrb(t_stack *b_stack)
{
	ft_rev_rotation(b_stack);
	ft_putstr("rrb\n");
}

void	ft_rrr(t_stack *a_stack, t_stack *b_stack)
{
	ft_rev_rotation(a_stack);
	ft_rev_rotation(b_stack);
	ft_putstr("rrr\n");
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