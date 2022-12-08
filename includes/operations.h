/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:05:11 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/08 01:24:34 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"

void	swap(t_stack *stack, char *op);
void	ss(t_state *state);

void	push(t_stack *dest, t_stack *src, char *op);

void	rotate(t_stack *stack, char *op);
void	rr(t_state *state);

void 	reverse(t_stack *stack, char *op);
void	rrr(t_state *state);

#endif