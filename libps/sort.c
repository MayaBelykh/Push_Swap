/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:28:21 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/13 22:01:28 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		final_sort(t_stack *a)
{
	t_node	*node;
	int		pos;

	node = a->start;
	while (node->next->pos_sort)
		node = node->next;
	pos = node->pos;
	if (pos < a->full_size - pos)
	{
		node = node->next;
		while (node != a->start)
			ra(a, NULL, PS);
	}
	else
		while (node != a->end)
			rra(a, NULL, PS);
}

void		mid_sort(t_stack *a, t_stack *b)
{
	int		min;
	t_node	*node;
	t_node	*min_node;

	while (b->size)
	{
		node = b->start;
		min = node->sum_ops;
		min_node = node;
		while (node)
		{
			min_node = node->sum_ops < min ? node : min_node;
			min = node->sum_ops < min ? node->sum_ops : min;
			node = node->next;
		}
		to_neib(a, b, min_node);
	}
}

void		dop_sort(t_stack *a, t_stack *b, int first, int third)
{
	int		second;
	int		max;
	int		min;

	second = a->start->next->pos_sort;
	max = a->full_size - 1;
	min = 0;
	if (first == max && second == min)
		return ;
	if (first == min && second == max)
		sa(a, b, PS);
	else if (first == min && third == max)
		rra(a, b, PS);
	else if (first == max && third == min)
	{
		sa(a, b, PS);
		ra(a, b, PS);
	}
	else if (second == min && third == max)
	{
		ra(a, b, PS);
		sa(a, b, PS);
	}
	else if (second == max && third == min)
		ra(a, b, PS);
}

void		start_sort(t_stack *a, t_stack *b)
{
	t_node	*node;
	int64_t	value;
	int64_t	next;

	if (a->size > 2)
	{
		while (a->size != 3)
		{
			node = a->start;
			value = node->value;
			next = node->next->value;
			if (value != a->min && value != a->mid && value != a->max)
				pb(b, a, PS);
			else
				ra(a, b, PS);
		}
	}
	dop_sort(a, b, a->start->pos_sort, a->end->pos_sort);
}

int			sort(t_stack *a, t_stack *b)
{
	if (a->size > 3)
	{
		start_sort(a, b);
		mid_sort(a, b);
		final_sort(a);
	}
	else if (a->size == 3)
		exc_sort(a, b, a->start->pos_sort, a->end->pos_sort);
	else if (a->size == 2)
		if (a->start->value > a->end->value)
			sa(a, b, PS);
	return (SUCCESS);
}
