/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:18:06 by asajed            #+#    #+#             */
/*   Updated: 2025/01/05 17:48:52 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	countword(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] == c && c != '\0')
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

void	ft_free(char **strs, int j)
{
	while (j >= 0)
	{
		free(strs[j]);
		j--;
	}
	free(strs);
}

int	ft_ft(char **strs, char const *s, char c, int j)
{
	int	i;
	int	start;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (start < i)
		{
			strs[j] = ft_substr(s, start, i - start);
			if (!strs[j])
			{
				ft_free(strs, --j);
				return (0);
			}
			j++;
		}
	}
	strs[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char **strs;
	int i;
	int j;

	if (s == NULL)
		return (NULL);
	j = countword(s, c);
	strs = (char **)malloc((j + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	j = 0;
	i = ft_ft(strs, s, c, j);
	if (i == 0)
		return (NULL);
	return (strs);
}