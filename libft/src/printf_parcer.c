/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_parcer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 23:35:49 by ccolemon          #+#    #+#             */
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

static t_ap		*p_lstcreate(t_ap *lst)
{
	t_ap		*new;

	if ((new = (t_ap *)malloc(sizeof(t_ap))))
	{
		lst->next = new;
		ft_memset(new, 0, sizeof(t_ap));
		new->next = NULL;
	}
	return (new);
}

static int		p_fill(char t, char *fmt, va_list *ap, t_ap *val)
{
	if (t == '%')
		return (p_percent(fmt, ap, val));
	if (t == 'c' || t == 'C')
		return (p_char(fmt, ap, val, t));
	if (t == 's' || t == 'S')
		return (p_str(fmt, ap, val, t));
	if (t == 'p')
		return (p_pointer(fmt, ap, val));
	if (t == 'd' || t == 'i' || t == 'D')
		return (p_dec(fmt, ap, val, t));
	if (t == 'o' || t == 'O')
		return (p_octal(fmt, ap, val, t));
	if (t == 'u' || t == 'U')
		return (p_unsigned_int(fmt, ap, val, t));
	if (t == 'x' || t == 'X')
		return (p_hex(fmt, ap, val, t));
	if (t == 'f' || t == 'F')
		return (p_float(fmt, ap, val, t));
	return (SUCCESS_END);
}

static char		*p_find_type(char *s)
{
	char		*type;
	char		*tmp;

	type = "cCsSpdDioOuUxXfF%";
	tmp = type;
	while (*s && (type = tmp))
	{
		s++;
		while (*type)
		{
			if (*s == *type)
				return (ft_strchr(s, *type));
			type++;
		}
	}
	return (ERR_TYPE);
}

static size_t	undef(va_list *ap, char *fmt, t_ap *new)
{
	char		*tmp;
	size_t		len;
	int			format[20];

	ft_memset(format, 0, sizeof(int) * 20);
	tmp = fmt + 1;
	while (FLAGS(*tmp) || MIN_WIDTH(*tmp) || PREC_DOT(*tmp) ||
			PREC(*tmp) || MODIF(*tmp))
		tmp++;
	TYPE = *tmp;
	len = p_errtype(fmt, p_format_parcer(fmt, ap, format), format, new);
	return (len);
}

int				p_parcer(va_list *ap, char *fmt, t_ap *val, int x)
{
	char		*tmp;
	size_t		len;

	tmp = fmt;
	while (*fmt)
	{
		if (*fmt != '%' && ((tmp = ft_strchr(fmt, '%')) || !tmp))
		{
			len = ft_strlen(fmt) - (tmp ? ft_strlen(tmp) : 0);
			if (!(val->str = ft_strndup(fmt, len)))
				return (ERR_MEMORY);
			fmt += len;
		}
		else if (tmp && (tmp = p_find_type(fmt)))
		{
			if (!(x = p_fill(*tmp, fmt, ap, val)))
				return (ERR_MEMORY);
			fmt = (x > 1 ? fmt + x : tmp + 1);
		}
		else
			fmt += undef(ap, fmt, val);
		if (*fmt && !(val = p_lstcreate(val)))
			return (ERR_MEMORY);
	}
	return (SUCCESS_END);
}
