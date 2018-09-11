/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 01:05:52 by hoax              #+#    #+#             */
/*   Updated: 2018/07/05 17:52:19 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	get_action(int nr, int nrr)
{
	if (nr < 1 || nrr < 1)
		return (NONE);
	if (nrr < nr)
		return (RRR);
	return (RR);
}

static int	doit(t_push *ps, int acta, int actb)
{
	if (!acta && !actb)
		return (0);
	if (actb == acta && actb == RR)
		rr(ps);
	else if (actb == acta && actb == RRR)
		rrr(ps);
	else if (actb)
		(actb == RR) ? rb(ps) : rrb(ps);
	else if (acta)
		(acta == RR) ? ra(ps) : rra(ps);
	calc_move(ps);
	return (1);
}

static void	insert(t_push *ps)
{
	t_elem	*sel;
	int		acta;
	int		acta2;
	int		actb;

	sel = get_better_push(ps->lst_b);
	acta = get_action(sel->path.nra, sel->path.nrra);
	acta2 = get_action(sel->path.nra, sel->path.nrra);
	actb = get_action(sel->path.nrb, sel->path.nrrb);
	while (1)
	{
		acta = get_action(sel->path.nra, sel->path.nrra);
		actb = get_action(sel->path.nrb, sel->path.nrrb);
		if (!doit(ps, acta, actb))
			break ;
	}
	if (VALB == sel->value)
		pa(ps);
	if (acta2 == NONE && ps->lst_a && ps->lst_a->next && ps->lst_a->next->next
		&& VALA < NVALA && NVALA > ps->lst_a->next->next->value
		&& VALA < ps->lst_a->next->next->value)
		(ps->lst_b && ps->lst_b->next && VALB < NVALB) ? ss(ps) : sa(ps);
	else if (VALA > NVALA || acta2 == RR)
		(ps->lst_b && ps->lst_b->next && VALB < NVALB) ? ss(ps) : sa(ps);
}

void		resolve_b(t_push *ps)
{
	while (ps->lst_b)
	{
		calc_move(ps);
		insert(ps);
	}
}
