/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:35:41 by asajed            #+#    #+#             */
/*   Updated: 2024/12/23 18:54:00 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_handlex(va_list lst, int len, const char *str, int *i)
{
	va_list			sec;
	int				printed;
	int				count;
	unsigned int	num;

	printed = 0;
	va_copy(sec, lst);
	num = va_arg(sec, unsigned int);
	count = ft_strx(num);
	if (num == 0 && len == 0)
		return (0);
	while (len > count)
	{
		printed += ft_putchar('0');
		count++;
	}
	va_end(sec);
	return (printed + check_argprint(str[(*i)], lst, str, i));
}

int	ft_handle_unsign(va_list lst, int len)
{
	unsigned int	num;
	int				count;
	int				printed;

	printed = 0;
	num = va_arg(lst, unsigned int);
	if (num == 0 && len == 0)
		return (0);
	count = ft_lenu(num);
	while (len > count)
	{
		printed += ft_putchar('0');
		count++;
	}
	return ((printed + ft_unsign(num)));
}

int	ft_negative(int *count, int *sign, char c, int num)
{
	if (num < 0)
	{
		if (c == '0')
			(*count)++;
		*sign = -1;
		return (ft_putchar('-'));
	}
	return (0);
}

int	ft_handlenum(const char *str, va_list lst, int len, char c)
{
	int	num;
	int	count;
	int	sign;
	int	printed;

	sign = 1;
	printed = 0;
	num = va_arg(lst, int);
	count = ft_len(num);
	count += ft_positive(str, c, num);
	printed += ft_negative(&count, &sign, c, num);
	if (num == 0 && len == 0)
		return (0);
	while (len > count)
	{
		printed += ft_putchar('0');
		count++;
	}
	if (num == -2147483648)
		return ((printed + ft_unsign(num * sign)));
	return (printed + ft_putnbr((num * sign)));
}

int	ft_padding(const char *str, int *i, va_list lst, char c)
{
	int	len;
	int	j;

	len = 0;
	j = *i;
	while (str[j] != '%')
		j--;
	if (ft_gothrough(str, i, &c) == -1)
		return (ft_addnum(str, i, lst));
	len = ft_atoi(str, i);
	if (c == '0')
		c = ft_checkdot0(str, i, &len, lst);
	if (str[(*i)] == 'd' || str[(*i)] == 'i')
		return (ft_handlenum(str + j, lst, len, c));
	if (str[(*i)] == 'u')
		return (ft_handle_unsign(lst, len));
	if (str[(*i)] == 's' && c == '.')
		return (ft_handlestr(lst, len));
	if (str[(*i)] == 'x' || str[(*i)] == 'X')
		return (ft_handlex(lst, len, str, i));
	return (check_argprint(str[(*i)], lst, str, i));
}
