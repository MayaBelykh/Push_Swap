/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:16:52 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/05 21:44:57 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**  rotate - shift up all elements of stack by 1.
**  The first element becomes the last one.
*/

int	rotate(t_stack *stack)
{
	t_node *temp;

	temp = NULL;
	if (stack->size >= 2)
	{
		if (!(temp = create_node(stack->start->value, stack->start->pos_sort)))
			return (MALLOC_ERROR);
		if (pop(stack, START))
		{
			stack->end->next = temp;
			stack->end = stack->end->next;
			stack->size++;
			return (SUCCESS);
		}
	}
	return (END);
}

int	ra(t_stack *a, t_stack *b, int ps_or_ch)
{
	int code;

	code = rotate(a);
	print_op_ps(RA, ps_or_ch);
	if (code == MALLOC_ERROR)
		end_free(MALLOC_ERROR, a, b, ps_or_ch);
	set_neib(a, b);
	return (code ? SUCCESS : END);
}

int	rb(t_stack *a, t_stack *b, int ps_or_ch)
{
	int code;

	code = rotate(b);
	print_op_ps(RB, ps_or_ch);
	if (code == MALLOC_ERROR)
		end_free(MALLOC_ERROR, a, b, ps_or_ch);
	set_neib(a, b);
	return (code ? SUCCESS : END);
}

int	rr(t_stack *a, t_stack *b, int ps_or_ch)
{
	int code;

	code = rotate(a) + rotate(b);
	print_op_ps(RR, ps_or_ch);
	if (code >= MALLOC_ERROR)
		end_free(MALLOC_ERROR, a, b, ps_or_ch);
	set_neib(a, b);
	return (code ? SUCCESS : END);
}
