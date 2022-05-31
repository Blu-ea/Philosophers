/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 07:29:04 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/30 12:15:53 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(int error, t_philo *data, int i)
{
	if (error == WRONG_ARGS)
		printf("Error: Wrongs args\n");
	else if (error == MAL_1)
		printf("Error: Malloc failed\n");
	else if (error == MAL_2)
		printf("Error: Malloc failed\n");
	else if (error == THREAD_ERR)
		ft_error_thread(data, i);
	else
		ft_error_mutex(data, error - MUTEX_ERR);
	return (error);
}

void	ft_error_thread(t_philo *data, int limit)
{
	int	i;

	i = -1;
	while (++i < limit)
		pthread_cancel(data->lst_philo[i].thread);
	ft_error_mutex(data, data->nb_philo);
}

void	ft_error_mutex(t_philo *data, int limit)
{
	int	i;

	i = -1;
	while (++i < limit)
		pthread_mutex_destroy(&data->mutex[i]);
}

void	ft_leave(t_philo *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_join(data->lst_philo[i].thread, NULL);
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&data->mutex[i]);
}
