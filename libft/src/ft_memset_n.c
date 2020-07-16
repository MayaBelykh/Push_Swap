/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:48:04 by ccolemon          #+#    #+#             */
/*   Updated: 2019/06/01 16:48:30 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset_n(void *destination, int shift, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;

	ch = (char)c;
	str = (unsigned char *)(destination + shift);
	while (n--)
		*(str++) = ch;
	return (destination);
}
