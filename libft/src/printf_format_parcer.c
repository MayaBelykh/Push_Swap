/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format_parcer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 22:22:45 by ccolemon          #+#    #+#             */
/*   Updated: 2019/06/03 19:20:52 by ccolemon         ###   ########.fr       */
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

static int	p_flags(char *fmt, int *format)
{
	N = 0;
	while (*fmt != TYPE && FLAGS(*fmt))
	{
		if (*fmt != TYPE && FLAGS(*fmt) && *fmt == '#')
			SHARP = ++N - N + (TYPE == 'p' ? 0 : 1);
		else if (*fmt != TYPE && FLAGS(*fmt) && *fmt == '0')
			NUL = ++N - N + (TYPE == 'p' ? 0 : 1);
		else if (*fmt != TYPE && FLAGS(*fmt) && *fmt == '-')
			MINUS = ++N - N + (TYPE == 'p' ? 0 : 1);
		else if (*fmt != TYPE && FLAGS(*fmt) && *fmt == '+')
			PLUS = ++N - N + (TYPE == 'p' ? 0 : 1);
		else if (*fmt != TYPE && FLAGS(*fmt) && *fmt == ' ')
			SHIFT = ++N - N + (TYPE == 'p' ? 0 : 1);
		fmt += *fmt != TYPE && FLAGS(*fmt) ? 1 : 0;
	}
	return (SUCCESS_END);
}

static int	p_min_width(char *fmt, va_list *ap, int *format)
{
	char	*tmp;
	int		i;

	N = 0;
	if (TYPE != 'p')
	{
		i = 0;
		tmp = fmt;
		while (MIN_WIDTH(*(tmp)))
		{
			WIDTH = (*tmp == '*') ? va_arg(*ap, int) : ft_atoi(tmp);
			i += (*tmp == '*') ? 1 : ft_numlen(WIDTH);
			tmp += i;
			N = i;
		}
	}
	else
	{
		WIDTH = (*fmt == '*') ? va_arg(*ap, int) : ft_atoi(fmt);
		N = (*fmt == '*') ? 1 : ft_numlen(WIDTH);
	}
	return (SUCCESS_END);
}

static int	p_prec(char *fmt, va_list *ap, int *format, int err)
{
	N = 0;
	PREC_ON = 1;
	if (PREC(*fmt))
		PRECISION = (*fmt == '*') ? va_arg(*ap, int) : ft_atoi(fmt);
	else
		PRECISION = 0;
	while (PREC(*fmt))
	{
		N++;
		fmt++;
	}
	if (err && TYPE == 'p')
	{
		WIDTH = PRECISION;
		PRECISION = 1;
	}
	return (SUCCESS_END);
}

static int	p_modif(char *fmt, int *format)
{
	N = 0;
	HL = (TYPE == 'f' && *fmt == 'L') ? 1 : 0;
	HH = (*fmt == 'h' && *(fmt + 1) == 'h') ? 1 : 0;
	LL = (*fmt == 'l' && *(fmt + 1) == 'l') ? 1 : 0;
	H = (*fmt == 'h' && *(fmt + 1) != 'h') ? 1 : 0;
	L = (*fmt == 'l' && *(fmt + 1) != 'l') ? 1 : 0;
	J = (*fmt == 'j') ? 1 : 0;
	Z = (*fmt == 'z') ? 1 : 0;
	N = (HH + LL != 0) ? 2 : 1;
	return (SUCCESS_END);
}

int			p_format_parcer(char *fmt, va_list *ap, int *format)
{
	int		x;
	char	*tmp;
	char	c;

	x = 0;
	N = 1;
	tmp = fmt;
	if (!(fmt + 1))
		return (0);
	if (*(fmt += N) && *fmt != TYPE && FLAGS(*fmt) && (x = 1))
		p_flags(fmt, format);
	if (*(fmt += (x < 1 ? 0 : N)) && *fmt != TYPE && MIN_WIDTH(*fmt) && (x = 2))
		p_min_width(fmt, ap, format);
	if (*(fmt += (x < 2 ? 0 : N)) && (c = *fmt) != TYPE &&
									(PREC_DOT(*fmt) || *fmt == '*'))
		p_prec((x = 3) && c == '*' ? fmt : ++fmt, ap, format, c == '*' ? 1 : 0);
	if (*(fmt += (x < 3 ? 0 : N)) && *fmt != TYPE && MODIF(*fmt) && (x = 4))
		p_modif(fmt, format);
	if (*(fmt += (x < 4 ? 0 : N)) != TYPE)
	{
		TYPE = *fmt;
		return ((int)(fmt - tmp));
	}
	return (SUCCESS_END);
}
