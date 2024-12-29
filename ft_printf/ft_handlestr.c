/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlestr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 02:17:16 by asajed            #+#    #+#             */
/*   Updated: 2024/12/23 18:53:44 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_handlestr(va_list lst, int len)
{
	char	*str;
	int		count;

	str = va_arg(lst, char *);
	if (!str)
		return (0);
	count = ft_strlen(str);
	if (count >= len)
		return (write(1, str, len));
	ft_putstr(str);
	return (count);
}
