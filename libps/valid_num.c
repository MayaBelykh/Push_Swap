/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:06:57 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/10 22:58:48 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		valid_str(char *s)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (((*s > '9' || *s < '0') && *s != '-' && *s != '+' && *s != ' ')
		|| ((*s == '+' || *s == '-') && (*(s + 1) > '9' || *(s + 1) < '0'))
		|| (*s >= '0' && *s <= '9' && *(s + 1) != ' ' && (*(s + 1) > '9'
		|| *(s + 1) < '0') && *(s + 1) != 0))
			end(1, "\033[1;31mError\033[0m\n");
		if (*s >= '0' && *s <= '9' && (*(s + 1) == ' ' || *(s + 1) == 0))
			count++;
		s++;
	}
	return (count);
}

void	check_dup(int64_t *num, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size && (j = i) >= 0)
		while (++j < size)
			if (num[i] == num[j])
				end(1, "\033[1;31mError\033[0m\n");
}

t_stack	*valid_num(int lenght, char **av, int code)
{
	int		i;
	int		j;
	int		count;
	int64_t	num[MAX];

	i = 0;
	j = -1;
	count = 0;
	ft_numset(num, MAX, LONG_MAX);
	if (lenght < 2)
		return (END);
	while (++i < lenght && count <= MAX)
	{
		if ((count = valid_str(av[i])) == 1)
			get_num(&j, num, av[i]);
		else if (count > 1)
			get_mnum(count, &j, num, ft_strsplit(av[i], ' '));
		else if (!count)
			end(1, "\033[1;31mError\033[0m\n");
	}
	check_dup(num, j + 1);
	return (get_stack(num, j + 1, code));
}
