/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:16:45 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/05 22:06:00 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** push - take the first element at the top of second stack and put it
** at the top of first stack. Do nothing if second is empty.
*/

int	push(t_stack *stack, t_node *node)
{
	t_node	*temp;

	temp = NULL;
	if (stack && node)
	{
		temp = stack->start;
		stack->start = node;
		stack->start->next = temp;
		stack->start->pos_sort = node->pos_sort;
		if (++stack->size == 1)
			stack->end = node;
		return (SUCCESS);
	}
	return (END);
}

int	pa(t_stack *a, t_stack *b, int ps_or_ch)
{
	t_node	*node;

	node = NULL;
	if (b->size)
	{
		node = create_node(b->start->value, b->start->pos_sort);
		if (pop(b, START) && push(a, node))
		{
			set_neib(a, b);
			print_op_ps(PA, ps_or_ch);
			return (SUCCESS);
		}
	}
	set_neib(a, b);
	return (END);
}

int	pb(t_stack *b, t_stack *a, int ps_or_ch)
{
	t_node	*node;

	node = NULL;
	if (a->size)
	{
		node = create_node(a->start->value, a->start->pos_sort);
		if (pop(a, START) && push(b, node))
		{
			set_neib(a, b);
			print_op_ps(PB, ps_or_ch);
			return (SUCCESS);
		}
	}
	set_neib(a, b);
	return (END);
}
