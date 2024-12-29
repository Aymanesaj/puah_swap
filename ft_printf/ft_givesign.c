/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_givesign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:38:09 by asajed            #+#    #+#             */
/*   Updated: 2024/12/23 18:53:38 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_givesign(const char *str, int *i, va_list lst, char c)
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
		if (n < 0)
			return (check_argprint(str[(*i)], lst, str, i));
		else
			return (ft_putchar(c) + check_argprint(str[(*i)], lst, str, i));
	}
	return (check_argprint(str[(*i)], lst, str, i));
}
