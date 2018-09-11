/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 00:02:43 by hoax              #+#    #+#             */
/*   Updated: 2018/07/05 17:56:43 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include "flag.h"

void	show_rotate(t_push *ps, int act)
{
	if (act == RR)
		(ps->flag & CC_FLAG) ? write(1, "\e[31mrr\n", 9) \
			: write(1, "rr\n", 3);
	else if (act == RRR)
		(ps->flag & CC_FLAG) ? write(1, "\e[32mrrr\n", 10) \
			: write(1, "rrr\n", 4);
	else if (act == RA)
		(ps->flag & CC_FLAG) ? write(1, "\e[33mra\n", 9) \
			: write(1, "ra\n", 3);
	else if (act == RB)
		(ps->flag & CC_FLAG) ? write(1, "\e[34mrb\n", 9) \
			: write(1, "rb\n", 3);
	else if (act == RRB)
		(ps->flag & CC_FLAG) ? write(1, "\e[35mrrb\n", 10) \
			: write(1, "rrb\n", 4);
	else if (act == RRA)
		(ps->flag & CC_FLAG) ? write(1, "\e[36mrra\n", 10) \
			: write(1, "rra\n", 4);
}

void	show_swap(t_push *ps, int act)
{
	if (act == SA)
		(ps->flag & CC_FLAG) ? write(1, "\e[91msa\n", 9) \
			: write(1, "sa\n", 3);
	else if (act == SS)
		(ps->flag & CC_FLAG) ? write(1, "\e[92mss\n", 9) \
			: write(1, "ss\n", 3);
	else if (act == SB)
		(ps->flag & CC_FLAG) ? write(1, "\e[94msb\n", 9) \
			: write(1, "sb\n", 3);
}

void	show_instru(t_push *ps, t_instru *lst)
{
	if (!ps)
		return ;
	while (lst)
	{
		if (lst->instru == RR || lst->instru == RRR || lst->instru == RA
		|| lst->instru == RB || lst->instru == RRA || lst->instru == RRB)
			show_rotate(ps, lst->instru);
		else if (lst->instru == SA
			|| lst->instru == SB || lst->instru == SS)
			show_swap(ps, lst->instru);
		else if (lst->instru == PB)
			(ps->flag & CC_FLAG) ? write(1, "\e[95mpb\n", 9) \
				: write(1, "pb\n", 3);
		else if (lst->instru == PA)
			(ps->flag & CC_FLAG) ? write(1, "\e[96mpa\n", 9) \
				: write(1, "pa\n", 3);
		lst = lst->next;
	}
}
