/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:40:03 by ccolemon          #+#    #+#             */
/*   Updated: 2019/06/03 19:01:51 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define EMPTY -2
#define ERR_PROGRAM -1

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_ap	*val;
	t_ap	*start;
	int		n;

	if (!(val = (t_ap *)malloc(sizeof(t_ap))))
		return (-1);
	ft_memset(val, 0, sizeof(t_ap));
	start = val;
	if (!(ft_strchr(fmt, '%')))
	{
		ft_putstr(fmt);
		n = ft_strlen(fmt);
		return (p_free(val, 0, 0, n));
	}
	va_start(ap, fmt);
	n = p_output(start, p_parcer(&ap, (char *)fmt, val, 0));
	va_end(ap);
	n = (n == 0) ? ERR_PROGRAM : n;
	n = (n == EMPTY) ? 0 : n;
	return (n);
}
