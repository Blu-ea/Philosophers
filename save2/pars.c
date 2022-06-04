/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:03:35 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/31 15:22:58 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_pars(int argc, char **argv, t_philo *data)
{
	if (argc != 5 && argc != 6)
		return (WRONG_ARGS);
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_must_eat = ft_atoi(argv[5]);
	else
		data->nb_must_eat = -1;
	if (ft_check_values(*data, argv))
		return (WRONG_ARGS);
	return (0);
}

int	ft_check_values(t_philo data, char **argv)
{
	if (data.nb_philo <= 0 || ft_is_all_digit(argv[1]))
		return (1);
	if (data.time_to_die < 0 || ft_is_all_digit(argv[2]))
		return (1);
	if (data.time_to_eat < 0 || ft_is_all_digit(argv[3]))
		return (1);
	if (data.time_to_sleep < 0 || ft_is_all_digit(argv[4]))
		return (1);
	if (data.nb_must_eat != -1)
		if (data.nb_must_eat < 0 || ft_is_all_digit(argv[5]))
			return (-1);
	return (0);
}

int	ft_is_all_digit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}
