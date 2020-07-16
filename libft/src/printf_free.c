/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 23:33:41 by ccolemon          #+#    #+#             */
/*   Updated: 2019/06/01 16:48:30 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			p_free(t_ap *param1, void *param2, void *param3, int code)
{
	int		i;
	t_ap	*tmp;

	i = 0;
	tmp = param1;
	while (tmp)
	{
		param1 = tmp;
		tmp = param1->next;
		if (param1->str)
			free(param1->str);
		free(param1);
	}
	free(param2);
	free(param3);
	return (code);
}
