/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:01:50 by asajed            #+#    #+#             */
/*   Updated: 2025/01/10 11:41:43 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*z;

	i = 0;
	z = s;
	while (i < n)
	{
		z[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(count * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*v;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = 0;
	i = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		return (malloc(1));
	if (len > s_len - start)
		len = s_len - start;
	v = (char *)malloc(len + 1);
	if (!v)
		return (NULL);
	while (i < len && s[start])
	{
		v[i] = s[start];
		i++;
		start++;
	}
	v[i] = '\0';
	return (v);
}
