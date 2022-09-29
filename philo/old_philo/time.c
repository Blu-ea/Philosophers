/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:37:26 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/29 17:09:46 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/old_philo.h"

u_int64_t	get_time(t_ph *data)
{
	u_int64_t		start;
	u_int64_t		current;
	struct timeval	now;

	gettimeofday(&now, NULL);
	start = (u_int64_t) data->start.tv_sec * 1000 + data->start.tv_usec / 1000;
	current = (u_int64_t) now.tv_sec * 1000
		+ now.tv_usec / 1000;
	return (current - start);
}

void	ft_usleep(u_int64_t time, t_ph *data, t_lst_ph *philo)
{
	struct timeval	now;
	struct timeval	current;

	gettimeofday(&now, NULL);
	current = now;
	pthread_mutex_lock(&data->state_check);
	while (philo->state == ALIVE)
	{
		pthread_mutex_unlock(&data->state_check);
		gettimeofday(&now, NULL);
		if ((u_int64_t)((now.tv_sec - current.tv_sec) * 1000
			+ (now.tv_usec - current.tv_usec) / 1000) > time)
			break ;
		pthread_mutex_lock(&data->state_check);
	}
	pthread_mutex_unlock(&data->state_check);
}

int	get_last_eat(t_lst_ph *philo, t_ph *data)
{
	struct timeval	now;
	int				time;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(&data->last_eat_check);
	time = (now.tv_sec - philo->last_eat.tv_sec) * 1000;
	time += (now.tv_usec - philo->last_eat.tv_usec) / 1000;
	pthread_mutex_unlock(&data->last_eat_check);
	return (time);
}
