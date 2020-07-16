/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:50:01 by ccolemon          #+#    #+#             */
/*   Updated: 2019/03/26 21:48:17 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*str;

	if (!(str = (char *)malloc(n + 1)))
		return (NULL);
	str[n] = '\0';
	i = 0;
	while (s[i] && i < n)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
