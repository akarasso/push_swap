/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_better_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 10:08:34 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/04 10:09:00 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		opti_path(t_elem *e)
{
	int len;

	len = 0;
	len += (e->path.nrrb < e->path.nrb) ? e->path.nrrb : e->path.nrb;
	len += (e->path.nrra < e->path.nra) ? e->path.nrra : e->path.nra;
	return (len);
}

t_elem	*get_better_push(t_elem *lst)
{
	t_elem *sel;

	sel = 0;
	while (lst)
	{
		if (!sel)
			sel = lst;
		else if (sel && opti_path(lst) < opti_path(sel))
			sel = lst;
		lst = lst->next;
	}
	return (sel);
}
