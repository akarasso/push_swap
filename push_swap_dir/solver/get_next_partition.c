/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_partition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:07:15 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/04 10:04:24 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		get_next_partition(t_elem *lst, int *current)
{
	while (lst)
	{
		if (*current == -1)
		{
			*current = lst->partition;
			return (1);
		}
		else if (*current == lst->partition)
		{
			while (lst && lst->partition == *current)
				lst = lst->next;
			if (lst)
			{
				*current = lst->partition;
				return (1);
			}
			else
				return (-2);
		}
		lst = lst->next;
	}
	return (-2);
}
