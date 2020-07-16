/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funfree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:41:46 by ccolemon          #+#    #+#             */
/*   Updated: 2019/06/01 16:48:30 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*funfree(char *(*f)(const char *, const char *), char *p, char *p2,
																	int check)
{
	char	*result;

	result = (*f)(p, p2);
	if (check != 2)
		free(check == 1 ? p : p2);
	else
	{
		free(p);
		free(p2);
	}
	return (result);
}
