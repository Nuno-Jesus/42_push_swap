/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:40:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/11 22:23:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdbool.h>

# include "libft.h"

# define MAX(a, b) ((a > b) ? (a) : (b))
# define MIN(a, b) ((a < b) ? (a) : (b))
# define ABS(x) ((x < 0) ? (-x) : (x))
# define BIT(i) (1 << i)
// # define DEBUG

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}			t_operation;

typedef struct	s_node
{
	int				val;
	int 			rank;
	bool			has_negative_rank;
	bool			was_first;
	struct s_node	*next;
	struct s_node	*prev;	
}				t_node;

typedef struct	s_stack
{
	int	size;
	int	capacity;
	t_node 	*head;
}				t_stack;

typedef struct	s_state
{
	t_stack	*a;
	t_stack	*b;
}				t_state;

//!-------------------------------------------------

t_stack	*new_stack(int capacity);

void	stack_push(t_stack *stack, t_node *val);

t_node*	stack_pop(t_stack *stack);

void	destroy_stack(t_stack **stack);

void	print_stack(t_stack *stack, char *name);

//!-------------------------------------------------

void	do_op(t_state *state, t_operation op);

void	sx(t_stack *stack, char *op);

void	ss(t_state *state);

void	px(t_stack *src, t_stack *dest, char *op);

void	rx(t_stack *stack, char *op);

void	rr(t_state *state);

void 	rrx(t_stack *stack, char *op);

void	rrr(t_state *state);

//!-------------------------------------------------

t_node	*new_node(int val);

void	destroy_node(t_node **node);

//!-------------------------------------------------

void	sort(t_state *state);

//!-------------------------------------------------
bool	is_sorted(t_stack *stack);

#endif