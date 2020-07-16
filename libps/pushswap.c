/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 20:40:45 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/13 22:01:30 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (!(a = valid_num(ac, av, PS)))
		return (END);
	if (!(b = create_stack('b')))
		free_stack(a, MALLOC_ERROR);
	if (check_sort(a, b))
		end_free(END, a, b, PS);
	sort(a, b);
	end_free(check_sort(a, b), a, b, PS);
	return (END);
}
