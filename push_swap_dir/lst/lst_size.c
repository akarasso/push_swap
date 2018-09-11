/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10:58:10 by akarasso          #+#    #+#             */
/*   Updated: 2018/06/25 12:28:52 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		lst_size(t_elem *lst)
{
	int len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

int		lst_size_at(t_elem *lst, int end)
{
	int len;

	len = 0;
	while (lst && lst->value != end)
	{
		len++;
		lst = lst->next;
	}
	if (lst->value == end)
		len++;
	return (len);
}
