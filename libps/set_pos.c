/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 21:33:58 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/04 17:22:05 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_pos(t_stack *stack)
{
	int		i;
	t_node	*node;

	i = -1;
	node = stack->start;
	while (++i < stack->size)
	{
		node->pos = i;
		set_up(stack, node);
		node = node->next;
	}
}

void	set_sort_pos(int64_t *num, t_stack *stack)
{
	int		i;
	int		j;
	t_node	*node;

	i = -1;
	j = -1;
	ft_memcpy(stack->sort_num, num, 1024 * sizeof(int64_t));
	ft_qsort(stack->sort_num, 0, stack->size);
	node = stack->start;
	while (++i < stack->size)
	{
		j = -1;
		while (stack->sort_num[++j] != node->value)
			;
		node->pos_sort = j;
		node = node->next;
	}
	stack->max = stack->sort_num[stack->size - 1];
	stack->min = stack->sort_num[0];
	stack->mid = stack->sort_num[stack->size / 2];
}
