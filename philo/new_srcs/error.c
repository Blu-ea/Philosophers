/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:54:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/06 19:23:57 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/new_philo.h"

int	ft_error(int id, t_ph *data)
{
	if (id == __NO_ARG || id == __WRONG_ARG)
		usage();
	if (id == __MALLOC_FORK)
		printf("Malloc failed");
	if (id == __FORK)
		error_data(data, data->i);
	return (EXIT_FAILURE);
}

void	usage(void)
{
	printf ("Usage : ./philo number_of_philosophers time_to_die time_to_eat");
	printf (" time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
}

void	error_data(t_ph *data, int i)
{
	while (--i)
		pthread_mutex_destroy(&data->fork[i]);
	free(data->fork);
}
