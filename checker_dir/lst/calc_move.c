/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 15:15:26 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/04 15:15:35 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		is_min(t_elem *e1, t_elem *e2, t_elem *i)
{
	int d1;
	int d2;

	d1 = ABS(i->value - e1->value);
	d2 = ABS(i->value - e2->value);
	if (d1 < d2)
		return (1);
	return (0);
}

void	calc_insert_a(t_elem *lst, t_elem *elem, int size)
{
	t_elem	*place;
	int		i;

	place = 0;
	i = 0;
	while (lst)
	{
		if (!place && lst->value > elem->value)
		{
			place = lst;
			elem->path.nra = (i == 0) ? 0 : i - 1;
			elem->path.nrra = size - i;
		}
		else if (place && lst->value > elem->value && is_min(lst, place, elem))
		{
			place = lst;
			elem->path.nra = (i == 0) ? 0 : i - 1;
			elem->path.nrra = size - i;
		}
		i++;
		lst = lst->next;
	}
}

void	calc_move_a(t_elem *lst, int size)
{
	int i;

	i = 0;
	while (lst)
	{
		lst->path.nra = i;
		lst->path.nrra = size - i;
		lst = lst->next;
		i++;
	}
}

void	calc_move_b(t_push *ps, t_elem *lst, int size)
{
	int i;

	i = 0;
	while (lst)
	{
		lst->path.nrb = i;
		lst->path.nrrb = size - i;
		calc_insert_a(ps->lst_a, lst, ps->len_a);
		lst = lst->next;
		i++;
	}
}

void	calc_move(t_push *ps)
{
	calc_move_a(ps->lst_a, ps->len_a);
	calc_move_b(ps, ps->lst_b, ps->len_b);
}
