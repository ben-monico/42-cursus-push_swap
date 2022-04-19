/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_parse_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:12:28 by bcarreir          #+#    #+#             */
/*   Updated: 2022/04/18 16:19:26 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//review situations longer and smaller than max int. use strcmp, care for leading zeros
int	ft_parse_args(t_stack *a, int argc, char **argv) 
{
	a->head = ft_split_to_stack(argc, argv);
	if (!a->head)
		return (0);
	if (ft_dup_check(a->head))
	{
		ft_lstclear(&a->head);   
		return (0);
	}
	a->size = ft_lstsize(a->head);
	a->tail = ft_find_tail(a->head);
	return (1);
}

int	ft_strvalid(char **str)
{
	int	j;
	int	i;

	j = 0;
	while (str[j])
	{
		i = 0;
		if (str[j][0] == '+' || str[j][0] == '-')
			i++;
		if (!ft_isdigit(str[j][i]))
			return (0);
		while (str[j][i])
		{
			if (!ft_isdigit(str[j][i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

t_node *ft_atoiton(char **str)
{
	static t_node	*tmp2;
	t_node			*tmp;
	long			res;
	int				j;

	j = 0;
	while (str[j])
	{
		res = ft_atoi(str[j]);
		if (res > 2147483647 || res < -2147483648)
			return (NULL);
		tmp = ft_initnode(res);
		if (tmp2)
			tmp2->next = tmp;
		tmp->prev = tmp2;
		tmp2 = tmp;
		j++;
	}
	return (tmp);
}

int	ft_free(char **str)
{
	int	j;

	j = 0;
	while(str[j])
	{
		free(str[j]);
		j++;
	}
	free(str);
	str = NULL;
	return (1);
}

int	ft_dup_check(t_node *ptr)
{
	t_node	*aux;

	while (ptr != NULL)
	{
		aux = ptr->next;
		while (aux != NULL)
		{
			if (aux->nb == ptr->nb)
				return (1);
			aux = aux->next;
		}
		ptr = ptr->next;
	}
	return (0);
}