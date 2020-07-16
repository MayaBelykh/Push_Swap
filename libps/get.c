/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 21:12:46 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/10 21:56:01 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*get_stack(int64_t *num, int size, int code)
{
	t_stack	*stack;
	t_node	*node;
	int		i;

	i = size - 1;
	if (!(stack = create_stack('a')))
		end(1, "\033[1;31mError\033[0m\n");
	if (!(node = create_node(num[i], 0)))
		free_stack(stack, MALLOC_ERROR);
	push(stack, node);
	stack->end = node;
	while (i--)
	{
		if (!(node = create_node(num[i], 0)))
			free_stack(stack, MALLOC_ERROR);
		push(stack, node);
	}
	stack->start = node;
	stack->size = size;
	stack->full_size = size;
	if (code == PS || code == CH)
		set_sort_pos(num, stack);
	return (stack);
}

void	get_num(int *j, int64_t *num, char *str)
{
	num[++(*j)] = ft_ltoi(str);
	if (num[*j] < INT_MIN || num[*j] > INT_MAX)
		end(1, "\033[1;31mError\033[0m\n");
}

void	get_mnum(int count, int *j, int64_t *num, char **split)
{
	char	*str;
	int		i;

	i = -1;
	str = NULL;
	if (split && count <= MAX)
	{
		while (++i < count && ++(*j) >= 0 && count <= MAX)
		{
			str = split[i];
			num[*j] = ft_ltoi(str);
			if (num[*j] < INT_MIN || num[*j] > INT_MAX)
			{
				ft_mchardel(split);
				end(1, "\033[1;31mError\033[0m\n");
			}
		}
		ft_mchardel(split);
	}
	else
	{
		ft_mchardel(split);
		end(1, "\033[1;31mError\033[0m\n");
	}
}
