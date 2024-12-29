/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:57:35 by asajed            #+#    #+#             */
/*   Updated: 2024/12/28 18:51:03 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/libftprintf.h"
#include <stdlib.h>

typedef struct s_list
{
    int num;
    struct s_list *next;  
}   t_list;

int     ft_dstrlen(char **str);
int     ft_aatoi(char *str);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void    pa(t_list **stack_a, t_list **stack_b);
void    pb(t_list **stack_b, t_list **stack_a);

#endif