/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:27:42 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/02/15 15:02:42 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_number(char *arg)
{
	if (*arg == '\0')
		return (false);
	if (*arg == '-' && ft_strlen(arg) > 1)
		arg++;
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

	i = -1;
	while (++i < argc)
		if (!is_number(argv[i]) || !is_int(argv[i]) || is_duplicated(argv, i))
			return (false);
	return (true);
}
