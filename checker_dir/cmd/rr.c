/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:26:26 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/05 18:02:46 by akarasso         ###   ########.fr       */
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

int		ra(t_push *ps)
{
	if (ps->lst_a)
	{
		rotate(&ps->lst_a);
	}
	return (1);
}

int		rb(t_push *ps)
{
	if (ps->lst_b)
	{
		rotate(&ps->lst_b);
	}
	return (1);
}

int		rr(t_push *ps)
{
	if (ps->lst_a && ps->lst_b)
	{
		ra(ps);
		rb(ps);
	}
	return (1);
}
