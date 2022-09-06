/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:54:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/06 20:48:46 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/new_philo.h"

int	ft_error(int id, t_ph *data)
{
	if (id == __NO_ARG || id == __WRONG_ARG)
		usage();
	if (id == __MALLOC_FORK)
		printf("Malloc Failed");
	if (id == __FORK)
		error_data(data, data->i, id);
	if (id >= __CHECK1 && id <= __CHECK4)
		error_mutex(data, id);
	return (EXIT_FAILURE);
}

void	usage(void)
{
	printf ("Usage : ./philo number_of_philosophers time_to_die time_to_eat");
	printf (" time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
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
