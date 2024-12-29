/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:12:11 by asajed            #+#    #+#             */
/*   Updated: 2024/12/28 09:42:42 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_aatoi(char *str)
{
	int	len;
    int	i;
	int	sign;

	len = 0;
    i = 0;
    sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	if (!ft_isdigit(str[i]) && !(str[i] == '+' || str[i] == '-'))
	{
		ft_printf("Error");
		exit (1);
	}
	while (ft_isdigit(str[i]))
	{
		len = len * 10 + (str[i] - '0');
		i++;
	}
	if (!ft_isdigit(str[i]) && str[i]!= '\0')
	{
		ft_printf("Error");
		exit (1);
	}
	return (len * sign);
}