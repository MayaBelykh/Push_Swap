/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:16:33 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/05 21:45:40 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**  rotate - shift up all elements of stack by 1.
**  The first element becomes the last one.
*/

int	reverse_rotate(t_stack *stack)
{
	t_node	*temp;

	temp = NULL;
	if (stack->size >= 2)
	{
		if (!(temp = create_node(stack->end->value, stack->end->pos_sort)))
			return (MALLOC_ERROR);
		if (pop(stack, END))
		{
			push(stack, temp);
			return (SUCCESS);
		}
		set_pos(stack);
	}
	return (END);
}

int	rra(t_stack *a, t_stack *b, int ps_or_ch)
{
	int code;

	code = reverse_rotate(a);
	print_op_ps(RRA, ps_or_ch);
	if (code == MALLOC_ERROR)
		end_free(MALLOC_ERROR, a, b, ps_or_ch);
	set_neib(a, b);
	return (code ? SUCCESS : END);
}

int	rrb(t_stack *a, t_stack *b, int ps_or_ch)
{
	int code;

	code = reverse_rotate(b);
	print_op_ps(RRB, ps_or_ch);
	if (code == MALLOC_ERROR)
		end_free(MALLOC_ERROR, a, b, ps_or_ch);
	set_neib(a, b);
	return (code ? SUCCESS : END);
}

int	rrr(t_stack *a, t_stack *b, int ps_or_ch)
{
	int code;

	code = reverse_rotate(a) + reverse_rotate(b);
	print_op_ps(RRR, ps_or_ch);
	if (code >= MALLOC_ERROR)
		end_free(MALLOC_ERROR, a, b, ps_or_ch);
	set_neib(a, b);
	return (code ? SUCCESS : END);
}
