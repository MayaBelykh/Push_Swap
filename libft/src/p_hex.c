/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 23:43:48 by ccolemon          #+#    #+#             */
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

static void		get_arg(uint64_t *dec, va_list *ap, int *format)
{
	if (L)
		*dec = (uint64_t)va_arg(*ap, unsigned long);
	else if (LL)
		*dec = va_arg(*ap, uint64_t);
	else if (HH)
		*dec = (uint64_t)(uint8_t)va_arg(*ap, uint32_t);
	else if (H)
		*dec = (uint64_t)(uint16_t)va_arg(*ap, uint32_t);
	else if (J)
		*dec = (uint64_t)va_arg(*ap, uintmax_t);
	else if (Z)
		*dec = (uint64_t)va_arg(*ap, size_t);
	else
		*dec = (uint64_t)va_arg(*ap, uint32_t);
}

static char		*add_sharp(char *str, int *format)
{
	char		*start;

	start = str;
	if ((*str == ' ') && (*(str + 1) == ' '))
	{
		while (*str == ' ')
			str++;
		str -= 2;
		*str++ = '0';
		*str = 'x';
	}
	else if (N <= WIDTH - 1)
	{
		N = (N == WIDTH - 1) ? 1 : 2;
		start = funfree(ft_strjoin, "0x", ft_strsub(str, MINUS ? 0 : N,
						ft_strlen(str) - (MINUS ? N : N - 1)), 3);
		free(str);
	}
	else
	{
		N = (!MINUS && LEN == WIDTH - 1 && PRECISION < WIDTH) ? 1 : 0;
		start = ft_strjoin("0x", str + N);
		free(str);
	}
	return (start);
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

int				p_hex(char *fmt, va_list *ap, t_ap *val, int type)
{
	int			n;
	uint64_t	dec;
	char		*s;
	char		*tmp;
	int			format[20];

	ft_memset(format, 0, sizeof(int) * 20);
	TYPE = type;
	if ((n = p_format_parcer(fmt, ap, format)) > 1)
		return (p_errtype(fmt, n, format, val));
	get_arg(&dec, ap, format);
	if (dec == 0 && PREC_ON && PRECISION == 0)
	{
		val->str = (char *)malloc(WIDTH + 1);
		val->str = ft_memset(val->str, ' ', WIDTH);
	}
	else
	{
		s = ft_ultoa_base(dec, 16);
		tmp = (SHARP && dec != 0) ? add_sharp(get_str(format, dec, s), format)
									: get_str(format, dec, s);
		val->str = (type == 'x') ? ft_tolower_str(tmp) : ft_toupper_str(tmp);
		free(s);
	}
	return (SUCCESS_END);
}
