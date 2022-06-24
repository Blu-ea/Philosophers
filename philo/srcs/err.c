/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:38:30 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/24 14:43:38 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(int i, t_ph *data)
{
	if (i == WRONG_ARGS || i == WRONG_ARGS_2)
		ft_putendl_fd("Wrong arguments", 2);
	if (i >= MALLOC_ERROR_2)
		free(data->lst_philo);
	if (i == MALLOC_ERROR || i == MALLOC_ERROR_2)
		ft_putendl_fd("Malloc error", 2);
	if (i > MALLOC_ERROR_2)
		free(data->mutex);
	if (i == MUTEX_ERROR)
		ft_putendl_fd("Mutex error", 2);
	return (i);
}

int	ft_error_mutex(int i, t_ph *data)
{
	i--;
	while (i)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		i--;
	}
	return (MUTEX_ERROR);
}

int	ft_error_thread(int i, t_ph *data)
{
	i--;
	kill_all(data);
	while (i)
	{
		pthread_join(data->lst_philo[i].thread, NULL);
		i--;
	}
	return (THREAD_ERROR);
}
