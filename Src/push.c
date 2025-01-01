/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:24:34 by asajed            #+#    #+#             */
/*   Updated: 2024/12/30 15:09:20 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// go to last node - 1
// tmp = last node
// last node - 1 next == null
// last node in stack b next == tmp

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// tmp == stack a's head
// stack a head == tmp's next
// stack b's last next == tmp
// tmp next == null

void	ft_push(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (!src || !(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_printf("pb\n");
}
