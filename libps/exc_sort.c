/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:59:06 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/13 22:35:13 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		exc_sort(t_stack *a, t_stack *b, int first, int third)
{
	int		second;
	int		max;
	int		min;

	second = a->start->next->pos_sort;
	max = a->full_size - 1;
	min = 0;
	if (first == min && third == max)
		return ;
	if (first == min && second == max)
	{
		rra(a, b, PS);
		sa(a, b, PS);
	}
	else if (first == max && second == min)
		ra(a, b, PS);
	else if (first == max && third == min)
	{
		sa(a, b, PS);
		rra(a, b, PS);
	}
	else if (second == min && third == max)
		sa(a, b, PS);
	else if (second == max && third == min)
		rra(a, b, PS);
}
