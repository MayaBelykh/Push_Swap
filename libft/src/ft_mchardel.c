/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mchardel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:39:48 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/06 20:25:31 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mchardel(char **m_char)
{
	int i;

	i = 0;
	while (m_char[i])
		free(m_char[i++]);
	free(m_char);
}