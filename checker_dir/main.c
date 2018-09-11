/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 15:07:54 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/14 14:57:48 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include "libft.h"
#include "flag.h"

void		init(t_push *ps)
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

void		lst_show(t_push *ps)
{
	t_elem	*lst;

	lst = ps->lst_a;
	write(1, "Stack A:", 8);
	while (lst)
	{
		ft_putnbr(lst->value);
		write(1, " ", 1);
		lst = lst->next;
	}
	write(1, "\n", 1);
	lst = ps->lst_b;
	write(1, "Stack B:", 8);
	while (lst)
	{
		ft_putnbr(lst->value);
		lst = lst->next;
	}
	write(1, "\n", 1);
}

int			parse_cmd(t_push *ps, char *str)
{
	if ((!ft_strcmp(str, "rr") && rr(ps))
		|| (!ft_strcmp(str, "rrr") && rrr(ps))
		|| (!ft_strcmp(str, "ra") && ra(ps))
		|| (!ft_strcmp(str, "rb") && rb(ps))
		|| (!ft_strcmp(str, "rra") && rra(ps))
		|| (!ft_strcmp(str, "rrb") && rrb(ps))
		|| (!ft_strcmp(str, "sb") && sb(ps))
		|| (!ft_strcmp(str, "sa") && sa(ps))
		|| (!ft_strcmp(str, "ss") && ss(ps))
		|| (!ft_strcmp(str, "pa") && pa(ps))
		|| (!ft_strcmp(str, "pb") && pb(ps)))
		return (1);
	ps_error(ps);
	return (0);
}

void		listen(t_push *ps)
{
	char	*instru;
	int		ret;

	instru = 0;
	while ((ret = get_next_line(0, &instru)) > 0)
	{
		if (instru)
		{
			parse_cmd(ps, instru);
			if (ps->flag & SS_FLAG)
				lst_show(ps);
			ft_strdel(&instru);
		}
	}
	ft_strdel(&instru);
	clear(ps, ret);
}

int			main(int argc, char **argv)
{
	t_push	ps;

	init(&ps);
	if (argc < 2)
		return (0);
	if (!parser(&ps, argc, argv))
		ps_error(&ps);
	if (ps.lst_a)
		listen(&ps);
	return (0);
}
