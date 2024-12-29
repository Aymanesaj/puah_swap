/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:02:36 by asajed            #+#    #+#             */
/*   Updated: 2024/12/27 16:32:14 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_swap(t_list *stack)
{
    int tmp;

    if (!stack || !stack->next)
    {
        return ;
    }
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}

void	sa(t_list *stack_a)
{
    ft_swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_list *stack_b)
{
    ft_swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
	ft_printf("ss\n");
}
