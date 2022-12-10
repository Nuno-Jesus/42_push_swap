/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:55:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/12/10 03:57:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"
#include "../includes/state.h"
#include "../includes/operations.h"

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
//2147483647 -2147483648
int	main(int argc, char **argv)
{
	//size_t	size;
	//t_state	*state;
	if (argc < 2)
		return (EXIT_FAILURE);
	if (!valid_args(argc - 1, argv + 1))
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (EXIT_FAILURE);	
	}
		
	/* size = ft_atoi(argv[1]);
	state = state_new(stack_new(size), stack_new(size));
	state_delete(state); */
}

/*
if (!is_number(argv[i]))
	{
		printf("\"%s\" is not a number\n", argv[i]);
		return (false);
	}
	if (!is_int(argv[i]))
	{
		printf("\"%s\" is not an int\n", argv[i]);
		return (false);
	}
	if (is_duplicated(argv, i))
	{
		printf("\"%s\" is duplicated\n", argv[i]);
		return (false);
	}
*/

/* 
	for(size_t i = 0; i < size; i++)
	{
		stack_push(a, size - i);
		printf("\n\tSIZE: %ld\n\n", i);
		stack_print(a);	
	} 
*/
/* 
	stack_pop(a);
	printf("\n\t===== TESTING POP =====\n\n");
	stack_print(a);
*/
/* 	
	printf("\n\t===== TESTING PUSH B  =====\n\n");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	
	printf("\n\t===== B =====\n\n");
	stack_print(b);	
	
	push(state->b, state->a, "pb");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	
	printf("\n\t===== B =====\n\n");
	stack_print(b);	
	
	printf("\n\t===== TESTING SWAP A  =====\n\n");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	
	
	swap(state->a, "sa");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);		
	 
	printf("\n\t===== TESTING ROTATE A  =====\n\n");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	
	
	rotate(state->a, "ra");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	
	
	printf("\n\t===== TESTING REVERSE A  =====\n\n");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	
	
	reverse(state->a, "rra");
	
	printf("\n\t===== A =====\n\n");
	stack_print(a);	
 */	