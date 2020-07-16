/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_neib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:03:10 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/11 22:01:34 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		to_neib(t_stack *a, t_stack *b, t_node *node)
{
	int		ops[7];

	S_NODE_RX = node->rx;
	S_NODE_RRX = node->rrx;
	S_SS = node->ss;
	S_RR = node->rr;
	S_RRR = node->rrr;
	S_NEIB_RX = node->neib_rx;
	S_NEIB_RRX = node->neib_rrx;
	while (S_NODE_RX--)
		rb(a, b, PS);
	while (S_NODE_RRX--)
		rrb(a, b, PS);
	while (S_SS--)
		ss(a, b, PS);
	while (S_RR--)
		rr(a, b, PS);
	while (S_RRR--)
		rrr(a, b, PS);
	while (S_NEIB_RX--)
		ra(a, b, PS);
	while (S_NEIB_RRX--)
		rra(a, b, PS);
	pa(a, b, PS);
}
