/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:02:12 by asajed            #+#    #+#             */
/*   Updated: 2024/12/01 14:30:19 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_checkprints(const char *str, int *i, va_list lst)
{
	int	result;
	int	j;

	result = 0;
	(*i)++;
	if (str[*i] == '\0')
		return (-1);
	j = check_argprint(str[*i], lst, str, i);
	if (j < 0)
		return (-1);
	result = j;
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		result;
	int		j;
	int		i;

	result = 0;
	i = 0;
	va_start(lst, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			j = ft_checkprints(str, &i, lst);
			if (j < 0)
				return (-1);
			result += j;
		}
		else
			result += ft_putchar(str[i]);
		i++;
	}
	va_end(lst);
	return (result);
}
