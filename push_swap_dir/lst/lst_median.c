/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10:56:12 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/04 10:56:09 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		count_elem_below(t_elem *lst, int end, int value)
{
	int		count;

	count = 0;
	while (lst && lst->value != end)
	{
		if (lst->value < value)
			count++;
		lst = lst->next;
	}
	if (lst->value < value)
		count++;
	return (count);
}

int		count_elem_above(t_elem *lst, int end, int value)
{
	int		count;

	count = 0;
	while (lst && lst->value != end)
	{
		if (lst->value > value)
			count++;
		lst = lst->next;
	}
	if (lst->value > value)
		count++;
	return (count);
}

int		stop_it(int even, int above, int below)
{
	if (!even && below == above)
		return (1);
	else if (even && below == above - 1)
		return (1);
	return (0);
}

t_elem	*lst_median(t_elem *lst, int end)
{
	t_elem	*start;
	int		even;
	int		above;
	int		below;

	start = lst;
	even = ((lst_size_at(lst, end)) % 2 == 0) ? 1 : 0;
	while (lst && lst->value != end)
	{
		above = count_elem_above(start, end, lst->value);
		below = count_elem_below(start, end, lst->value);
		if (stop_it(even, above, below))
			return (lst);
		lst = lst->next;
	}
	if (lst)
	{
		above = count_elem_above(start, end, lst->value);
		below = count_elem_below(start, end, lst->value);
		if (stop_it(even, above, below))
			return (lst);
	}
	return (0);
}
