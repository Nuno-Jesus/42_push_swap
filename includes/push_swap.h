/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:40:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/15 16:30:08 by ncarvalh         ###   ########.fr       */
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

# define SMALL_SORT_THRESHOLD 3
# define MEDIUM_SORT_THRESHOLD 5

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

typedef struct s_node
{
	int				val;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;	
}t_node;

typedef struct s_stack
{
	int		size;
	int		capacity;
	t_node	*head;
}t_stack;

typedef struct s_state
{
	t_stack	*a;
	t_stack	*b;
}t_state;

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ STACK _/=\_/=\_/=\_/=\_/=\_/=\_/=\_

t_stack	*new_stack(int capacity);

t_node	*new_node(int val);

void	stack_push(t_stack *stack, t_node *val);

t_node	*stack_pop(t_stack *stack);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ DEBUG _/=\_/=\_/=\_/=\_/=\_/=\_/=\_

void	print_bits(unsigned char n);

void	print_stack(t_stack *stack, char *name);

void	print_state(t_state *state);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ DESTROY _/=\_/=\_/=\_/=\_/=\_/=\_/=\_
void	destroy_node(t_node **node);

void	destroy_stack(t_stack **stack);

void	destroy_state(t_state *state);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ PS_OPS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_

void	do_op(t_state *state, t_operation op);

void	sx(t_stack *stack, char *op);

void	ss(t_state *state);

void	px(t_stack *src, t_stack *dest, char *op);

void	rx(t_stack *stack, char *op);

void	rr(t_state *state);

void	rrx(t_stack *stack, char *op);

void	rrr(t_state *state);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ VALIDATOR _/=\_/=\_/=\_/=\_/=\_/=\_/=\_

bool	valid_args(int argc, char **argv);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ ALGORITHMS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_

bool	is_sorted(t_stack *stack);

void	apply_rankings(t_stack *a);

void	small_sort_algorithm(t_state *state);

void	medium_sort_algorithm(t_state *state);

void	big_sort_algorithm(t_state *state);

//!_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ PS_UTILS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_

int		count_bits(int n);

void	stack_fill(t_stack *stack, char **argv, int argc);

t_node	*find_next_unranked_min(t_stack *a);

int		find_stack_min(t_stack *stack);

void	extract_min_to_b(t_state *state);

#endif