/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:52:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/29 17:08:49 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *temp)
{
	t_lst_ph	*philo;
	t_ph		*data;

	philo = temp;
	data = philo->data;
	while (data->state_check.__opaque[24] != 0)
		;
	gettimeofday(&philo->last_eat, NULL);
	print_state(philo, data, _THINK);
	if (philo->id % 2 != 0)
		usleep((data->t_eat / 2) * 1000);
	routine_loop(data, philo);
	return (0);
}

void	routine_loop(t_ph *data, t_lst_ph *philo)
{
	while (data->state_check.__opaque[24] == 0)
	{
		if (philo->fork_l == philo->fork_r)
			break ;
		pthread_mutex_lock(&data->fork[philo->fork_l]);
		print_state(philo, data, _TAKE);
		pthread_mutex_lock(&data->fork[philo->fork_r]);
		print_state(philo, data, _TAKE);
		print_state(philo, data, _EAT);
		pthread_mutex_lock(&data->last_eat_check);
		gettimeofday(&philo->last_eat, NULL);
		pthread_mutex_unlock(&data->last_eat_check);
		ft_usleep(data->t_eat, data);
		pthread_mutex_unlock(&data->fork[philo->fork_l]);
		pthread_mutex_unlock(&data->fork[philo->fork_r]);
		pthread_mutex_lock(&data->eat_check);
		if (philo->eat > 0)
			philo->eat--;
		pthread_mutex_unlock(&data->eat_check);
		print_state(philo, data, _SLEEP);
		ft_usleep(data->t_sleep, data);
		print_state(philo, data, _THINK);
	}
}

void	print_state(t_lst_ph *philo, t_ph *data, int state)
{
	long long unsigned int	time;

	pthread_mutex_lock(&data->print);
	time = get_time(data);
	if (state == _DIED)
		printf ("%llu %d %s\n", time, philo->id + 1, _DIING);
	else if (data->state_check.__opaque[24] == 0)
	{
		if (state == _TAKE)
			printf ("%llu %d %s\n", time, philo->id + 1, _TAKEN_FORK);
		if (state == _EAT)
			printf ("%llu %d %s\n", time, philo->id + 1, _EATING);
		if (state == _SLEEP)
			printf ("%llu %d %s\n", time, philo->id + 1, _SLEEPING);
		if (state == _THINK)
			printf ("%llu %d %s\n", time, philo->id + 1, _THINKING);
	}
	pthread_mutex_unlock(&data->print);
}

void	ft_usleep(int time, t_ph *data)
{
	int				start;
	int				current;
	struct timeval	now;
	struct timeval	before;

	gettimeofday(&now, NULL);
	gettimeofday(&before, NULL);
	start = before.tv_sec * 1000 + before.tv_usec / 1000;
	current = now.tv_sec * 1000 + now.tv_usec / 1000;
	while (data->state_check.__opaque[24] == 0 && current - start < time)
	{
		gettimeofday(&now, NULL);
		current = now.tv_sec * 1000 + now.tv_usec / 1000;
		usleep(1000);
	}
}

u_int64_t	get_time(t_ph *data)
{
	u_int64_t		start;
	u_int64_t		current;
	struct timeval	now;

	gettimeofday(&now, NULL);
	start = (u_int64_t) data->start.tv_sec * 1000 + data->start.tv_usec / 1000;
	current = (u_int64_t) now.tv_sec * 1000 + now.tv_usec / 1000;
	return (current - start);
}
