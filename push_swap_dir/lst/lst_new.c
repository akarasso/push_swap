/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10:18:01 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/05 17:51:02 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_elem	*lst_new(int value)
{
	t_elem *new;

	if (!(new = (t_elem *)malloc(sizeof(t_elem))))
		return (0);
	new->value = value;
	new->lst = LST_A;
	new->partition = 0;
	new->futur_index = 0;
	new->path.nra = 0;
	new->path.nrb = 0;
	new->path.nrra = 0;
	new->path.nrrb = 0;
	new->next = 0;
	return (new);
}
