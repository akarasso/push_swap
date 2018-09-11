/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_rec_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 00:47:54 by hoax              #+#    #+#             */
/*   Updated: 2018/07/05 17:58:37 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void		reinsert_b(t_push *ps)
{
	while (ps->lst_a && ps->lst_a->lst == LST_B)
		pb(ps);
}

void		split_b(t_push *ps, t_partition part)
{
	while (ps->lst_b && VALB != part.last->value)
	{
		if (VALB > part.med->value)
		{
			ps->lst_b->futur_index = part.futur_index + 2;
			pa(ps);
		}
		else
		{
			ps->lst_b->futur_index = part.futur_index;
			rb(ps);
		}
	}
	if (VALB == part.last->value && VALB > part.med->value)
	{
		ps->lst_b->futur_index = part.futur_index + 2;
		pa(ps);
	}
	else
	{
		ps->lst_b->futur_index = part.futur_index;
		rb(ps);
	}
	reinsert_b(ps);
}

void		inc_index_part(t_push *ps, t_partition part)
{
	while (ps->lst_b && ps->lst_b->value != part.last->value)
	{
		ps->lst_b->futur_index = part.futur_index;
		rb(ps);
	}
	if (ps->lst_b->value == part.last->value)
	{
		ps->lst_b->futur_index = part.futur_index;
		rb(ps);
	}
}

int			init_part(t_elem *lst, t_partition *part, int futur_index)
{
	part->futur_index = futur_index;
	part->begin = lst;
	if (!(part->last = lst_get_last_partition(lst, part->index)))
		return (0);
	part->med = lst_median(lst, part->last->value);
	if (part->med)
		return (1);
	return (0);
}

void		split_rec_b(t_push *ps, int rec)
{
	t_partition part;
	int			futur_index;

	if (rec <= 0)
		return ;
	futur_index = 0;
	part.index = -1;
	if (get_next_partition(ps->lst_b, &part.index) != -2)
	{
		if (init_part(ps->lst_b, &part, futur_index))
			split_b(ps, part);
		else
			inc_index_part(ps, part);
		futur_index += 4;
	}
	apply_index(ps);
	split_rec_b(ps, --rec);
}
