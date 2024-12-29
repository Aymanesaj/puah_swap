/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:19:20 by asajed            #+#    #+#             */
/*   Updated: 2024/12/23 18:54:28 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_specifier(const char *str, int i)
{
	while (str[i] == '-' || ft_isdigit(str[i]) || str[i] == '.')
		i++;
	if (str[i] == 'd' || str[i] == 'i')
		return (1);
	return (0);
}
