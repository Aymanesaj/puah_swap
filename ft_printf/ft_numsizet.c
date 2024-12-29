/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numsizet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:15:09 by asajed            #+#    #+#             */
/*   Updated: 2024/12/23 18:53:57 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_unsign(unsigned int n)
{
	char	c;
	int		result;

	result = 0;
	if ((n / 10) > 0)
		result += ft_unsign((n / 10));
	c = (n % 10) + '0';
	result += write(1, &c, 1);
	return (result);
}
