/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:50:17 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/04 23:24:42 by hoax             ###   ########.fr       */
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

int		sa(t_push *ps)
{
	if (ps->lst_a && ps->lst_a->next)
	{
		s(&ps->lst_a);
		return (1);
	}
	return (0);
}

int		sb(t_push *ps)
{
	if (ps->lst_b && ps->lst_b->next)
	{
		s(&ps->lst_b);
		return (1);
	}
	return (1);
}

int		ss(t_push *ps)
{
	sa(ps);
	sb(ps);
	return (1);
}
