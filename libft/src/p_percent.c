/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_percent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 23:44:59 by ccolemon          #+#    #+#             */
/*   Updated: 2019/06/03 19:01:48 by ccolemon         ###   ########.fr       */
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

/*
** format:
**
** SHARP		0		NUL			1		MINUS		2		PLUS		3
** SHIFT		4		WIDTH		5		PREC_ON		6		PRECISION	7
** HL			8		L			9		LL 			10		H 			11
** HH 			12		J 			13		Z 			14		TYPE 		15
** N 			16		SIG 		17		X 			18		LEN 		19
*/

int			p_percent(char *fmt, va_list *ap, t_ap *val)
{
	int		n;
	int		x;
	int		format[20];

	ft_memset(format, 0, sizeof(int) * 20);
	TYPE = '%';
	x = SUCCESS_END;
	if ((n = p_format_parcer(fmt, ap, format)) > 1)
		x = n;
	n = (WIDTH) ? WIDTH : 1;
	val->str = (char *)malloc(n + 1);
	ft_memset(val->str, (NUL && !MINUS ? '0' : ' '), n + 1);
	val->str[n] = '\0';
	n -= (MINUS ? n : 1);
	val->str[n] = TYPE;
	return (x);
}
