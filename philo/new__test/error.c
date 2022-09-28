/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:54:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/28 13:39:00 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

int	ft_error(int id, t_ph *data)
{
	if (id == __NO_ARG || id == __WRONG_ARG)
	{
		printf ("Usage : ./philo number_of_philosophers time_to_die time_to_eat"
			" time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	}
	if (id == __MALLOC_FORK)
		printf("Malloc Failed");
	if (id == __FORK)
		error_data(data, data->i, id);
	if (id >= __CHECK1 && id <= __CHECK4)
		error_mutex(data, id);
	if (id == __MALLOC_PHILO)
		error_malloc_philo(data, __MALLOC_PHILO);
	if (id == __PTHREAD)
		error_pthread(data, __PTHREAD);
	return (EXIT_FAILURE);
}

void	error_data(t_ph *data, int i, int id)
{
	while (--i)
		pthread_mutex_destroy(&data->fork[i]);
	if (id == __FORK)
		printf ("Mutex Failed");
	free (data->fork);
}

void	error_mutex(t_ph *data, int id)
{
	if (id > __CHECK1)
		pthread_mutex_destroy(&data->state_check);
	if (id > __CHECK2)
		pthread_mutex_destroy(&data->eat_check);
	if (id > __CHECK3)
		pthread_mutex_destroy(&data->last_eat_check);
	if (id > __CHECK4)
		pthread_mutex_destroy(&data->print);
	if (id >= __CHECK1 && id <= __CHECK4)
		printf ("Mutex Failed");
	error_data(data, data->nb_philo, id);
}

void	error_malloc_philo(t_ph *data, int id)
{
	if (id == __MALLOC_PHILO)
		printf ("Malloc failed");
	else
		free(data->philo);
	error_mutex(data, id);
}

void	error_pthread(t_ph *data, int id)
{
	if (id == __PTHREAD)
		printf ("Threading failed");
	pthread_mutex_lock(&data->state_check);
	while (data->i)
	{
		data->i--;
		pthread_join(data->philo[data->i].thread, NULL);
		data->philo[data->i].state = DEAD;
	}
	pthread_mutex_unlock(&data->state_check);
	error_malloc_philo(data, id);
}
