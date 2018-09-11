/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:15:38 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/04 10:30:30 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_elem	*lst_get_last(t_elem *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

t_elem	*lst_get_last_partition(t_elem *lst, int partition)
{
	t_elem *ret;

	ret = 0;
	while (lst)
	{
		if (lst->partition == partition)
			ret = lst;
		lst = lst->next;
	}
	return (ret);
}
