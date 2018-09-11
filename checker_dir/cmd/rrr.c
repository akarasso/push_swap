/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:31:06 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/04 23:35:56 by hoax             ###   ########.fr       */
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

int		rra(t_push *ps)
{
	if (ps->lst_a)
	{
		rrotate(&ps->lst_a);
	}
	return (1);
}

int		rrb(t_push *ps)
{
	if (ps->lst_b)
	{
		rrotate(&ps->lst_b);
	}
	return (1);
}

int		rrr(t_push *ps)
{
	rra(ps);
	rrb(ps);
	return (1);
}
