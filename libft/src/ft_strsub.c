/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:27:13 by ccolemon          #+#    #+#             */
/*   Updated: 2019/05/25 23:40:11 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	char	*st;

	i = len;
	if (!s || !(str = ft_strnew(len)))
		return (0);
	st = str;
	while (i--)
		*str++ = s[start++];
	return (st);
}
