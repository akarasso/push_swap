/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:21:39 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/05 17:45:30 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include "flag.h"

void	init(t_push *ps)
{
	ps->instru = 0;
	ps->instru_save = 0;
	ps->origin = 0;
	ps->lst_a = 0;
	ps->lst_b = 0;
	ps->part = 0;
	ps->len_a = 0;
	ps->len_b = 0;
	ps->flag = 0;
}

int		solve_continue(t_push *ps)
{
	if (ps->instru_save && len_instru(ps->instru) < len_instru(ps->instru_save))
	{
		lst_del_instru(&ps->instru_save);
		ps->instru_save = ps->instru;
		ps->instru = 0;
	}
	else if (ps->instru_save
		&& len_instru(ps->instru) >= len_instru(ps->instru_save))
		return (0);
	else
	{
		ps->instru_save = ps->instru;
		ps->instru = 0;
	}
	return (1);
}

void	ft_putnbr(int n)
{
	int x;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= (-1);
		write(1, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		x = n + 48;
		write(1, (char *)&x, 1);
	}
}

void	solve(t_push *ps)
{
	int i;

	i = 0;
	while (1)
	{
		if (!lst_dup(ps->origin, &ps->lst_a))
			ps_error(ps);
		ps->len_a = lst_len(ps->lst_a);
		ps->len_b = 0;
		parse_a(ps);
		split_rec_b(ps, i++);
		resolve_b(ps);
		lst_reorder(ps);
		if (!solve_continue(ps))
			break ;
		lst_del(&ps->lst_a);
	}
}

int		main(int argc, char **argv)
{
	t_push	ps;

	if (argc < 2)
		return (0);
	init(&ps);
	if (!parser(&ps, argc, argv) || !ps.origin)
		return (1);
	if (!lst_isorder_place(&ps, ps.origin))
		solve(&ps);
	if (ps.flag & NN_FLAG)
	{
		ft_putnbr(len_instru(ps.instru_save));
		write(1, "\n", 1);
	}
	else
		show_instru(&ps, ps.instru_save);
	clear_struct(&ps);
	return (0);
}
