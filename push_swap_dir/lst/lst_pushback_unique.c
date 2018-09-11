/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pushback_unique.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10:20:19 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/05 17:50:18 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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
