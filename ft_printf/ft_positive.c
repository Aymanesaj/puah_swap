/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:20:32 by asajed            #+#    #+#             */
/*   Updated: 2024/12/23 18:54:03 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_positive(const char *str, char c, int num)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (num >= 0 && c == '0')
	{
		while ((str[i] != 'd' || str[i] != 'i') && str[i])
		{
			if (str[i] != 'd' || str[i] != 'i')
				break ;
			if (str[i] == '+' || str[i] == ' ')
				count++;
			i++;
		}
	}
	return (count);
}
