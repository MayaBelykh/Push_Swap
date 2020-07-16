/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 21:17:37 by ccolemon          #+#    #+#             */
/*   Updated: 2019/06/03 19:01:13 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define EMPTY -2
#define ERR_PROGRAM -1
#define ERR_MEMORY 0
#define ERR_TYPE 0
#define SUCCESS_END 1
#define FLAGS(x) (x == '#' || x == '0' || x == '-' || x == '+' || x == 32)
#define MIN_WIDTH(x) (x == '*' || (x >= '0' && x <= '9'))
#define PREC_DOT(x) (x == '.')
#define PREC(x) (x == '*' || (x >= '0' && x <= '9'))
#define MODIF(x) (x == 'h' || x == 'l' || x == 'L' || x == 'j' || x == 'z')
#define SHARP format[0]
#define NUL format[1]
#define MINUS format[2]
#define PLUS format[3]
#define SHIFT format[4]
#define WIDTH format[5]
#define PREC_ON format[6]
#define PRECISION format[7]
#define HL format[8]
#define L format[9]
#define LL format[10]
#define H format[11]
#define HH format[12]
#define J format[13]
#define Z format[14]
#define TYPE format[15]
#define N format[16]
#define SIG format[17]
#define X format[18]
#define LEN format[19]

int			p_output(t_ap *val, int code)
{
	int		n;
	int		m;
	int		i;
	t_ap	*tmp;

	n = 0;
	tmp = val;
	while (tmp)
	{
		i = -1;
		if (tmp->str && tmp->ischar != -1 && tmp->ischar != 1)
			write(1, tmp->str, ft_strlen(tmp->str));
		else if (tmp->ischar == 1 && (++n))
			write(1, "\0", 1);
		else if (tmp->ischar == -1)
			while (tmp->str[++i])
				write(1, (i == tmp->pos_nul) ? "\0" : &tmp->str[i], 1);
		n += (i > 0) ? i : ft_strlen(tmp->str);
		tmp = tmp->next;
	}
	m = (code == 1) ? n : code;
	return (p_free(val, 0, 0, (code && m) ? m : EMPTY));
}
