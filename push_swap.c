/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:33:17 by asajed            #+#    #+#             */
/*   Updated: 2025/01/03 15:59:05 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_listsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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
	if (ft_is_sorted(*n))
		return ;
	else if ((*n)->num > (*n)->next->num)
		sa(*n);
	else if ((*n)->num < (*n)->next->num && (*n)->next->next->num < (*n)->num)
		rra(n);
	else if ((*n)->num > (*n)->next->num && (*n)->num > (*n)->next->next->num)
		ra(n);
	else if ((*n)->num < (*n)->next->num
		&& (*n)->next->num > (*n)->next->next->num)
	{
		sa(*n);
		ra(n);
	}
}

void	ft_sort_low(t_list **stack_a, t_list **stack_b)
{
	int		min;
	t_list	*tmp;

	min = ft_find_min(*stack_a);
	tmp = *stack_a;
	while ((ft_listsize(*stack_a) > 3))
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
			if (ft_is_sorted(*stack_a))
				break ;
			pb(stack_b, stack_a);
		}
		else
		 	rra(stack_a);
	}
	while (!ft_is_sorted(*stack_a))
		ft_sort_three(stack_a);
	while (ft_listsize(*stack_b))
		pa(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		num;
	int		i;

	i = 1;
	if (ac <= 1)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	while (av[i])
	{
		num = ft_aatoi(av[i]);
		ft_lstadd_back(&stack_a, num);
		i++;
	}
	ft_check_double(stack_a);
	ft_sort_low(&stack_a, &stack_b);
	while (stack_a)
	{
		ft_printf("%d -> ", stack_a->num);
		stack_a = stack_a->next;
	}
	ft_printf("NULL");
}
