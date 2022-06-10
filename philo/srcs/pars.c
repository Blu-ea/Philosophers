/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:24:05 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/10 19:00:17 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_pars(int argc, char **argv, t_ph *data)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (WRONG_ARGS);
	if (ft_check_values(argv) != 0)
		return (WRONG_ARGS_2);
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_must_eat = ft_atoi(argv[5]);
	else
		data->nb_must_eat = -1;
	return (0);
}

int	ft_check_values(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_is_all_digit(argv[i]))
			return (1);
		i++;
	}
	if (ft_atoi(argv[1]) == 0)
		return (1);
	return (0);
}
