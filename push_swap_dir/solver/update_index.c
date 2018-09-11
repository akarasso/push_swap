/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 10:15:21 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/04 10:15:30 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	apply_index(t_push *ps)
{
	t_elem *lst;

	lst = ps->lst_b;
	while (lst)
	{
		lst->partition = lst->futur_index;
		lst = lst->next;
	}
}
