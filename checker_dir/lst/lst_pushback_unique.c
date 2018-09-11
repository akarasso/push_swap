/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pushback_unique.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoax <hoax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10:20:19 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/04 22:55:42 by hoax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_elem	*lst_new(int value)
{
	t_elem *new;

	if (!(new = (t_elem *)malloc(sizeof(t_elem))))
		return (0);
	new->value = value;
	new->lst = LST_A;
	new->partition = 0;
	new->futur_index = 0;
	new->path.nra = 0;
	new->path.nrb = 0;
	new->path.nrra = 0;
	new->path.nrrb = 0;
	new->next = 0;
	return (new);
}

t_elem	*lst_pushback_unique(t_elem **lst, int val)
{
	t_elem *elem;

	if (*lst)
	{
		elem = *lst;
		while (elem->next)
		{
			if (elem->value == val)
				return (0);
			elem = elem->next;
		}
		if (elem->value == val)
			return (0);
		elem->next = lst_new(val);
		return (elem->next);
	}
	else
	{
		*lst = lst_new(val);
		return (*lst);
	}
}
