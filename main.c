/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:55:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/06 17:35:35 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_number(char *arg)
{
	if (*arg == '\0')
		return (false);
	// If the argument is negative, but not only a minus
	if (*arg == '-' && ft_strlen(arg) > 1)
		arg++;
	//Check if the rest of the characters are only numeric
	while (*arg)
		if (!ft_isdigit(*(arg++)))
			return (false);
	return (true);
}

bool	is_int(char *arg)
{
	int		signal;
	long	res;

	res = 0;
	signal = 1;
	if (*arg == '-')
	{
		signal = -1;
		arg++;
	}
	while (ft_isdigit(*arg))
		res = res * 10 + *(arg++) - '0';
	res *= signal;		
	return (res >= INT_MIN && res <= INT_MAX);
}

bool	is_duplicated(char **argv, int pos)
{
	int	i;
	int	current;

	i = 0;
	current = ft_atoi(argv[pos]);
	while (i < pos)
	{
		if (ft_atoi(argv[i++]) == current)
			return (true);
	}
	return (false);
}

bool	valid_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]) || !is_int(argv[i]) || is_duplicated(argv, i))
			return (false);		
		i++;
	}
	return (true);
}

bool	is_sorted(t_stack *stack)
{
	size_t	i;
	t_node	*aux;

	i = -1;
	aux = stack->head;
	while (++i < stack->size - 1)
	{
		if (aux->val > aux->next->val)
			return (false);
		aux = aux->next;
	}
	return (true);
}

void	stack_fill(t_stack *stack, char **argv, int argc)
{
	int	i;

	i = argc - 1;
	while (i >= 0)
		stack_push(stack, new_node(ft_atoi(argv[i--])));
}

//2147483647 -2147483648

void	destroy_state(t_state *state)
{
	if (state->a)
		destroy_stack(&state->a);
	if (state->b)
		destroy_stack(&state->b);
	return ;
}

int	main(int argc, char **argv)
{
	t_state	state;
	
	printf("Number of args: %d\n", argc);
	if (argc < 2)
		return (EXIT_FAILURE);
	if (!valid_args(argc - 1, argv + 1))
	{
		ft_putendl_fd("Error", STDOUT_FILENO);
		return (EXIT_FAILURE);	
	}
	state.a = new_stack(argc - 1);
	state.b = new_stack(argc - 1);
	if (!state.a || !state.b)
		destroy_state(&state);

	stack_fill(state.a, argv + 1, argc - 1);
	if (is_sorted(state.a))
		printf("Stack is sorted\n");
	sort(&state);
	print_stack(state.a, "A");
	destroy_state(&state);
	return (0);
}