/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:50:12 by asajed            #+#    #+#             */
/*   Updated: 2025/01/11 22:18:48 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_check_double(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*head;

	head = *stack_a;
	if (!head)
		return ;
	while (head)
	{
		tmp = head;
		while (tmp->next)
		{
			if (head->num == tmp->next->num)
				ft_remove(stack_a, ft_lstsize(*stack_a));
			tmp = tmp->next;
		}
		head = head->next;
	}
}

int	ft_checkargs(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (ft_isdigit(s[i]) && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

void	handle_err(char *str, t_list **stack_a)
{
	int j;

	j = 0;
	if ((str[j] == '+' || str[j] == '-') && str[j + 1] != '\0')
		j++;
	while (ft_isdigit(str[j]))
		j++;
	if (!ft_isdigit(str[j]) && str[j] != '\0')
	{
		ft_printf("Error\n");
		ft_remove(stack_a, ft_lstsize(*stack_a));
		exit(1);
	}
}

void    ft_clean_and_free(t_list **stack_a, t_list **stack_b)
{
    ft_remove(stack_a, ft_lstsize(*stack_a));
    ft_remove(stack_b, ft_lstsize(*stack_b));
    ft_printf("Error\n");
    exit (1);
}
