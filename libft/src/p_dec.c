/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_dec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 23:42:46 by ccolemon          #+#    #+#             */
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

static void		get_arg(long long *dec, va_list *ap, int *format)
{
	if (L)
		*dec = (int64_t)va_arg(*ap, long);
	else if (LL)
		*dec = va_arg(*ap, int64_t);
	else if ((TYPE == 'd' || TYPE == 'i') && HH)
		*dec = (int64_t)(int8_t)va_arg(*ap, int32_t);
	else if ((TYPE == 'd' || TYPE == 'i') && H)
		*dec = (int64_t)(int16_t)va_arg(*ap, int32_t);
	else if (J)
		*dec = (int64_t)va_arg(*ap, intmax_t);
	else if (Z)
		*dec = (int64_t)va_arg(*ap, size_t);
	else if (TYPE == 'd' || TYPE == 'i')
		*dec = (int64_t)va_arg(*ap, int32_t);
	else
		*dec = (int64_t)va_arg(*ap, long);
	MINUS = (WIDTH < 0 || MINUS) ? 1 : 0;
	WIDTH = (WIDTH < 0) ? WIDTH * -1 : WIDTH;
	PREC_ON = (PRECISION < 0) ? 0 : PREC_ON;
	PRECISION = (PRECISION < 0) ? 0 : PRECISION;
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

int				p_dec(char *fmt, va_list *ap, t_ap *val, int type)
{
	int			format[20];
	long long	dec;
	char		*s;

	ft_memset(format, 0, sizeof(int) * 20);
	TYPE = type;
	if ((N = p_format_parcer(fmt, ap, format)) > 1)
		return (p_errtype(fmt, N, format, val));
	get_arg(&dec, ap, format);
	if (dec == 0 && PREC_ON && PRECISION == 0)
	{
		N = PLUS && !WIDTH && MINUS ? 2 : 1;
		val->str = ft_strset(' ', WIDTH + N - 1, 0, 0);
		N = (MINUS || !WIDTH) ? 0 : WIDTH - 1;
		val->str[N] = (PLUS) ? '+' : val->str[N];
	}
	else
	{
		s = ft_ltoa_base(dec, 10, 0);
		val->str = get_str(format, dec, s);
		free(s);
	}
	return (SUCCESS_END);
}
