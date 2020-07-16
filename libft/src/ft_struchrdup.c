/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struchrdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:50:01 by ccolemon          #+#    #+#             */
/*   Updated: 2019/03/13 22:55:06 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_struchrdup(const char *s, char c)
{
	size_t	i;
	char	*str;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (*tmp && *tmp != c)
	{
		i++;
		tmp++;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	tmp = str;
	while (*s && *s != c)
		*str++ = *s++;
	return (tmp);
}
