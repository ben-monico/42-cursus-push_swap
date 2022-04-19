/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:10:26 by bcarreir          #+#    #+#             */
/*   Updated: 2022/04/18 18:02:56 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algorithm(t_stack *a, t_stack *b)
{
	// ft_putstr("| Init stacks |\n");
	// ft_printlist(a, b);
	ft_setindex(a);
	ft_algo2(a, b);
	ft_sort(a, b);
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