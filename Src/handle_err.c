/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:50:12 by asajed            #+#    #+#             */
/*   Updated: 2025/01/03 16:03:05 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_check_double(t_list *head)
{
    t_list *tmp;

    if (!head)
		return ;
    while (head)
    {
        tmp = head;
        while (tmp->next)
        {
            if (head->num == tmp->next->num)
	    	{
                ft_printf("Error");
                exit(1);
	    	}
            tmp = tmp->next;
        }
        head = head->next;
    }
}