/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:57:35 by asajed            #+#    #+#             */
/*   Updated: 2025/01/06 11:35:05 by asajed           ###   ########.fr       */
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
void    ra(t_list **stack_a);
void    rb(t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);
void    rra(t_list **stack_a);
void    rrb(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);
int     ft_find_min(t_list *lst);
int	    ft_find_max(t_list *lst);
void    ft_check_double(t_list *head);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int     ft_checkargs(char *s);
void    handle_err(char *str);

#endif
