/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem_above.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 09:29:41 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/04 10:30:06 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_elem	*get_elem_above(t_elem *lst, int last, int n)
{
	t_elem *start;

	start = lst;
	while (lst)
	{
		if (count_elem_below(start, last, lst->value) == n)
			return (lst);
		lst = lst->next;
	}
	return (0);
}
