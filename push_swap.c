/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:33:17 by asajed            #+#    #+#             */
/*   Updated: 2025/01/11 21:40:37 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libftprintf.h"
#include "push_swap.h"

void	ft_sort_low(t_list **stack_a, t_list **stack_b)
{
	int		min;
	t_list	*tmp;

	min = ft_find_min(*stack_a);
	tmp = *stack_a;
	while ((ft_lstsize(*stack_a) > 3))
	{
		if (ft_is_sorted(*stack_a))
			break ;
		tmp = *stack_a;
		min = ft_find_min(*stack_a);
		if (tmp->num == min)
			pb(stack_b, stack_a);
		else if (tmp->next->num == min)
		{
			sa(*stack_a);
			pb(stack_b, stack_a);
		}
		else
			rra(stack_a);
	}
	if ((ft_lstsize(*stack_a) == 2) && !ft_is_sorted(*stack_a))
		sa(*stack_a);
	while (!ft_is_sorted(*stack_a))
		ft_sort_three(stack_a);
	while (ft_lstsize(*stack_b))
		pa(stack_a, stack_b);
}

void	print_list(t_list *head)
{
	if (!head)
	{
		ft_printf("List is empty\n");
		return ;
	}
	while (head)
	{
		ft_printf("%d ->", head->num);
		head = head->next;
	}
	ft_printf("NULL\n");
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*sorted;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
		return (0);
	ft_addsortlist(av, &stack_a, 1, 0);
	sorted = sortedstack(&stack_a);
	while (ft_lstsize(sorted) && !ft_is_sorted(stack_a))
		sort_with_chunks(&stack_a, &stack_b, ft_chunk_size(stack_a), &sorted);
	// ft_sort_low(&stack_a, &stack_b);
	ft_remove(&sorted, ft_lstsize(sorted));
	ft_remove(&stack_a, ft_lstsize(stack_a));
	ft_remove(&stack_b, ft_lstsize(stack_b));
}
