/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:52:39 by ccolemon          #+#    #+#             */
/*   Updated: 2019/08/17 17:14:41 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define NUM 1
#define STR 2

void	ft_print_mas(int fd, int64_t *num, char **mas, int size)
{
	int		i;

	i = -1;
	if (num && size)
		while (++i < size)
		{
			ft_putnbr_fd(num[i], fd);
			write(fd, "\n", 1);
		}
	else if (mas && size)
		while (++i < size)
		{
			ft_putstr_fd(mas[i], fd);
			write(fd, "\n", 1);
		}
}
