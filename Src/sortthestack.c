/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortthestack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:20:54 by asajed            #+#    #+#             */
/*   Updated: 2025/01/11 22:18:35 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

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

int	ft_b_is_sorted(t_list *head)
{
	if (!head)
		return (1);
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
    else if (ft_lstsize(*n) == 2 && !ft_b_is_sorted(*n))
        sb(*n);
}

int	ft_index(t_list *lst, int min)
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

void    both_at_the_same_time(t_list **stack_a, t_list **stack_b, int min_in_a)
{
    int max_in_b;

    if (!stack_a || !stack_b)
        return ;
    max_in_b = ft_index(*stack_b, ft_find_max(*stack_b));
    if (max_in_b >= (ft_lstsize(*stack_b) / 2) && min_in_a >= (ft_lstsize(*stack_a) / 2))
        rrr(stack_a, stack_b);
    else if (max_in_b < (ft_lstsize(*stack_b) / 2) && min_in_a < (ft_lstsize(*stack_a) / 2))
        rr(stack_a, stack_b);
    if (max_in_b == 1 && min_in_a == 1)
        ss(*stack_a, *stack_b);
}

void    push_back(t_list **stack_b, t_list **stack_a)
{
    int max_index;
    

    while (ft_lstsize(*stack_b))
    {
        max_index = ft_index(*stack_b, ft_find_max(*stack_b));
        if (max_index == 0)
            pa(stack_a, stack_b);
        else if (max_index == 1)
            sb(*stack_b);
        else if (ft_lstsize(*stack_b) <= 3)
        {
            // while (!ft_b_is_sorted(*stack_b))
            ft_sort_b(stack_b);
        }
        else if (max_index >= (ft_lstsize(*stack_b) / 2))
            rrb(stack_b);
        else
            rb(stack_b);
    }
}

void    sort_chunk(t_list **stack_a, t_list **stack_b, int  chunk_size, t_list **sorted)
{
    int pos;
    int size;

    while (sorted && ft_lstsize(*stack_a))
    {
        size = ft_lstsize(*stack_a);
        pos = find_optimal_hold(*stack_a, *sorted, chunk_size, size);
        if (pos == 0)
        {
            pb(stack_b, stack_a);
            if (ft_lstsize(*stack_b) > 1 && (*stack_b)->num < (*stack_b)->next->num)
                rb(stack_b);
            return ;
        }
        else if (pos == 1)
        {
            sa(*stack_a);
            pb(stack_b, stack_a);
            if (ft_lstsize(*stack_b) > 1 && (*stack_b)->num < (*stack_b)->next->num)
                rb(stack_b);
            return ;
        }
        else if (pos <= size / 2)
        {
            while (!in_the_chunk((*stack_a)->num, *sorted, chunk_size)
                && !in_the_chunk((*stack_a)->next->num, *sorted, chunk_size))
                ra(stack_a);
        }
        else if (pos > size / 2)
        {
            while (!in_the_chunk((*stack_a)->num, *sorted, chunk_size))
                rra(stack_a);
        }
    }
}

void    sort_with_chunks(t_list **stack_a, t_list **stack_b, int  chunk_size, t_list **sorted)
{
    int     i;
    int     size;

    i = chunk_size;
    size = ft_lstsize(*stack_a);
    while (sorted && i && size)
    {
        sort_chunk(stack_a, stack_b, chunk_size, sorted);
        ft_sort_b(stack_b);
        i--;
    }
    if (ft_lstsize(*stack_a) <= 3)
    {
        ft_sort_three(stack_a);
        ft_remove(sorted, ft_lstsize(*sorted));
        push_back(stack_b, stack_a);
        return ;
    }
    ft_remove(sorted, chunk_size);
}

