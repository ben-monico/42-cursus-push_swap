/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:07:52 by bcarreir          #+#    #+#             */
/*   Updated: 2022/04/12 14:25:13 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *ft_split_to_stack(int argc, char **argv)
{
	t_node	*node;
	t_node	*head;
	char	**str;
	int		i;

	str = NULL;
	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (!str)
			return (NULL);
		if (!ft_strvalid(str))
		{
			ft_free(str);
			return (NULL);
		}
		node = ft_atoiton(str);
		if (!node)
			return (NULL);
		ft_free(str);
		i++;
	}
	head = ft_find_head(node);
	return (head);
}

static int	ft_wordcount(char const *s, char c)
{
	int	wc;

	wc = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		while (*s != c && *s)
			s++;
		wc++;
	}
	return (wc);
}

static void	*ft_dealmem(char **a, int j, char const *str, char c)
{
	char	**b;
	int		cc;

	b = a;
	cc = 0;
	while (*str && *str != c)
	{
		str++;
		cc++;
	}
	b[j] = (char *)malloc(sizeof(char) * (cc + 1));
	if (!b[j])
	{
		while (j--)
			free(b[j]);
		free(b);
		return (NULL);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		j;
	int		k;
	int		wc;

	if (!s)
		return (NULL);
	wc = ft_wordcount(s, c);
	a = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!a)
		return (NULL);
	j = 0;
	while (j != wc)
	{
		while (c == *s && *s)
			s++;
		ft_dealmem(a, j, s, c);
		k = 0;
		while (*s && c != *s)
			a[j][k++] = (char)*s++;
		a[j][k] = '\0';
		j++;
	}
	a[j] = NULL;
	return (a);
}
