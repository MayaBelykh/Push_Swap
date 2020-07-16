/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 23:05:59 by ccolemon          #+#    #+#             */
/*   Updated: 2019/06/01 16:48:30 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ultoa_base(uint64_t value, int base)
{
	__uint128_t	n;
	char		*str;
	int			i;

	n = (__uint128_t)value;
	i = 1;
	while (value /= base)
		i++;
	str = ft_strnew(i);
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--i] = (n % base) + ((n % base) < 10 ? '0' : '7');
		n /= base;
	}
	return (str);
}
