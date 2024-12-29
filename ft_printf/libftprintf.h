/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:44:18 by asajed            #+#    #+#             */
/*   Updated: 2024/12/01 14:38:55 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(const char *s);
int		ft_putnbr(int n);
int		ft_printf(const char *str, ...);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_unsign(unsigned int n);
int		ft_address(unsigned long long address, char *base);
int		bonus_flags(const char *str, va_list lst, int *i);
int		check_argprint(char c, va_list lst, const char *str, int *i);
int		ft_isdigit(int c);
int		ft_givesign(const char *str, int *i, va_list lst, char c);
int		ft_padding(const char *str, int *i, va_list lst, char c);
int		ft_addnum(const char *str, int *i, va_list lst);
int		ft_len(int n);
int		ft_spaces(const char *str, int *i, va_list lst);
long	ft_atoi(const char *str, int *i);
int		ft_handlestr(va_list lst, int len);
int		ft_lenu(unsigned int n);
int		ft_strlen(const char *s);
int		ft_strx(unsigned int nbr);
int		ft_specifier(const char *str, int i);
int		ft_strchr(const char *s, int i, va_list lst);
int		ft_positive(const char *str, char c, int num);
char	ft_checkdot0(const char *str, int *i, int *len, va_list lst);
int		ft_gothrough(const char *str, int *i, char *c);

#endif
