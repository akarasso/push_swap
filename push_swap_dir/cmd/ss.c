/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:50:17 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/05 09:16:00 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	s(t_elem **lst)
{
	t_elem *first;
	t_elem *second;

	if (*lst && (*lst)->next)
	{
		first = *lst;
		second = (*lst)->next;
		first->next = second->next;
		second->next = first;
		*lst = second;
	}
}

void	sa(t_push *ps)
{
	if (ps->lst_a && ps->lst_a->next)
	{
		if (!(lst_push_instru(&ps->instru, SA)))
			ps_error(ps);
		s(&ps->lst_a);
	}
}

void	sb(t_push *ps)
{
	if (ps->lst_b && ps->lst_b->next)
	{
		if (!(lst_push_instru(&ps->instru, SB)))
			ps_error(ps);
		s(&ps->lst_b);
	}
}

void	ss(t_push *ps)
{
	if (ps->lst_a && ps->lst_a->next && ps->lst_b && ps->lst_b->next)
	{
		if (!(lst_push_instru(&ps->instru, SS)))
			ps_error(ps);
		s(&ps->lst_a);
		s(&ps->lst_b);
	}
}
