/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_reorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 09:30:18 by hoax              #+#    #+#             */
/*   Updated: 2018/07/14 14:55:40 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_elem	*get_min(t_elem *lst)
{
	t_elem *elem;

	elem = 0;
	while (lst)
	{
		if (!elem)
			elem = lst;
		else if (elem && lst->value < elem->value)
			elem = lst;
		lst = lst->next;
	}
	return (elem);
}

int		lst_isorder(t_elem *start)
{
	t_elem *lst;
	t_elem *min;

	min = get_min(start);
	lst = start;
	while (lst && lst->next && lst->next->value != min->value)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	while (min && min->next)
	{
		if (min->value > min->next->value)
			return (0);
		min = min->next;
	}
	return (1);
}

int		lst_isorder_place(t_elem *start)
{
	t_elem *min;

	min = get_min(start);
	if (start->value == min->value && lst_isorder(start))
		return (1);
	return (0);
}

void	lst_reorder(t_push *ps)
{
	t_elem *min;

	calc_move(ps);
	min = get_min(ps->lst_a);
	while (ps->lst_a->value != min->value)
		(min->path.nrra < min->path.nra) ? rra(ps) : ra(ps);
}
