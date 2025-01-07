#include "../push_swap.h"

int	ft_find_min(t_list *lst)
{
	int min;

	if (!lst)
		return (-1);
	min = lst->num;
	lst = lst->next;
	while (lst)
	{
		if (lst->num < min)
		{
			min = lst->num;
		}
		lst = lst->next;
	}
	return (min);
}

int	ft_find_max(t_list *lst)
{
	int max;

	if (!lst)
		return (-1);
	max = lst->num;
	lst = lst->next;
	while (lst)
	{
		if (lst->num > max)
		{
			max = lst->num;
		}
		lst = lst->next;
	}
	return (max);
}