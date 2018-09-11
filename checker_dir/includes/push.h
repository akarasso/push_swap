/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:22:22 by akarasso          #+#    #+#             */
/*   Updated: 2018/07/14 14:37:03 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# define LST_A 1
# define LST_B 2
# define NONE 0
# define SA 2
# define SB 3
# define SS 4
# define PA 5
# define PB 6
# define RA 7
# define RB 8
# define RR 9
# define RRA 10
# define RRB 11
# define RRR 12
# define VALA ps->lst_a->value
# define NVALA ps->lst_a->next->value
# define VALB ps->lst_b->value
# define NVALB ps->lst_b->next->value
# define ABS(x) (x < 0) ? -(x) : x

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"

typedef struct	s_path
{
	int				nra;
	int				nrb;
	int				nrra;
	int				nrrb;
}				t_path;

typedef struct	s_intru
{
	char			instru;
	struct s_intru	*next;
}				t_instru;

typedef struct	s_elem
{
	int				value;
	int				lst;
	int				partition;
	int				futur_index;
	struct s_path	path;
	struct s_path	opti_path;
	struct s_elem	*next;
}				t_elem;

typedef struct	s_partition
{
	t_elem			*begin;
	t_elem			*med;
	t_elem			*last;
	int				index;
	int				futur_index;
}				t_partition;

typedef struct	s_push
{
	t_elem			*origin;
	t_elem			*lst_a;
	t_elem			*lst_b;
	t_instru		*instru;
	t_instru		*instru_save;
	t_partition		*part;
	int				len_a;
	int				len_b;
	long long		flag;
}				t_push;

/*
** Parser
*/

t_instru		*lst_push_instru(t_instru **lst, int value);
t_elem			*lst_pushback_unique(t_elem **lst, int val);
t_elem			*lst_new(int value);
t_elem			*get_better_push(t_elem *lst);
t_elem			*get_last(t_elem *lst, int end);
int				lst_dup(t_elem *src, t_elem **dest);
int				len_instru(t_instru *lst);
int				lst_len(t_elem *lst);
int				parser(t_push *ps, int argc, char **argv);
int				lst_size_at(t_elem *lst, int end);
int				lst_size(t_elem *lst);
void			lst_del(t_elem **lst);
void			lst_del_instru(t_instru **lst);
void			show_instru(t_instru *lst);
void			parse_a(t_push *ps);
void			parse_b(t_push *ps, int ipart);
void			apply_index(t_push *ps);
int				lst_isorder(t_elem *start);
void			lst_show(t_push *ps);
int				lst_isorder_place(t_elem *start);
void			clear_struct(t_push *ps);
void			ps_error(t_push *ps);
void			parser_opt(t_push *ps, char *str);
void			clear(t_push *ps, int ret);

/*
** Split
*/

t_elem			*lst_get_last_partition(t_elem *lst, int partition);
t_elem			*lst_get_last(t_elem *lst);
t_elem			*find_next_above(t_elem *lst, int value);
t_elem			*find_next_max_above(t_elem *lst, int max, int value);
t_elem			*lst_median(t_elem *lst, int end);
t_elem			*get_elem_above(t_elem *lst, int n, int last);
int				get_next_partition(t_elem *lst, int *current);
int				count_elem_below(t_elem *lst, int end, int value);
int				count_elem_above(t_elem *lst, int end, int value);
void			split(t_push *ps, int rec);
void			resolve_b(t_push *ps);
void			calc_move(t_push *ps);
void			lst_reorder(t_push *ps);
void			split_rec_b(t_push *ps, int rec);

/*
** Solver
*/

void			solver(t_push *ps);

/*
** CMD
*/

int				pa(t_push *ps);
int				pb(t_push *ps);
int				rr(t_push *ps);
int				ra(t_push *ps);
int				rb(t_push *ps);
int				rra(t_push *ps);
int				rrb(t_push *ps);
int				rrr(t_push *ps);
int				sa(t_push *ps);
int				sb(t_push *ps);
int				ss(t_push *ps);

#endif
