/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 10:26:21 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/05 18:01:47 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include "flag.h"
#include "libft.h"

long long	ls_pow(unsigned int pow)
{
	long long ret;

	ret = 2;
	if (pow == 0)
		return (1);
	while (--pow)
		ret *= 2;
	return (ret);
}

int			is_valid(char c)
{
	char *valid;

	valid = "s";
	while (*valid)
	{
		if (c == *valid)
			return (1);
		valid++;
	}
	return (0);
}

void		usage(void)
{
	write(1, "usage: checker -cv [args...]\n", 29);
	exit(1);
}

void		parser_opt(t_push *ps, char *str)
{
	while (*str)
	{
		if (!is_valid(*str))
			usage();
		else
		{
			ps->flag |= ls_pow(*str - 'A');
		}
		str++;
	}
}
