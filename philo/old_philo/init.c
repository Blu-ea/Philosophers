/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:48:35 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/29 17:09:19 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/old_philo.h"

int	init(int argc, char **argv, t_ph *data)
{
	if (init_data(argc, argv, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_philo(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_data(int argc, char **argv, t_ph *data)
{
	data->i = 0;
	data->nb_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_eat = ft_atoi(argv[5]);
	else
		data->nb_eat = -1;
	data->fork = malloc (sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return (ft_error(__MALLOC_FORK, data));
	while (data->i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->fork[data->i], NULL))
			return (ft_error(__FORK, data));
		data->i++;
	}
	if (init_mutex(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_mutex(t_ph *data)
{
	if (pthread_mutex_init(&data->state_check, NULL))
		return (ft_error(__CHECK1, data));
	if (pthread_mutex_init(&data->eat_check, NULL))
		return (ft_error(__CHECK2, data));
	if (pthread_mutex_init(&data->last_eat_check, NULL))
		return (ft_error(__CHECK3, data));
	if (pthread_mutex_init(&data->print, NULL))
		return (ft_error(__CHECK4, data));
	return (EXIT_SUCCESS);
}

int	init_philo(t_ph *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_lst_ph) * data->nb_philo);
	if (!data->philo)
		return (ft_error(__MALLOC_PHILO, data));
	while (i < data->nb_philo)
	{
		data->philo[i].id = i;
		data->philo[i].fork_l = i;
		data->philo[i].fork_r = (i + 1) % data->nb_philo;
		data->philo[i].data = data;
		data->philo[i].state = ALIVE;
		data->philo[i].eat = data->nb_eat;
		i++;
	}
	return (EXIT_SUCCESS);
}
