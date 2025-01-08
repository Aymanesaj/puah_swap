/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortthestack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:20:54 by asajed            #+#    #+#             */
/*   Updated: 2025/01/08 10:46:29 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

void    ft_remove(t_list **list, int index)
{
    t_list *tmp;
    t_list *next;

    if (!list || !(*list) || index < 0)
        return ;
    tmp = *list;
    while (tmp && index--)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    *list = tmp;
}


void	sort_list(t_list **head)
{
	t_list	*tmp;
	int		swapped;

	if (!(*head))
		return ;
	tmp = *head;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		tmp = *head;
		while (tmp && tmp->next)
		{
			if (tmp->num > tmp->next->num)
			{
				ft_swap(tmp);
				swapped = 1;
			}
			tmp = tmp->next;
		}
	}
}

t_list    *sortedstack(t_list **stack_a)
{
    t_list  *sorted;
    t_list  *tmp;

    tmp = *stack_a;
    sorted = NULL;
    while (tmp)
    {
        ft_lstadd_back(&sorted, tmp->num);
        tmp = tmp->next;
    }
    sort_list(&sorted);
    return (sorted);
}

int     in_the_chunk(int num, t_list *stack, int chunk_size)
{
    int i;

    i = 0;
    while (stack && i < chunk_size)
    {
        if (stack->num == num)
            return (1);
        stack = stack->next;
        i++;
    }
    return (0);
}

int     position(t_list *stack, t_list *sorted, int chunk_size)
{
    int i;

    i = 0;
    while (!in_the_chunk(stack->num, sorted, chunk_size))
    {
        stack = stack->next;
        i++;
    }
    return (i);
}
int	ft_b_is_sorted(t_list *head)
{
	if (!head)
		return (-1);
	while (head->next)
	{
		if (head->num < head->next->num)
			return (0);
		head = head->next;
	}
	return (1);
}

void    ft_sort_b(t_list **n)
{
    if (ft_lstsize(*n) == 3)
    {
        if (ft_b_is_sorted(*n))
            return ;
        if ((*n)->num < (*n)->next->num && (*n)->num < (*n)->next->next->num)
            rb(n);
        else if ((*n)->num < (*n)->next->num)
            sb(*n);
        else if ((*n)->num > (*n)->next->num && (*n)->next->next->num > (*n)->num)
            rrb(n);
        else if ((*n)->num > (*n)->next->num
                && (*n)->next->num < (*n)->next->next->num)
        {
            sb(*n);
            rb(n);
        }
    }
    else if (ft_lstsize(*n) == 2)
        sb(*n);
}

int	ft_min_index(t_list *lst, int min)
{
	int	i;

	if (!lst)
		return (-1);
    i = 0;
	while (lst)
	{
		if (lst->num == min)
			return (i);
		lst = lst->next;
        i++;
    }
	return (i);
}

void    sort_chunk(t_list **stack_a, t_list **stack_b, int  chunk_size, t_list **sorted)
{
    int     size;
    int     pos;
    int     i;
    int     min_index;

    i = 0;
    pos = position(*stack_a, *sorted, chunk_size);
    while (i <= chunk_size && ft_lstsize(*stack_a) >= 6)
    {
        min_index = ft_min_index(*stack_a, ft_find_min(*sorted));
        size = ft_lstsize(*stack_a);
        pos = position(*stack_a, *sorted, chunk_size);
        if (pos == 0)
            pb(stack_b, stack_a);
        else if (pos == 1)
        {
            sa(*stack_a);
            pb(stack_b, stack_a);
        }
        else if (pos > (size / 2) || min_index == size - 1 || min_index == size - 2)
        {
            while (!in_the_chunk((*stack_a)->num, *sorted, chunk_size))
                rra(stack_a);
        }
        else if (pos <= (size / 2))
        {
            while (!in_the_chunk((*stack_a)->num, *sorted, chunk_size))
                ra(stack_a);
        }
        ft_sort_b(stack_b);
        i++;
    }
    while(!ft_b_is_sorted(*stack_b))
        ft_sort_b(stack_b);
    if (ft_lstsize(*stack_a) <= chunk_size)
    {
        ft_sort_low(stack_a, stack_b);
        ft_remove(sorted, ft_lstsize(*sorted));
        free(sorted);
        while (ft_lstsize(*stack_b))
            pa(stack_a, stack_b);
        return;
    }
    ft_remove(sorted, chunk_size);
}

