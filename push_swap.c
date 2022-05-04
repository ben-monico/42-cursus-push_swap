/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:10:26 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/04 16:17:11 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *a, t_stack *b);

int main(int argc, char **argv)
{
	t_ps	ps;

	ps.a = ft_initstack(0);
	ps.b = ft_initstack(0);
	if (argc == 1 || !ps.a || !ps.b || !ft_parse_args(ps.a, argc, argv))
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
 	// system("leaks -- push_swap");
	return (0);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	ft_setindex(a);
	ft_algorithm(a, b);
	return ;
}
