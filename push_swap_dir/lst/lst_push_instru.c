/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_instru.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 23:35:32 by hoax              #+#    #+#             */
/*   Updated: 2018/07/14 14:57:57 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_instru	*new_instru(int value)
{
	t_instru *instru;

	if (!(instru = (t_instru *)malloc(sizeof(*instru))))
		return (0);
	instru->instru = value;
	instru->next = 0;
	return (instru);
}

t_instru	*lst_push_instru(t_instru **lst, int value)
{
	t_instru *l;

	l = *lst;
	if (*lst)
	{
		while (l->next)
			l = l->next;
		if ((l->next = new_instru(value)))
			return (l->next);
		return (0);
	}
	else
	{
		if ((*lst = new_instru(value)))
			return (*lst);
		return (0);
	}
}
