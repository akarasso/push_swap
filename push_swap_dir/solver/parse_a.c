/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 00:26:35 by hoax              #+#    #+#             */
/*   Updated: 2018/07/05 17:20:20 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	continue_parse(t_elem *lst)
{
	while (lst && lst->next)
	{
		if (lst->value > lst->next->value)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static void	push_to_b(t_push *ps, int median)
{
	t_elem *e;

	if ((e = pb(ps)))
	{
		if (ps->len_b > 1 && e->value > median)
		{
			e->partition += 2;
			rb(ps);
		}
		e->lst = LST_B;
		e->partition++;
	}
}

void		action_a(t_push *ps, int lvalue, int median)
{
	if ((lvalue < VALA && VALA < NVALA) || (NVALA < lvalue && lvalue < VALA)
		|| (ps->len_a == 2 && VALA > NVALA))
		ra(ps);
	else if ((lvalue < NVALA && NVALA < VALA)
		|| (ps->len_a == 3 && VALA > NVALA))
	{
		if (ps->lst_b && ps->lst_b->next && VALB > NVALB)
			ss(ps);
		else
			sa(ps);
		if (continue_parse(ps->lst_a))
			ra(ps);
	}
	else if (VALA != lvalue)
		push_to_b(ps, median);
}

void		parse_a(t_push *ps)
{
	t_elem	*last;
	t_elem	*median;

	last = lst_get_last(ps->lst_a);
	median = lst_median(ps->lst_a, last->value);
	while (continue_parse(ps->lst_a))
	{
		if (!(last = lst_get_last(ps->lst_a)))
			break ;
		action_a(ps, last->value, median->value);
	}
}
