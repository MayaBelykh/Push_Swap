/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_float.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 23:43:32 by ccolemon          #+#    #+#             */
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

static char		*ft_get_float(long double value, int *format)
{
	long double	tmp;
	char		*bstr;
	char		*astr;
	char		*s;

	SIG = (int)sign(format, (value < 0) ? -1 : 1);
	value *= (long double)(value < 0 ? -1 : 1);
	PRECISION = (!PREC_ON) ? 6 : PRECISION;
	tmp = value;
	bstr = get_bstr(value, format, &tmp, 0);
	astr = get_astr(format, tmp, 0, 0);
	s = ft_strjoin(bstr, astr);
	p_free(0, bstr, astr, 0);
	return (get_fstr(s, format, SIG == '-' ? -1 : 1));
}

/*
** format:
**
** SHARP		0		NUL			1		MINUS		2		PLUS		3
** SHIFT		4		WIDTH		5		PREC_ON		6		PRECISION	7
** HL			8		L			9		LL 			10		H 			11
** HH 			12		J 			13		Z 			14		TYPE 		15
** N 			16		SIG 		17		X 			18		LEN 		19
*/

int				p_float(char *fmt, va_list *ap, t_ap *val, int t)
{
	int			n;
	int			format[20];
	long double	value;

	ft_memset(format, 0, sizeof(int) * 20);
	TYPE = t;
	if ((n = p_format_parcer(fmt, ap, format)) > 1)
		return (p_errtype(fmt, n, format, val));
	if (HL || (L && TYPE == 'F'))
		value = (long double)va_arg(*ap, long double);
	else
		value = (long double)va_arg(*ap, double);
	if (value >= 999999999999999999999999999999999999999.0)
		val->str = ft_strdup((TYPE == 'F') ? "+INF" : "+inf");
	else if (value <= -999999999999999999999999999999999999999.0)
		val->str = ft_strdup((TYPE == 'F') ? "-INF" : "-inf");
	else if (!(value == value))
		val->str = ft_strdup((TYPE == 'F') ? "NAN" : "nan");
	else
		val->str = ft_get_float(value, format);
	return (SUCCESS_END);
}
