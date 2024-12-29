/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:13:13 by asajed            #+#    #+#             */
/*   Updated: 2024/12/23 18:54:25 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_typestr(va_list sec)
{
	char	*s;

	s = va_arg(sec, char *);
	if (!s)
		return (6);
	return (ft_strlen(s));
}

int	ft_checktype(va_list sec, char c, int i)
{
	int	arg;
	int	count;

	count = 0;
	arg = 0;
	if (c == 'd' || c == 'i')
	{
		arg = va_arg(sec, int);
		if (arg < 0 || i)
			count++;
		return (count + ft_len(arg));
	}
	if (c == 'u')
		return (ft_lenu(va_arg(sec, unsigned int)));
	if (c == 's')
		return (ft_typestr(sec));
	if (c == 'p')
		return ((unsigned long)ft_strx(va_arg(sec, unsigned long)) + 2);
	if (c == '%')
		return (-2);
	return (1);
}

int	ft_spaces(const char *str, int *i, va_list lst)
{
	long	len;
	int		count;
	int		printed;
	va_list	sec;

	len = 0;
	len = ft_atoi(str, i);
	if (len > 2147483647)
		return (-1);
	va_copy(sec, lst);
	count = ft_checktype(sec, str[*i], ft_strchr(str, *i, lst));
	if (count == -2)
		return (check_argprint(str[(*i)], lst, str, i));
	printed = count;
	while (count < len)
		count += ft_putchar(' ');
	printed = count - printed;
	va_end(sec);
	return (printed + check_argprint(str[(*i)], lst, str, i));
}
