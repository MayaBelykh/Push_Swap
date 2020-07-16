/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:33:23 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/12 00:08:20 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*create_node(int num, int pos_sort)
{
	t_node	*node;

	node = NULL;
	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (END);
	node->value = num;
	node->pos = 0;
	node->pos_neib = -1;
	node->pos_sort = pos_sort;
	node->up = NO;
	node->sx = 0;
	node->rx = 0;
	node->rrx = 0;
	node->neib_rx = 0;
	node->neib_rrx = 0;
	node->ss = 0;
	node->rr = 0;
	node->rrr = 0;
	node->sum_op_up = 0;
	node->min_with_rr = 0;
	node->min_with_rrr = 0;
	node->sum_ops = 0;
	node->next = NULL;
	return (node);
}

t_stack	*create_stack(char name)
{
	t_stack	*stack;

	stack = NULL;
	if ((stack = (t_stack *)malloc(sizeof(t_stack))))
	{
		stack->start = NULL;
		stack->end = NULL;
		stack->min = 0;
		stack->mid = 0;
		stack->max = 0;
		stack->size = 0;
		stack->full_size = 0;
		stack->name = name;
		stack->next = NULL;
		return (stack);
	}
	return (END);
}
