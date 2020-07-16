/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 21:11:50 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/13 20:41:52 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	end(int code, char *message)
{
	write(code, message, ft_strlen(message));
	exit(END);
}

void	free_stack(t_stack *stack, int code)
{
	t_node *node;
	t_node *temp;

	node = stack->start;
	while (stack->size)
	{
		temp = node->next;
		free(node);
		node = temp;
		stack->size--;
	}
	free(stack);
	if (code == MALLOC_ERROR)
		end(1, "\033[1;31mError\033[0m\n");
}

void	end_error_free(t_stack *a, t_stack *b, char *str, char *temp)
{
	free_stack(a, END);
	free_stack(b, END);
	free(str);
	free(temp);
	end(1, "\033[1;31mError\033[0m\n");
}

void	end_free(int code, t_stack *a, t_stack *b, int ps_or_ch)
{
	if (ps_or_ch == CH)
		write(1, code && code != MALLOC_ERROR ? "✅  OK\n" : "❌  KO\n", 9);
	free_stack(a, END);
	free_stack(b, END);
	if (ps_or_ch == PS && code == MALLOC_ERROR)
		end(1, "\033[1;31mError\033[0m\n");
	exit(END);
}
