/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:16:41 by ccolemon          #+#    #+#             */
/*   Updated: 2019/08/30 21:25:18 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	pop(t_stack *stack, int code)
{
	t_node	*temp;

	if (stack->size)
	{
		if (code == START)
		{
			temp = stack->start->next;
			free(stack->start);
			stack->start = temp;
			if (--stack->size <= 1)
				stack->end = stack->start;
		}
		else
		{
			temp = stack->start;
			while (temp->next != stack->end)
				temp = temp->next;
			free(stack->end);
			stack->end = temp;
			stack->end->next = NULL;
			stack->size--;
		}
		return (SUCCESS);
	}
	return (END);
}
