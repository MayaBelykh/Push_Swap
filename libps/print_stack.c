/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 21:10:57 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/05 20:07:26 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_op_ps(int op, int ps_or_ch)
{
	if (ps_or_ch == CH)
		return ;
	if (op == RR || op == SS)
		write(1, op == RR ? "rr\n" : "ss\n", 3);
	else if (op == SA || op == SB)
		write(1, op == SA ? "sa\n" : "sb\n", 3);
	else if (op == PA || op == PB)
		write(1, op == PA ? "pa\n" : "pb\n", 3);
	else if (op == RA || op == RB)
		write(1, op == RA ? "ra\n" : "rb\n", 3);
	else if (op == RRR)
		write(1, "rrr\n", 4);
	else if (op == RRA || op == RRB)
		write(1, op == RRA ? "rra\n" : "rrb\n", 4);
}

void	print_sort_stack(int64_t *sort_num, int size)
{
	int		i;

	write(1, "\033[0;32mSort stack:\033[0m\n", 24);
	i = -1;
	while (++i < size)
		ft_printf("[%d] %lld\n", i, sort_num[i]);
	write(1, "\n", 1);
}

void	print_op(t_node *node)
{
	int		nu_op;
	int		op;
	int		rx;
	int		rrx;

	nu_op = node->sum_op_up;
	op = node->up;
	rx = node->rx;
	rrx = node->rrx;
	if (op == NO || op == SS)
		ft_printf("[up: %d %s]", nu_op, op == NO ? "NO" : "SS");
	else if (op == SA || op == SB)
		ft_printf("[up: %d %s]", nu_op, op == SA ? "SA" : "SB");
	else if (op == PA || op == PB)
		ft_printf("[up: %d %s]", nu_op, op == PA ? "PA" : "PB");
	else if (op == RA || op == RB)
		ft_printf("[up: %d %s]", nu_op, op == RA ? "RA" : "RB");
	else if (op == RR || op == RRR)
		ft_printf("[up: %d %s]", nu_op, op == RR ? "RR" : "RRR");
	else if (op == RRA || op == RRB)
		ft_printf("[up: %d %s]", nu_op, op == RRA ? "RRA" : "RRB");
	ft_printf("[sx %d][rx %d][rrx %d][ss %d][rr %d][rrr %d][n_rx %d][n_rrx %d]\
	[sum %d]", node->sx, rx, rrx, node->ss, node->rr, node->rrr, node->neib_rx,
	node->neib_rrx, node->sum_ops);
}

int		print_stack(t_stack *stack, int size, char name)
{
	int		i;
	t_node	*start;

	i = -1;
	if (stack->size)
	{
		start = stack->start;
		ft_printf("\033[0;32mStack %c\033[0m\n", name);
		while (++i < size)
		{
			ft_printf("[%lld][sort: %d][neib: %d]", start->pos, start->pos_sort,
													start->pos_neib);
			print_op(start);
			ft_printf(" %d\n", start->value);
			start = start->next;
		}
		ft_printf("\n");
	}
	return (END);
}

void	print(t_stack *a, t_stack *b, int code)
{
	if (code == A || code == B)
		print_stack(code == A ? a : b, code == A ? a->size : b->size,
					code == A ? 'a' : 'b');
	else if (code == BOTH)
	{
		print_stack(a, a->size, 'a');
		print_stack(b, b->size, 'b');
	}
}
