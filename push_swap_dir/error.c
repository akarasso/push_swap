/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 21:47:58 by hoax              #+#    #+#             */
/*   Updated: 2018/07/05 17:57:34 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	clear_struct(t_push *ps)
{
	lst_del(&ps->lst_b);
	lst_del(&ps->lst_a);
	lst_del(&ps->origin);
	lst_del_instru(&ps->instru);
	lst_del_instru(&ps->instru_save);
}

void	ps_error(t_push *ps)
{
	clear_struct(ps);
	write(1, "Error\n", 6);
	exit(1);
}
