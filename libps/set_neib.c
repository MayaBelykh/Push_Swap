/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_neib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 21:33:42 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/04 18:26:54 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_neib_one(t_stack *stack, t_node *node)
{
	t_node	*neibs;
	int		size;
	int		diff;

	neibs = stack->start;
	diff = INT_MAX;
	size = stack->size;
	while (size--)
	{
		if (node->pos_sort < neibs->pos_sort &&
			diff > neibs->pos_sort - node->pos_sort)
		{
			diff = neibs->pos_sort - node->pos_sort;
			node->pos_neib = neibs->pos;
		}
		neibs = neibs->next;
	}
	neibs = stack->start;
	diff = node->pos_neib != -1 ? node->pos_neib : 0;
	while (diff--)
		neibs = neibs->next;
	if (node && neibs)
		set_ops(node, neibs);
}

void	set_default_neib_one(t_stack *stack)
{
	t_node	*node;
	int		size;

	node = stack->start;
	size = stack->size;
	while (size--)
	{
		node->pos_neib = -1;
		node = node->next;
	}
}

void	set_default_neib(t_stack *a, t_stack *b)
{
	if (a && a->size && (!b || !b->size))
	{
		set_pos(a);
		set_default_neib_one(a);
	}
	else if ((!a || !a->size) && b && b->size)
	{
		set_pos(b);
		set_default_neib_one(b);
	}
	return ;
}

void	set_neib(t_stack *a, t_stack *b)
{
	t_node	*start_a;
	t_node	*start_b;

	if (!a || !b || !a->size || !b->size)
		set_default_neib(a, b);
	else
	{
		start_a = a->start;
		start_b = b->start;
		set_pos(a);
		set_pos(b);
		while (start_b)
		{
			set_neib_one(a, start_b);
			start_b = start_b->next;
		}
	}
}
