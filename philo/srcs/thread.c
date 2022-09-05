/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:32:28 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/05 18:50:29 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_thread(void *arg)
{
	t_ph		*data;
	t_lst_ph	*ph;

	ph = (t_lst_ph *)arg;
	data = ph->data;
	print_act(data, ph->id, "is thinking\n", 0);
	if (ph->id % 2 != 0)
		ft_usleep(50);
	while (ph->alive == ALIVE)
	{
		if (ph->alive == ALIVE)
			ft_eat(ph, data);
		if (ph->alive == ALIVE)
			ft_sleep(ph, data);
	}
	return (0);
}

void	ft_eat(t_lst_ph *ph, t_ph *data)
{
	pthread_mutex_lock(&data->mutex[ph->fork_left]);
	print_act(data, ph->id, "has taken a fork\n", 0);
	pthread_mutex_lock(&data->mutex[ph->fork_right]);
	print_act(data, ph->id, "has taken a fork\n", 0);
	gettimeofday(&ph->last_eat, NULL);
	print_act(data, ph->id, "is eating\n", 0);
	//pthread_mutex_lock(&data->kill_all);
	if (ph->alive == ALIVE)
		ft_usleep(data->time_to_eat);
	//pthread_mutex_unlock(&data->kill_all);
	pthread_mutex_unlock(&data->mutex[ph->fork_left]);
	pthread_mutex_unlock(&data->mutex[ph->fork_right]);
	//pthread_mutex_lock(&data->end);
	if (ph->eat != -1 && ph->eat != 0)
		ph->eat--;
	//pthread_mutex_unlock(&data->end);
}

void	ft_sleep(t_lst_ph *ph, t_ph *data)
{
	print_act(data, ph->id, "is sleeping\n", 0);
	if (ph->alive == ALIVE)
		ft_usleep(data->time_to_sleep);
	print_act(data, ph->id, "is thinking\n", 0);
}

void	print_act(t_ph *data, int i, char *str, int pass)
{
	u_int64_t	time;

	pthread_mutex_lock(&data->print);
	time = get_time(data);
	//pthread_mutex_lock(&data->kill_all);
	if (data->lst_philo[i].alive == ALIVE || pass == 1)
		printf("%llu %d %s", time, i, str);
	//pthread_mutex_unlock(&data->kill_all);
	pthread_mutex_unlock(&data->print);
}
