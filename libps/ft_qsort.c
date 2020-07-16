/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:33:37 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/11 22:01:34 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_elems(int64_t *num, int i, int j)
{
	int64_t temp;

	temp = num[i];
	num[i] = num[j];
	num[j] = temp;
}

void	ft_qsort(int64_t *num, int left, int right)
{
	int i;
	int last;

	if (left >= right)
		return ;
	swap_elems(num, left, (left + right) / 2);
	last = left;
	i = left;
	while (++i <= right)
		if (num[i] < num[left])
			swap_elems(num, ++last, i);
	swap_elems(num, left, last);
	ft_qsort(num, left, last - 1);
	ft_qsort(num, last + 1, right);
}
