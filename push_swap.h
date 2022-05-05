/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:57:03 by bcarreir          #+#    #+#             */
/*   Updated: 2022/05/04 18:55:32 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node {
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
	int				nb;
}	t_node;

typedef struct s_stack
{
	t_node		*head;
	t_node		*tail;
	int			size;
}	t_stack;

typedef struct s_pushswap
{
	t_stack	*a;
	t_stack	*b;
}	t_ps;

int		ft_algorithm(t_stack *a, t_stack *b);
int		arrlen(int *arr);
long	ft_atoi(const char *str);
t_node	*ft_atoiton(char **str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_checksort(t_stack *stack);
int		ft_circsort(t_stack *a);
int		ft_dup_check(t_node *ptr);
t_node	*ft_find_head(t_node *ptr);
int		*ft_findsequence(t_stack *a, t_node *start);
void	ft_fix_offset(t_stack *a);
t_node	*getaptr(t_stack *a, t_node *bptr);
t_node	*ft_get_cheapest(t_stack *a, t_stack *b, t_node *bptr);
t_node	*ft_get_node(t_stack *stack, int ind);
int		ft_get_rotdir(int index, t_stack *stack);
t_node	*ft_find_tail(t_node *ptr);
int		ft_free(char **str);
t_node	*ft_initnode(int i);
t_stack	*ft_initstack(int size);
int		ft_isdigit(int c);
int		ft_isseq(int *arr, int index);
void	ft_lstclear(t_node **lst);
int		ft_lstsize(t_stack *stack);
int		ft_maxind(t_stack *stack);
int		ft_minind(t_stack *stack);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_parse_args(t_stack *a, int argc, char **argv);
void	ft_printlist(t_stack *a, t_stack *b);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
int		ft_setindex(t_stack *stack);
void	ft_smol_algo(t_stack *a, t_stack *b);
void	ft_sort(t_stack *a, t_stack *b);
char	**ft_split(char const *s, char c);
t_node	*ft_split_to_stack(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strvalid(char **str);
void	ft_swap_int(int *a, int *b);

void	ft_push(t_stack *stack, t_stack *stackaux);
void	ft_rev_rotation(t_stack *stack);
void	ft_rotation(t_stack *stack);
void	ft_swap(t_node *node);

void	ft_sa(t_stack *a_stack);
void	ft_sb(t_stack *b_stack);
void	ft_ss(t_stack *a_stack, t_stack *b_stack);
void	ft_pa(t_stack *b_stack, t_stack *a_stack);
void	ft_pb(t_stack *a_stack, t_stack *b_stack);
void	ft_ra(t_stack *a_stack);
void	ft_rb(t_stack *b_stack);
void	ft_rr(t_stack *a_stack, t_stack *b_stack);
void	ft_rra(t_stack *a_stack);
void	ft_rrb(t_stack *b_stack);
void	ft_rrr(t_stack *a_stack, t_stack *b_stack);

#endif