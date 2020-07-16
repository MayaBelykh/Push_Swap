/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:20:46 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/13 19:45:09 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t			ft_ltoi(const char *s)
{
	int64_t		mod;
	int			rez;
	char		*str;

	str = (char *)s;
	rez = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (!(mod = 0) && (*str == '+' || *str == '-'))
		rez = ((*str++ == '-') ? -1 : 1);
	while (*str >= '0' && *str <= '9')
	{
		if ((mod * 10) / 10 != mod)
			return (LONG_MAX);
		mod = mod * 10 + (*str++ - '0');
	}
	return (int64_t)(rez * mod);
}
