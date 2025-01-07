/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:50:12 by asajed            #+#    #+#             */
/*   Updated: 2025/01/06 12:08:55 by asajed           ###   ########.fr       */
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

int ft_checkargs(char *s)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (!s)
        return (0);
    while (s[i])
    {
        if (ft_isdigit(s[i]) && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			j++;
        i++;
    }
    return (j);
}

void    handle_err(char *str)
{
    int j;

    j = 0;
    if ((str[j] == '+' || str[j] == '-') && str[j + 1] != '\0')
        j++;
    while (ft_isdigit(str[j]))
        j++;
    if (!ft_isdigit(str[j]) && str[j] != '\0')
    {
        ft_printf("Error");
    	exit(1);
    }
}