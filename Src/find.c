/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:21:18 by asajed            #+#    #+#             */
/*   Updated: 2025/01/11 20:15:05 by asajed           ###   ########.fr       */
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
	int	max;

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

int	ft_find_from_last(t_list *stack_a, t_list *sorted, int chunk_size)
{
	int		num;
	t_list	*tmp;

	if (!sorted || !stack_a)
		return (-1);
	tmp = stack_a;
	while (tmp)
	{
		if (in_the_chunk(tmp->num, sorted, chunk_size))
			num = tmp->num;
		tmp = tmp->next;
	}
	num = ft_index(stack_a, num);
	return (num);
}

int	ft_find_from_start(t_list *current, t_list *sorted, int index_first,
		int chunk_size)
{

	index_first = 0;
	while (!in_the_chunk(current->num, sorted, chunk_size))
	{
		current = current->next;
		index_first++;
	}
	return (index_first);
}

int	find_optimal_hold(t_list *stack_a, t_list *sorted, int chunk_size,
		int stack_size)
{
	int	index_first;
	int	index_second;
	int	index;

	index_first = 0;
	index_second = 0;
	index_first = ft_find_from_start(stack_a, sorted, index_first, chunk_size);
	index_second = ft_find_from_last(stack_a, sorted, chunk_size);
	index = closest_to(index_first, index_second, stack_size);
	return (index);
}
