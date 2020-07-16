/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:48:04 by ccolemon          #+#    #+#             */
/*   Updated: 2019/06/03 18:56:14 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;

	ch = (char)c;
	str = (unsigned char *)destination;
	while (n--)
		*(str++) = ch;
	return (destination);
}
