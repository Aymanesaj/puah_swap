/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:12:40 by asajed            #+#    #+#             */
/*   Updated: 2024/12/23 18:54:30 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strchr(const char *s, int i, va_list lst)
{
	va_list	ls;
	int		j;

	va_copy(ls, lst);
	j = va_arg(ls, int);
	va_end(ls);
	if (j < 0)
		return (0);
	while (s[i] != '%' && i >= 0)
	{
		if (s[i] == '+' || s[i] == ' ')
			return (1);
		i--;
	}
	return (0);
}
