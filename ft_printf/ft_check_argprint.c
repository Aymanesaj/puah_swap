/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argprint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:45:02 by asajed            #+#    #+#             */
/*   Updated: 2024/12/23 18:53:30 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_argprint(char c, va_list lst, const char *str, int *i)
{
	if (c == 'c')
		return ((ft_putchar((char)va_arg(lst, int))));
	else if (c == 'd' || c == 'i')
		return ((ft_putnbr(va_arg(lst, int))));
	else if (c == 'u')
		return ((ft_unsign(va_arg(lst, unsigned int))));
	else if (c == 's')
		return ((ft_putstr(va_arg(lst, char *))));
	else if (c == '%')
		return ((ft_putchar('%')));
	else if (c == 'p')
		return ((ft_address(va_arg(lst, unsigned long long),
							"0123456789abcdef")));
	else if (c == 'x')
		return ((ft_putnbr_base(va_arg(lst, unsigned int),
								"0123456789abcdef")));
	else if (c == 'X')
		return ((ft_putnbr_base(va_arg(lst, unsigned int),
								"0123456789ABCDEF")));
	else if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '.'
			|| c == '0' || ft_isdigit(c))
		return ((bonus_flags(str, lst, i)));
	return (-1);
}
