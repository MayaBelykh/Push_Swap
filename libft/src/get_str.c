/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:14:09 by ccolemon          #+#    #+#             */
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

static char	*fill_str(int *format, char *s, char *str, int m)
{
	char	*tmp;
	int		len;

	str[m] = (SIG) ? SIG : str[m];
	len = 0;
	while (s[len])
		len++;
	m = PRECISION - len;
	if (N == PRECISION)
		str = ft_memset_n(str, (SIG ? X : X - 1), '0', m);
	tmp = str + (SIG ? X : X - 1) + (N == PRECISION ? m : 0);
	tmp = ft_strncpy(tmp, s, len);
	return (str);
}

char		*get_str(int *format, long long dec, char *s)
{
	int		m;
	char	*str;

	LEN = ft_strlen(s);
	N = ft_max(LEN, PRECISION, 0);
	m = ft_max(N, PRECISION, WIDTH);
	SIG = (TYPE != 'u' && TYPE != 'x' && TYPE != 'X' && TYPE != 'o' &&
			TYPE != 'O') ? (int)sign(format, dec) : 0;
	str = ft_strnew(m + (SIG || PRECISION >= WIDTH ? 1 : 0));
	if (!MINUS)
	{
		X = m + ((SIG && PRECISION < WIDTH) ? 0 : 1) - N;
		X = (!X && SIG ? 1 : X);
		str = ft_memset_n(str, 0, (!PREC_ON && NUL && m == WIDTH) ?
																'0' : ' ', X);
		m = (!PREC_ON && NUL && m == WIDTH) ? 0 : X - 1;
	}
	else
	{
		X = 1;
		str = ft_memset_n(str, 0, ' ', m + (SIG && PRECISION >= WIDTH ? 1 : 0));
		m = 0;
	}
	return (fill_str(format, s, str, m));
}
