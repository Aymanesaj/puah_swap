/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:35:10 by asajed            #+#    #+#             */
/*   Updated: 2024/12/23 18:53:34 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_checkdot0(const char *str, int *i, int *len, va_list lst)
{
	int		j;
	int		len2;
	char	c;
	va_list	ls;

	c = '0';
	va_copy(ls, lst);
	j = va_arg(ls, int);
	va_end(ls);
	if (str[(*i)] == '.')
	{
		if (j < 0)
			(*len)--;
		(*i)++;
		len2 = ft_atoi(str, i);
		while ((*len) > len2)
		{
			ft_putchar(' ');
			(*len)--;
		}
		c = '.';
		return (c);
	}
	return (c);
}
