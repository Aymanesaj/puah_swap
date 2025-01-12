/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:15:16 by asajed            #+#    #+#             */
/*   Updated: 2025/01/11 21:17:17 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if ((s1[i] && !s2[i]) || (!s1[i] && s2[i]))
		return (0);
	return (1);
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

int	check_get_line(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = get_next_line(0);
	if (ft_strcmp(str, "Error\n"))
        ft_clean_and_free(stack_a, stack_b);
	while (str)
	{
		if (ft_strcmp(str, "sa\n"))
			sa(*stack_a);
		else if (ft_strcmp(str, "sb\n"))
			sb(*stack_b);
		else if (ft_strcmp(str, "ss\n"))
			ss(*stack_a, *stack_b);
		else if (ft_strcmp(str, "pa\n"))
			pa(stack_a, stack_b);
		else if (ft_strcmp(str, "pb\n"))
			pb(stack_b, stack_a);
		else if (ft_strcmp(str, "ra\n"))
			ra(stack_a);
		else if (ft_strcmp(str, "rb\n"))
			rb(stack_b);
		else if (ft_strcmp(str, "rr\n"))
			rr(stack_a, stack_b);
		else if (ft_strcmp(str, "rra\n"))
			rra(stack_a);
		else if (ft_strcmp(str, "rrb\n"))
			rrb(stack_b);
		else if (ft_strcmp(str, "rrr\n"))
			rrr(stack_a, stack_b);
        else
            ft_clean_and_free(stack_a, stack_b);
		free(str);
		str = get_next_line(0);
	}
	return (0);
}


int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	ft_addsortlist(av, &stack_a, 1, 0);
	check_get_line(&stack_a, &stack_b);
	if (ft_is_sorted(stack_a))
		ft_printf("OK");
	else
		ft_printf("KO");
	ft_remove(&stack_a, ft_lstsize(stack_a));
	ft_remove(&stack_b, ft_lstsize(stack_b));
}
