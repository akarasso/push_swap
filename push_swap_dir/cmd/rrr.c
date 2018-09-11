/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:31:06 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/05 09:16:08 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_elem	*lst_get_elem_before(t_elem **lst, t_elem *m)
{
	t_elem *elem;

	elem = *lst;
	if (!elem)
		return (0);
	while (elem->next && elem->next != m)
		elem = elem->next;
	return (elem);
}

void	rrotate(t_elem **lst)
{
	t_elem *blast;
	t_elem *last;

	last = lst_get_elem_before(lst, 0);
	if (last)
	{
		blast = lst_get_elem_before(lst, last);
		if (blast && last->value != blast->value)
		{
			blast->next = 0;
			last->next = (*lst);
			(*lst) = last;
		}
	}
}

void	rra(t_push *ps)
{
	if (ps->lst_a)
	{
		if (!(lst_push_instru(&ps->instru, RRA)))
			ps_error(ps);
		rrotate(&ps->lst_a);
	}
}

void	rrb(t_push *ps)
{
	if (ps->lst_b)
	{
		if (!(lst_push_instru(&ps->instru, RRB)))
			ps_error(ps);
		rrotate(&ps->lst_b);
	}
}

void	rrr(t_push *ps)
{
	if (ps->lst_a && ps->lst_b)
	{
		if (!(lst_push_instru(&ps->instru, RRR)))
			ps_error(ps);
		rrotate(&ps->lst_a);
		rrotate(&ps->lst_b);
	}
}
