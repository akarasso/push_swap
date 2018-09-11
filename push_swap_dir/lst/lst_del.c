/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 23:44:05 by hoax              #+#    #+#             */
/*   Updated: 2018/07/04 10:30:40 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	lst_del(t_elem **origin)
{
	t_elem *lst;
	t_elem *tmp;

	lst = *origin;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	*origin = 0;
}

void	lst_del_instru(t_instru **origin)
{
	t_instru *tmp;
	t_instru *lst;

	lst = *origin;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	*origin = 0;
}
