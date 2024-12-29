/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:07:22 by asajed            #+#    #+#             */
/*   Updated: 2024/12/23 18:53:16 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_sign(const char *str, int *i, va_list lst, char c)
{
	int		n;
	va_list	ls;

	while ((str[(*i)] == ' ' || str[(*i)] == '+'))
	{
		if (str[(*i)] == '+' && c == ' ')
			c = '+';
		(*i)++;
	}
	if (ft_specifier(str, *i))
	{
		va_copy(ls, lst);
		n = va_arg(ls, int);
		va_end(ls);
		if (n >= 0)
			return (ft_putchar(c));
		return (0);
	}
	return (0);
}

int	ft_addnum(const char *str, int *i, va_list lst)
{
	long	len;
	int		count;

	len = 0;
	while ((str[(*i)] == '-' || str[(*i)] == '0') && str[(*i)])
		(*i)++;
	if (str[(*i)] == '+' || str[(*i)] == ' ')
		ft_sign(str, i, lst, str[(*i)]);
	len = (ft_atoi(str, i));
	if (len > 2147483647)
		return (-1);
	if (str[(*i)] == '%')
		return (check_argprint(str[(*i)], lst, str, i));
	count = ft_strchr(str, *i, lst) + check_argprint(str[(*i)], lst, str, i);
	if (count < len)
	{
		while (count < len)
			count += ft_putchar(' ');
		return (len);
	}
	return (count);
}
