/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:12:58 by ccolemon          #+#    #+#             */
/*   Updated: 2019/09/13 22:35:56 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define SUCCESS (1)
# define START (1)
# define END (0)
# define MALLOC_ERROR (6253861)

# define PS (1)
# define CH (0)

# define A (0)
# define B (1)
# define BOTH (2)

# define UP (1)
# define NEUTRAL (0)
# define DOWN (-1)

# define NO (0)
# define SA (1)
# define SB (2)
# define SS (3)
# define PA (4)
# define PB (5)
# define RA (6)
# define RB (7)
# define RR (8)
# define RRA (9)
# define RRB (10)
# define RRR (11)

# define S_NODE_RX ops[0]
# define S_NODE_RRX ops[1]
# define S_NEIB_RX ops[2]
# define S_NEIB_RRX ops[3]
# define S_SS ops[4]
# define S_RR ops[5]
# define S_RRR ops[6]

# define CHMT ✅
# define CHMF ❌
# define MAX 1024

# include "../libft/src/libft.h"

typedef struct		s_node
{
	int64_t			value;
	int				pos;
	int				pos_neib;
	int				pos_sort;

	int				up;
	int				sx;
	int				rx;
	int				rrx;
	int				neib_rx;
	int				neib_rrx;
	int				ss;
	int				rr;
	int				rrr;

	int				sum_op_up;
	int				min_with_ss;
	int				min_with_rr;
	int				min_with_rrr;
	int				sum_ops;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	t_node			*start;
	t_node			*end;
	int64_t			min;
	int64_t			mid;
	int64_t			max;
	int				size;
	int				full_size;
	int64_t			sort_num[1024];
	char			name;
	struct s_stack	*next;
}					t_stack;

/*
**	Libstack functions
*/

t_node				*create_node(int num, int pos_sort);
t_stack				*create_stack(char name);

int					pop(t_stack *stack, int code);

int					push(t_stack *stack, t_node *node);
int					pa(t_stack *a, t_stack *b, int ps_or_ch);
int					pb(t_stack *b, t_stack *a, int ps_or_ch);

int					swap(t_stack *stack);
int					sa(t_stack *a, t_stack *b, int ps_or_ch);
int					sb(t_stack *a, t_stack *b, int ps_or_ch);
int					ss(t_stack *a, t_stack *b, int ps_or_ch);

int					rotate(t_stack *stack);
int					ra(t_stack *a, t_stack *b, int ps_or_ch);
int					rb(t_stack *a, t_stack *b, int ps_or_ch);
int					rr(t_stack *a, t_stack *b, int ps_or_ch);

int					reverse_rotate(t_stack *stack);
int					rra(t_stack *a, t_stack *b, int ps_or_ch);
int					rrb(t_stack *a, t_stack *b, int ps_or_ch);
int					rrr(t_stack *a, t_stack *b, int ps_or_ch);

/*
**	Checker's functions
*/

void				print(t_stack *a, t_stack *b, int code);
int					print_stack(t_stack *stack, int size, char name);
void				print_sort_stack(int64_t *sort_num, int size);
void				end(int code, char *message);
void				end_free(int code, t_stack *a, t_stack *b, int ps_or_ch);
void				end_error_free(t_stack *a, t_stack *b, char *s, char *temp);
void				free_stack(t_stack *stack, int code);

void				get_num(int *j, int64_t *num, char *str);
void				get_mnum(int count, int *j, int64_t *num, char **split);
t_stack				*get_stack(int64_t *num, int size, int code);

void				valid_command(char *str, t_stack *a, t_stack *b);
int					valid_str(char *s);
void				check_dup(int64_t *num, int size);
t_stack				*valid_num(int lenght, char **av, int code);

int					check_sort(t_stack *a, t_stack *b);

/*
**	Algorithm's functions
*/

void				print_op_ps(int op, int ps_or_ch);

void				set_pos(t_stack *stack);
void				set_sort_pos(int64_t *num, t_stack *stack);

void				set_neib(t_stack *a, t_stack *b);
void				set_neib_one(t_stack *stack, t_node *node);
void				set_default_neib_one(t_stack *stack);
void				set_default_neib(t_stack *a, t_stack *b);

void				set_up(t_stack *stack, t_node *node);
void				set_ops(t_node *node, t_node *neib);
void				set_ops_one(t_node *node, t_node *neib);
void				set_ops_exc(t_node *node, t_node *neib);

void				swap_elems(int64_t *num, int i, int j);
void				ft_qsort(int64_t *num, int left, int right);

int					sort(t_stack *a, t_stack *b);
void				start_sort(t_stack *a, t_stack *b);
void				to_neib(t_stack *a, t_stack *b, t_node *node);
void				dop_sort(t_stack *a, t_stack *b, int first, int third);
void				mid_sort(t_stack *a, t_stack *b);
void				exc_sort(t_stack *a, t_stack *b, int first, int third);

#endif
