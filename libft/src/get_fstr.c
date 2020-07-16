/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:40:34 by ccolemon          #+#    #+#             */
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

static char		*helper_bstr(__uint128_t num_i, long double *tmp, int *format,
																		int i)
{
	char		*bstr;
	int			len;

	len = i;
	bstr = ft_strnew(i);
	bstr[0] = '0';
	while (num_i > 0.9 && --i >= 0)
	{
		bstr[i] = num_i % 10 + (i == 0 && PRECISION == 0
							&& (int)(*tmp * 10) % 10 >= 5
							&& (int)(*tmp * 10) % 10 < 9 ? '1' : '0');
		num_i /= 10;
	}
	if (!PRECISION && (int)(*tmp * 10) % 10 == 9)
	{
		while (bstr[--i] == '9')
			bstr[i] = '0';
		bstr[i] += 1;
	}
	return (bstr);
}

char			*get_bstr(long double value, int *format, long double *tmp,
																	int i)
{
	long double	n;
	__uint128_t	num_i;
	char		*bstr;

	i = ((int)value == 0 || value == 1.0) ? 1 : 0;
	n = value;
	while ((value /= 10) > 0.1)
		i++;
	num_i = n;
	*tmp = n - (long double)num_i;
	bstr = NULL;
	if (i < 41)
		bstr = helper_bstr(num_i, tmp, format, i);
	else if (SIG == '-')
	{
		bstr = ft_strdup((TYPE == 'F') ? "-INF" : "-inf");
		ft_memset(format, 0, sizeof(int) * 20);
	}
	else if (SIG == '+')
	{
		bstr = ft_strdup((TYPE == 'F') ? "+INF" : "+inf");
		ft_memset(format, 0, sizeof(int) * 20);
	}
	return (bstr);
}

char			*get_astr(int *format, long double tmp, int i, int check)
{
	char		*astr;

	astr = ft_strnew(PRECISION + 1);
	astr[0] = (PRECISION) ? '.' : 0;
	while (PRECISION-- && tmp)
	{
		tmp -= (tmp > 1000000) ? (int)tmp : 0;
		tmp *= 10;
		astr[++i] = (int)tmp % 10 + (!PRECISION && (int)tmp % 10 != 9 &&
				(int)(tmp * 10) % 10 >= 5 && (int)(tmp * 10) % 10 <= 9 &&
				(tmp - (int)tmp) * 10 >= 5.00000000000000000001 ? '1' : '0');
		check = (!PRECISION && (int)tmp % 10 != 9 &&
				(int)(tmp * 10) % 10 >= 5 && (int)(tmp * 10) % 10 <= 9 &&
				(tmp - (int)tmp) * 10 >= 5.00000000000000000001 ? 1 : 0);
	}
	while (PRECISION-- >= 0)
		astr[++i] = '0';
	if (astr[i] == '9' && check == 0 && (int)(tmp * 10) % 10 >= 5 &&
										(int)(tmp * 10) % 10 <= 9)
	{
		while (astr[i] == '9')
			astr[i--] = '0';
		astr[i] += 1;
	}
	return (astr);
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

char			*get_fstr(char *s, int *format, int sg)
{
	char		*str;
	char		*tmp;
	int			i;

	N = ft_strlen(s);
	i = SIG ? 1 : 0;
	str = ft_strnew((N >= WIDTH ? N : WIDTH) + i);
	tmp = str;
	i = 0;
	str[i++] = ((sg < 0 || PLUS) && ((WIDTH >= N && NUL) || WIDTH <= N))
									? (char)SIG : str[i];
	i = (str[0]) ? 1 : 0;
	ft_memset(tmp + i, NUL && !MINUS ? '0' : ' ', (N >= WIDTH ? N : WIDTH));
	if ((sg < 0 || PLUS) && WIDTH > N && !NUL && ++i)
		str[(MINUS ? N : WIDTH - i) - N] = (char)SIG;
	i = (N >= WIDTH && (sg < 0 || PLUS) ? 1 : 0);
	N = ((N >= WIDTH || MINUS) ? N : WIDTH) - N;
	tmp = str + (ft_strlen(str) - ft_strlen(s));
	ft_fstrcpy(&tmp, s);
	free(s);
	return (str);
}
