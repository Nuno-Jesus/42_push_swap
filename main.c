/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:55:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/18 15:23:26 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_state	state;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (!valid_args(argc - 1, argv + 1))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	state.a = new_stack(argc - 1);
	state.b = new_stack(argc - 1);
	if (!state.a || !state.b)
		destroy_state(&state);
	stack_fill(state.a, argv + 1, argc - 1);
	apply_rankings(state.a);
	if (state.a->size <= MEDIUM_SORT_THRESHOLD)
		medium_sort_algorithm(&state);
	else
		big_sort_algorithm(&state);
	destroy_state(&state);
	return (EXIT_SUCCESS);
}
