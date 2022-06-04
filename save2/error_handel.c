/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:00:58 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/01 15:59:03 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(int err, t_philo *data, int place)
{
	if (err == WRONG_ARGS)
		printf("Error : Wrong arguments\n");
	if (err == MALLOC_ERROR || err == MALLOC_ERROR_2)
		printf ("Error : Malloc failed\n");
	if (err == MUTEX_ERROR)
		ft_error_mutex(data, place);
	if (err == THREAD_ERROR)
		ft_error_thread(data, place);
	if (err >= MALLOC_ERROR_2)
		free (data->lst_philo);
	if (err > MALLOC_ERROR_2)
		free (data->mutex);
	return (err);
}

void	ft_error_mutex(t_philo *data, int place)
{
	int	i;

	i = 0;
	while (i < place)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		i++;
	}
	printf("Error : Mutex failed\n");
}

void	ft_error_thread(t_philo *data, int place)
{
	int	i;

	i = 0;
	while (i < place)
	{
		pthread_join(data->lst_philo[i].thread, NULL);
		i++;
	}
	printf("Error : Thread failed\n");
	ft_error_mutex(data, data->nb_philo);
}
