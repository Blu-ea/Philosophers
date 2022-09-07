/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:02:01 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/07 21:00:29 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/new_philo.h"

void	*routine(void *temp)
{
	t_lst_ph	*philo;
	t_ph		*data;

	philo = (t_lst_ph *)temp;
	data = philo->data;
	state_print(philo, data, _THINK);
	if (philo->id % 2 != 0)
		(ft_usleep(100));
	rout_loop(philo, data);
	return (0);
}

void	rout_loop(t_lst_ph *philo, t_ph *data)
{
	pthread_mutex_lock(&data->state_check);
	while (philo->state == ALIVE)
	{
		if (philo->state == ALIVE)
		{
			pthread_mutex_unlock(&data->state_check);
			ft_eat(philo, data);
			pthread_mutex_lock(&data->state_check);
		}
		if (philo->state == ALIVE)
		{
			pthread_mutex_unlock(&data->state_check);
			ft_sleep(philo, data);
			pthread_mutex_lock(&data->state_check);
		}
	}
	pthread_mutex_unlock(&data->state_check);
}

void	ft_eat(t_lst_ph *philo, t_ph *data)
{
	pthread_mutex_lock(&data->fork[philo->fork_l]);
	state_print(philo, data, _TAKE);
	pthread_mutex_lock(&data->fork[philo->fork_r]);
	state_print(philo, data, _TAKE);
	pthread_mutex_lock(&data->state_check);
	if (philo->state == ALIVE)
	{
		pthread_mutex_unlock(&data->state_check);
		pthread_mutex_lock(&data->last_eat_check);
		gettimeofday(&philo->last_eat, NULL);
		pthread_mutex_unlock(&data->last_eat_check);
		state_print(philo, data, _EAT);
		ft_usleep(data->t_eat);
	}
	pthread_mutex_unlock(&data->fork[philo->fork_l]);
	pthread_mutex_unlock(&data->fork[philo->fork_r]);
	pthread_mutex_lock(&data->eat_check);
	if (philo->eat != -1)
		philo->eat--;
	pthread_mutex_unlock(&data->eat_check);
}

void	ft_sleep(t_lst_ph *philo, t_ph *data)
{
	pthread_mutex_lock(&data->state_check);
	if (philo->state == ALIVE)
	{
		pthread_mutex_unlock(&data->state_check);
		state_print(philo, data, _SLEEP);
		ft_usleep(data->t_sleep);
	}
	state_print(philo, data, _THINK);
}

void	state_print(t_lst_ph *philo, t_ph *data, int action)
{
	uint64_t	time;

	time = get_time(data);
	pthread_mutex_lock(&data->print);
	pthread_mutex_lock(&data->state_check);
	if (philo->state == ALIVE)
	{
		pthread_mutex_unlock(&data->state_check);
		if (action == _TAKE)
			printf ("%llu %d %s\n", time, philo->id, _TAKEN_FORK);
		if (action == _EAT)
			printf ("%llu %d %s\n", time, philo->id, _EATING);
		if (action == _SLEEP)
			printf ("%llu %d %s\n", time, philo->id, _SLEEPING);
		if (action == _THINK)
			printf ("%llu %d %s\n", time, philo->id, _THINKING);
	}
	pthread_mutex_unlock(&data->state_check);
	if (action == _DIED)
		printf ("%llu %d %s", time, philo->id, _DIING);
	pthread_mutex_unlock(&data->print);
}
