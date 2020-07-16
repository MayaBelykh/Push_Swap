/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:16:55 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/04 20:57:37 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** swap - swap the first 2 elements at the top of stack.
** Do nothing if there is only one or no elements
*/

int	swap(t_stack *stack)
{
	int	num;
	int	pos_sort;

	if (stack->size >= 2)
	{
		num = stack->start->value;
		pos_sort = stack->start->pos_sort;
		stack->start->value = stack->start->next->value;
		stack->start->pos_sort = stack->start->next->pos_sort;
		stack->start->next->value = num;
		stack->start->next->pos_sort = pos_sort;
		return (SUCCESS);
	}
	return (END);
}

int	sa(t_stack *a, t_stack *b, int ps_or_ch)
{
	int code;

	code = swap(a);
	print_op_ps(SA, ps_or_ch);
	set_neib(a, b);
	return (code ? SUCCESS : END);
}

int	sb(t_stack *a, t_stack *b, int ps_or_ch)
{
	int code;

	code = swap(b);
	print_op_ps(SB, ps_or_ch);
	set_neib(a, b);
	return (code ? SUCCESS : END);
}

int	ss(t_stack *a, t_stack *b, int ps_or_ch)
{
	int code;

	code = swap(a) + swap(b);
	print_op_ps(SS, ps_or_ch);
	set_neib(a, b);
	return (code ? SUCCESS : END);
}
