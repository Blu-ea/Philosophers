/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:39:56 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/07 20:40:53 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/new_philo.h"

int	main(int argc, char **argv)
{
	t_ph	data;

	if (argc != 5 && argc != 6)
		return (ft_error(__NO_ARG, &data));
	if (parsing(argv) == EXIT_FAILURE)
		return (ft_error(__WRONG_ARG, &data));
	if (init(argc, argv, &data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (launch(&data) == EXIT_FAILURE)
		return (ft_error(__PTHREAD, &data));
	check_loop(&data);
	pthread_mutex_lock(&data.state_check);
	kill_all(&data, data.nb_philo);
	return (0);
}

int	launch(t_ph *data)
{
	data->i = 0;
	gettimeofday(&data->start, NULL);
	while (data->i < data->nb_philo)
	{
		if (pthread_create(&data->philo[data->i].thread, NULL,
				routine, &data->philo[data->i]))
			return (EXIT_FAILURE);
		data->i++;
	}
	return (EXIT_SUCCESS);
}

void	check_loop(t_ph *data)
{
	int	i;
	int	lock;

	lock = 1;
	while (lock)
	{
		i = 0;
		while (i < data->nb_philo && lock)
		{
			pthread_mutex_lock(&data->eat_check);
			if (data->philo[i].eat != 0)
				lock = 0;
			pthread_mutex_unlock(&data->eat_check);
			pthread_mutex_lock(&data->last_eat_check);
			if (get_last_eat(&data->philo[i], data) >= data->t_die)
			{
				state_print(&data->philo[i], data, _DIED);
				lock = 0;
			}
			pthread_mutex_unlock(&data->last_eat_check);
			i++;
		}
	}
}

void	kill_all(t_ph *data, int i)
{
	pthread_mutex_lock(&data->state_check);
	while (i)
	{
		i--;
		data->philo[i].state = DEAD;
	}
	pthread_mutex_unlock(&data->state_check);
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&data->eat_check);
	pthread_mutex_destroy(&data->last_eat_check);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->state_check);
	free(data->philo);
	while (i)
	{
		i--;
		pthread_mutex_destroy(&data->fork[i]);
	}
	free(data->fork);
}
