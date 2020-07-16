/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:05:22 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/13 22:34:23 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	main_read(t_stack *a, t_stack *b)
{
	char	*str;
	char	*temp;

	str = NULL;
	temp = NULL;
	while ((str = ft_strnew(4)) && read(0, str, 3))
	{
		if (str[0] == '\n' || str[1] == '\n')
			end_error_free(a, b, str, NULL);
		if (str[2] != '\n' && (temp = ft_strnew(1)) && read(0, temp, 1))
		{
			if (temp[0] == '\n')
				str = ft_strcat(str, temp);
			else
				end_error_free(a, b, str, temp);
			free(temp);
		}
		valid_command(str, a, b);
		free(str);
	}
}

int		main(int ac, char **av)
{
	char	*str;
	char	*temp;
	t_stack	*a;
	t_stack	*b;

	str = NULL;
	temp = NULL;
	if (!(a = valid_num(ac, av, CH)))
		return (END);
	if (!(b = create_stack('b')))
		free_stack(a, MALLOC_ERROR);
	main_read(a, b);
	end_free(check_sort(a, b), a, b, CH);
	return (END);
}
