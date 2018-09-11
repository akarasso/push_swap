/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:26:26 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/05 09:34:09 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rotate(t_elem **lst)
{
	t_elem *elem;
	t_elem *start;

	if (!(*lst)->next)
		return ;
	elem = *lst;
	start = *lst;
	*lst = elem->next;
	while (elem->next)
		elem = elem->next;
	elem->next = start;
	start->next = 0;
}

void	rr(t_push *ps)
{
	if (ps->lst_a && ps->lst_b)
	{
		if (!(lst_push_instru(&ps->instru, RR)))
			ps_error(ps);
		rotate(&ps->lst_a);
		rotate(&ps->lst_b);
	}
}

void	ra(t_push *ps)
{
	if (ps->lst_a)
	{
		if (!(lst_push_instru(&ps->instru, RA)))
			ps_error(ps);
		rotate(&ps->lst_a);
	}
}

void	rb(t_push *ps)
{
	if (ps->lst_b)
	{
		if (!(lst_push_instru(&ps->instru, RB)))
			ps_error(ps);
		rotate(&ps->lst_b);
	}
}
