/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 22:21:34 by ccolemon          #+#    #+#             */
/*   Updated: 2019/03/21 21:46:14 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < (unsigned int)n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < (unsigned int)n)
		dest[i++] = 0;
	return (dest);
}
