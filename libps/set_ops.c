/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 21:34:14 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/05 19:11:47 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_up(t_stack *stack, t_node *node)
{
	int		pos;

	pos = node->pos;
	node->sum_op_up = pos <= stack->size / 2 ? pos : stack->size - pos;
	if (pos == 1)
		node->up = stack->name == 'a' ? SA : SB;
	else if (pos > stack->size / 2)
		node->up = stack->name == 'a' ? RRA : RRB;
	else if (pos > 1 && pos <= stack->size / 2)
		node->up = stack->name == 'a' ? RA : RB;
	else if (!pos)
		node->up = NO;
	node->sx = pos == 1 ? 1 : 0;
	node->rx = pos;
	node->rrx = stack->size - pos;
}

void	set_ops_exc(t_node *node, t_node *neib)
{
	if (node->rx < node->rrx)
		node->rrx = 0;
	else
		node->rx = 0;
	node->rr = 0;
	node->rrr = 0;
	if (neib->rx < neib->rrx)
	{
		node->neib_rrx = 0;
		node->neib_rx = neib->rx;
	}
	else
	{
		node->neib_rx = 0;
		node->neib_rrx = neib->rrx;
	}
}

void	set_ops_one(t_node *node, t_node *neib)
{
	int		rx;
	int		rrx;

	rx = node->rx;
	rrx = node->rrx;
	node->rr = ft_min(rx, neib->rx);
	node->rrr = ft_min(rrx, neib->rrx);
	node->min_with_rr = rx + neib->rx - node->rr + 1;
	node->min_with_rrr = rrx + neib->rrx - node->rrr + 1;
	node->sum_ops = ft_min(rx, rrx) + ft_min(neib->rx, neib->rrx) + 1;
}

void	set_ops(t_node *node, t_node *neib)
{
	int		min;

	set_ops_one(node, neib);
	min = ft_min_th(node->min_with_rr, node->min_with_rrr, node->sum_ops);
	if (min == node->sum_ops)
		set_ops_exc(node, neib);
	else if (min == node->min_with_rr)
	{
		node->rx -= node->rr;
		node->neib_rx = neib->rx - node->rr;
		node->rrx = 0;
		node->neib_rrx = 0;
		node->rrr = 0;
		node->sum_ops = node->min_with_rr;
	}
	else if (min == node->min_with_rrr)
	{
		node->rx = 0;
		node->neib_rx = 0;
		node->rrx -= node->rrr;
		node->neib_rrx = neib->rrx - node->rrr;
		node->rr = 0;
		node->sum_ops = node->min_with_rrr;
	}
}
