/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 23:25:38 by hoax              #+#    #+#             */
/*   Updated: 2018/07/04 10:30:12 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		lst_dup(t_elem *src, t_elem **dest)
{
	while (src && lst_pushback_unique(dest, src->value))
	{
		src = src->next;
	}
	if (!src)
		return (1);
	return (0);
}
