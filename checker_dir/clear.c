/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:33:50 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/14 14:47:36 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void		clear(t_push *ps, int ret)
{
	if (ret < 0)
		write(1, "Error\n", 6);
	else
	{
		if (ps->lst_b || !lst_isorder_place(ps->lst_a))
		{
			if (!lst_isorder_place(ps->lst_a))
			{
				write(1, "batard\n", 7);
			}
			write(1, "KO\n", 3);
		}
		else
			write(1, "OK\n", 3);
	}
	lst_del(&ps->lst_a);
	lst_del(&ps->lst_b);
}
