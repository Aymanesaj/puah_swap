/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:33:17 by asajed            #+#    #+#             */
/*   Updated: 2024/12/30 15:11:10 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *create_node(int num)
{
    t_list *new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
		return (NULL);
    new_node->num = num;
    new_node->next = NULL;
    return (new_node);
}

void	ft_lstadd_back(t_list **lst , int num)
{
	t_list	*p;
	t_list	*new_node;

	new_node = create_node(num);
	if (!(*lst))
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

int	main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;
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
	while (stack_a)
	{
		ft_printf("%d -> ", stack_a->num);
		stack_a = stack_a->next;
	}
	ft_printf("NULL");
}
