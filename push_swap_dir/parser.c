/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10:14:48 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/05 17:54:12 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <fcntl.h>

long long	ft_atoi(char *s)
{
	long long	ret;
	int			neg;

	ret = 0;
	while ((*s >= 8 && *s <= 13) || *s == 32)
		s++;
	neg = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		ret = ret * 10 + ((long long)*s - 48);
		s++;
	}
	return (ret * neg);
}

int			check_var(char *s)
{
	long long	res;

	if ((res = ft_atoi(s)) > 2147483647 || res < -2147483648)
	{
		return (0);
	}
	while ((*s >= 8 && *s <= 13) || *s == 32)
		s++;
	if (*s && (*s == '-' || *s == '+'))
		s++;
	while (*s && ((*s >= '0' && *s <= '9')))
		s++;
	if (*s)
		return (0);
	return (1);
}

int			ft_stralpha(char *s)
{
	while (*s)
	{
		if (!((*s > 64 && *s < 91) || (*s > 96 && *s < 123)))
		{
			return (0);
		}
		s++;
	}
	return (1);
}

int			parser(t_push *ps, int argc, char **argv)
{
	int		i;
	t_elem	*last;

	i = 1;
	if (i > 0 && argv[1][0] == '-' && ft_stralpha(&argv[1][1]))
	{
		parser_opt(ps, &argv[1][1]);
		i++;
	}
	while (i < argc)
	{
		if (!check_var(argv[i])
			|| !(last = lst_pushback_unique(&ps->origin, ft_atoi(argv[i++]))))
			ps_error(ps);
		ps->len_a++;
	}
	if (last)
		return (1);
	return (0);
}
