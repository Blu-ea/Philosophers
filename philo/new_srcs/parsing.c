/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:20:03 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/06 20:57:41 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/new_philo.h"

int	parsing(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_is_digit(argv[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (ft_atoi(argv[1]) == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_is_digit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] > '9' || arg[i] < '0')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_atoi(char *str)
{
	int			i;
	long int	ret_int;
	int			minus;

	ret_int = 0;
	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		||str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i += 1;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		ret_int = ret_int * 10 + (str[i] - 48);
		i++;
	}
	return (ret_int * minus);
}
