/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:08:54 by asajed            #+#    #+#             */
/*   Updated: 2024/12/23 18:53:26 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_skipflags(const char *str, int i)
{
	while (str[i] == '#' || str[i] == '0' || str[i] == '.'
		|| ft_isdigit(str[i]))
		i++;
	if (str[i] == 'x' || str[i] == 'X')
		return (i);
	return (-1);
}

int	ft_hash(const char *str, int *i, va_list lst)
{
	unsigned int	l;

	l = va_arg(lst, unsigned long long);
	while (str[(*i)] == '#')
		(*i)++;
	if (!l)
		return (ft_putchar('0'));
	if (str[(*i)] == 'x')
		return ((write(1, "0x", 2) + ft_putnbr_base(l, "0123456789abcdef")));
	else if (str[(*i)] == 'X')
		return ((write(1, "0X", 2) + ft_putnbr_base(l, "0123456789ABCDEF")));
	return (check_argprint(str[(*i)], lst, str, i));
}

int	ft_hashcomb(const char *str, int *i, va_list lst)
{
	unsigned long long	l;
	va_list				ls;
	int					j;

	va_copy(ls, lst);
	l = va_arg(ls, unsigned long long);
	va_end(ls);
	while (str[(*i)] == '#')
		(*i)++;
	j = ft_skipflags(str, *i);
	if (!l)
		return (check_argprint(str[(*i)], lst, str, i));
	if (str[j] == 'x')
		return ((write(1, "0x", 2) + check_argprint(str[(*i)], lst, str, i)));
	else if (str[j] == 'X')
		return ((write(1, "0X", 2) + check_argprint(str[(*i)], lst, str, i)));
	return (check_argprint(str[(*i)], lst, str, i));
}

int	bonus_flags(const char *str, va_list lst, int *i)
{
	if (str[(*i)] == '-')
		return (ft_addnum(str, i, lst));
	else if (str[(*i)] == '+' || str[(*i)] == ' ')
		return (ft_givesign(str, i, lst, str[(*i)]));
	else if (str[(*i)] == '#' && (str[(*i) + 1] == 'X' || str[(*i) + 1] == 'x'))
		return (ft_hash(str, i, lst));
	else if (str[(*i)] == '#' && (str[(*i) + 1] != 'X' && str[(*i) + 1] != 'x'))
		return (ft_hashcomb(str, i, lst));
	else if (str[(*i)] == '.' || str[(*i)] == '0')
		return (ft_padding(str, i, lst, str[*i]));
	else if (ft_isdigit(str[(*i)]))
		return (ft_spaces(str, i, lst));
	return (-1);
}
