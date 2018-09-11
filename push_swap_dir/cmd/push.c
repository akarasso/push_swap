/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:47:25 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/04 22:12:40 by hoax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_elem	*p(t_elem **origin, t_elem **dest)
{
	t_elem *elem;

	if (*origin)
	{
		elem = *origin;
		*origin = (*origin)->next;
		elem->next = *dest;
		*dest = elem;
		return (*dest);
	}
	return (0);
}

t_elem	*pa(t_push *ps)
{
	t_elem *e;

	if (!(lst_push_instru(&ps->instru, PA)))
		ps_error(ps);
	if ((e = p(&ps->lst_b, &ps->lst_a)))
	{
		ps->len_a++;
		ps->len_b--;
	}
	return (e);
}

t_elem	*pb(t_push *ps)
{
	t_elem *e;

	if (!(lst_push_instru(&ps->instru, PB)))
		ps_error(ps);
	if ((e = p(&ps->lst_a, &ps->lst_b)))
	{
		ps->len_a--;
		ps->len_b++;
	}
	return (e);
}
