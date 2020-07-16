/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:52:41 by ccolemon          #+#    #+#             */
/*   Updated: 2019/06/01 16:48:30 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strset(int c1, size_t s1, int c2, size_t s2)
{
	char	*str;
	char	*start;
	size_t	len;

	len = s1 + s2;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	start = str;
	str[len] = 0;
	while (s1-- > 0)
		*(str++) = c1;
	while (s2-- > 0)
		*(str++) = c2;
	return (start);
}
