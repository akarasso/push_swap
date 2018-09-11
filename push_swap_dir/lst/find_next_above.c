/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_above.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 09:30:35 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/04 09:30:52 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_elem	*find_next_above(t_elem *lst, int value)
{
	while (lst)
	{
		if (lst->value < value)
			return (lst);
		lst = lst->next;
	}
	return (0);
}
