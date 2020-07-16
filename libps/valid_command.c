/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 21:47:14 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/13 20:06:51 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	valid_command(char *str, t_stack *a, t_stack *b)
{
	if (ft_strequ(str, "sa\n"))
		sa(a, b, CH);
	else if (ft_strequ(str, "sb\n"))
		sb(a, b, CH);
	else if (ft_strequ(str, "ss\n"))
		ss(a, b, CH);
	else if (ft_strequ(str, "pa\n"))
		pa(a, b, CH);
	else if (ft_strequ(str, "pb\n"))
		pb(b, a, CH);
	else if (ft_strequ(str, "ra\n"))
		ra(a, b, CH);
	else if (ft_strequ(str, "rb\n"))
		rb(a, b, CH);
	else if (ft_strequ(str, "rr\n"))
		rr(a, b, CH);
	else if (ft_strequ(str, "rra\n"))
		rra(a, b, CH);
	else if (ft_strequ(str, "rrb\n"))
		rrb(a, b, CH);
	else if (ft_strequ(str, "rrr\n"))
		rrr(a, b, CH);
	else
		end_error_free(a, b, str, NULL);
}
