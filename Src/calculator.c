/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:03:00 by asajed            #+#    #+#             */
/*   Updated: 2025/01/10 11:19:20 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     ft_chunk_size(t_list *stack)
{
    int size;
    int chunk_size;

    if (!stack)
        return (0);
    size = ft_lstsize(stack);
    if (size >= 500)
        chunk_size = size / 12;
    else if (size >= 100)
        chunk_size = size / 5;
    else
        chunk_size = size / 4;
    return (chunk_size);
}
