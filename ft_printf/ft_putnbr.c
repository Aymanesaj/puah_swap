/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:42:15 by asajed            #+#    #+#             */
/*   Updated: 2024/12/23 18:54:19 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n)
{
	long	nb;
	char	c;
	int		result;

	nb = n;
	result = 0;
	if (nb < 0)
	{
		nb = -nb;
		result += write(1, "-", 1);
	}
	if ((nb / 10) > 0)
		result += ft_putnbr((nb / 10));
	c = (nb % 10) + '0';
	result += write(1, &c, 1);
	return (result);
}
