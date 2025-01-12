/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:32:43 by asajed            #+#    #+#             */
/*   Updated: 2025/01/11 21:26:07 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

int get_right_position(int num, t_list *stack)
{
    t_list *temp;
    int i;

    temp = stack;
    i = 0;

    while (temp && temp->next)
    {
        if (temp->num < num && temp->next->num > num)
            return (i + 1);
        temp = temp->next;
        i++;
    }
    return (i);
}


void insert(t_list **stack_a, t_list **stack_b)
{
    int i;
    int lst_size;

    if (!(*stack_b) )
    {
        pb(stack_b, stack_a);
        return ;
    }
    lst_size = ft_lstsize(*stack_b);
    i = get_right_position((*stack_a)->num,*stack_b);
    if (i > lst_size / 2)
    {
        while (lst_size - i > 0)
        {
            rrb(stack_b);
            i++;
        }
    }
    else
    {
        while (i--)
            rb(stack_b);
    }
    pb(stack_b, stack_a);
}

void	ft_addsortlist(char **av, t_list **stack_a, int i, int j)
{
	int	num;

	num = -1;
	while (av[i])
	{
		if (ft_checkargs(av[i]) <= 1)
			handle_err(av[i], stack_a);
		if (ft_checkargs(av[i]) > 1)
		{
			ft_addsortlist(ft_split(av[i], ' '), stack_a, 0, -1);
			if (ft_checkargs(av[i + 1]))
				i++;
			else
				break ;
		}
		else
		{
			num = ft_aatoi(av[i]);
			ft_lstadd_back(stack_a, num);
            if (j == -1)
                free(av[i]);
			i++;
		}
	}
    if (j == -1)
    {
        free(av);
    }
	ft_check_double(stack_a);
}

int	ft_is_sorted(t_list *head)
{
	if (!head)
		return (-1);
	while (head->next)
	{
		if (head->num > head->next->num)
			return (0);
		head = head->next;
	}
	return (1);
}

