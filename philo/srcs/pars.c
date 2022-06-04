/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:46:37 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/04 18:19:46 by amiguez          ###   ########.fr       */
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
	if (ft_check_values(data, argv, argc))
		return (WRONG_ARGS);
	data->lst_philo = malloc(sizeof (t_philo) * data->nb_philo);
	if (data->lst_philo == NULL)
		return (MALLOC_ERROR);
	data->mutex = malloc(sizeof (pthread_mutex_t) * data->nb_philo);
	if (data->mutex == NULL)
		return (MALLOC_ERROR_2);
	return (0);
}

int	ft_check_values(t_philo *data, char **argv, int argc)
{
	if (data->nb_philo <= 0)
		return (1);
	if (data->time_to_die < 0)
		return (1);
	if (data->time_to_eat < 0)
		return (1);
	if (data->time_to_sleep < 0)
		return (1);
	if (argc == 6)
		if (data->nb_must_eat < 0)
			return (1);
	if (!ft_is_all_digit(argv[1]))
		return (1);
	if (!ft_is_all_digit(argv[2]))
		return (1);
	if (!ft_is_all_digit(argv[3]))
		return (1);
	if (!ft_is_all_digit(argv[4]))
		return (1);
	if (argc == 6)
		if (!ft_is_all_digit(argv[5]))
			return (1);
	return (0);
}
