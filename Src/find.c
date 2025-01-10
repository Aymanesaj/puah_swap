/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:21:18 by asajed            #+#    #+#             */
/*   Updated: 2025/01/10 11:31:42 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_min(t_list *lst)
{
	int	min;

	if (!lst)
		return (-1);
	min = lst->num;
	lst = lst->next;
	while (lst)
	{
		if (lst->num < min)
		{
			min = lst->num;
		}
		lst = lst->next;
	}
	return (min);
}

int	ft_find_max(t_list *lst)
{
	int max;

	if (!lst)
		return (-1);
	max = lst->num;
	lst = lst->next;
	while (lst)
	{
		if (lst->num > max)
		{
			max = lst->num;
		}
		lst = lst->next;
	}
	return (max);
}

int ft_find_from_last(t_list *stack_a, t_list *sorted, int chunk_size)
{
	int 	num;
	int		size;
	t_list	*tmp;

	if (!sorted || !stack_a)
		return (-1);
	size = ft_lstsize(stack_a);
	if (!size)
		return (-1);
	size = size / 2;
	tmp = stack_a;
	while (size)
	{
		tmp = tmp->next;
		size--;
	}
	while(tmp)
	{
		if (in_the_chunk(tmp->num, sorted, chunk_size))
			num = tmp->num;
		tmp = tmp->next;
	}
	num = ft_index(stack_a, num);
	return (num);
}

int	ft_find_from_start(t_list *current, t_list *sorted, int index_first, int chunk_size)
{
	t_list *sorted_current;
	int		current_index;
	int		j;
	
	current_index = 0;
	j = 0;
    while (current)
	{
        sorted_current = sorted;
        while (sorted_current && j < chunk_size)
		{
            if (current->num <= sorted_current->num)
			{
                if (index_first == -1)
                    index_first = current_index;
                break;
            }
            sorted_current = sorted_current->next;
            j++;
        }
        current = current->next;
        current_index++;
    }
	return (index_first);
}

int find_optimal_hold(t_list *stack_a, t_list *sorted, int chunk_size, int stack_size)
{
    int index_first;
    int index_second;

    index_first = -1;
    index_second = -1;
	index_first = ft_find_from_start(stack_a, sorted, index_first, chunk_size);
	index_second = ft_find_from_last(stack_a, sorted, chunk_size);
	if (index_first <= stack_size / 2)
		return (index_first);
	else
        return (index_second);
}
