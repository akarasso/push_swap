/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:47:25 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/05 09:17:27 by akarasso         ###   ########.fr       */
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

int		pa(t_push *ps)
{
	t_elem *e;

	if ((e = p(&ps->lst_b, &ps->lst_a)))
	{
		ps->len_a++;
		ps->len_b--;
	}
	return (1);
}

int		pb(t_push *ps)
{
	t_elem *e;

	if ((e = p(&ps->lst_a, &ps->lst_b)))
	{
		ps->len_a--;
		ps->len_b++;
	}
	return (1);
}
