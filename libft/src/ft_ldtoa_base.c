/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:56:36 by ccolemon          #+#    #+#             */
/*   Updated: 2019/05/29 17:56:54 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ldtoa_base(double value, int base, int need_sign)
{
	__int128_t	n;
	char		*str;
	int			i;
	int			sign;

	n = (__int128_t)value;
	sign = (value < 0) ? -1 : 1;
	i = (base == 10 && need_sign && value < 0) ? 2 : 1;
	n *= (sign < 0) ? -1 : 1;
	while (value /= base)
		i++;
	str = ft_strnew(i);
	str[0] = (sign < 0 && need_sign && base == 10) ? '-' : '0';
	while (n)
	{
		str[--i] = (n % base) + ((n % base) < 10 ? '0' : '7');
		n /= base;
	}
	return (str);
}
