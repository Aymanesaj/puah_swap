/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:17:37 by asajed            #+#    #+#             */
/*   Updated: 2025/01/11 18:19:41 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


t_list	*create_node(int num)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, int num)
{
	t_list	*p;
	t_list	*new_node;

	new_node = create_node(num);
	if (!(*lst) || !lst)
	{
		*lst = new_node;
		return ;
	}
	p = *lst;
	if (!new_node)
		return ;
	while (p->next)
		p = p->next;
	p->next = new_node;
}

void	ft_sort_three(t_list **n)
{
	while (!ft_is_sorted(*n) && ft_lstsize(*n) == 3)
	{
		if (ft_is_sorted(*n))
			return ;
		else if ((*n)->num > (*n)->next->num
				&& (*n)->num > (*n)->next->next->num)
			ra(n);
		else if ((*n)->num > (*n)->next->num)
			sa(*n);
		else if ((*n)->num < (*n)->next->num
				&& (*n)->next->next->num < (*n)->num)
			rra(n);
		else if ((*n)->num < (*n)->next->num
				&& (*n)->next->num > (*n)->next->next->num)
		{
			sa(*n);
			ra(n);
		}
	}
}
