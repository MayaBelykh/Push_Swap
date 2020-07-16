/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:18:40 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/11 22:01:34 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_sort(t_stack *a, t_stack *b)
{
	t_node *node;

	if (b->start || !a->start || !a)
		return (END);
	node = a->start;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (END);
		node = node->next;
	}
	return (SUCCESS);
}
