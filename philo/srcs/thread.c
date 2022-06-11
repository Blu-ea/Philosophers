/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:32:28 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/11 20:46:09 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_thread(void *arg)
{
	t_ph		*data;
	t_lst_ph	*ph;

	ph = (t_lst_ph *)arg;
	data = ph->data;
	if (ph->id % 2 == 0)
		usleep(50);
	while (ph->alive == ALIVE)
	{
		if (ph->alive == ALIVE)
			ft_eat(ph, data);
		if (ph->alive == ALIVE)
			ft_sleep(ph, data);
	}
	printf ("%d is dead\n", ph->id);
	return (0);
}

void	ft_eat(t_lst_ph *ph, t_ph *data)
{
	pthread_mutex_lock(&data->mutex[ph->fork_left]);
	if (ph->alive == ALIVE)
		print_act(data, ph->id, "has taken a fork\n");
	pthread_mutex_lock(&data->mutex[ph->fork_right]);
	if (ph->alive == ALIVE)
		print_act(data, ph->id, "has taken a fork\n");
	if (ph->alive == ALIVE)
		print_act(data, ph->id, "is eating\n");
	gettimeofday(&ph->last_eat, NULL);
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(&data->mutex[ph->fork_left]);
	pthread_mutex_unlock(&data->mutex[ph->fork_right]);
	if (ph->eat != -1)
		ph->eat--;
}

void	ft_sleep(t_lst_ph *ph, t_ph *data)
{
	if (ph->alive == ALIVE)
		print_act(data, ph->id, "is sleeping\n");
	ft_usleep(data->time_to_sleep);
}

void	print_act(t_ph *data, int i, char *str)
{
	u_int64_t	time;

	time = get_time(data);
	if (data->lst_philo[i].alive == ALIVE)
		printf("%llu %d %s", time, i, str);
}
