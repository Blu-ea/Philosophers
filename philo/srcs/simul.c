/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:23:09 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/04 19:40:47 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_simul(void *arg)
{
	t_lst_ph	*ph;
	int			i;
	t_philo		*data;

	ph = (t_lst_ph *) arg;
	data = ph->data;
	i = 0;
	while (i != data->nb_must_eat && ph->alive == ALIVE)
	{
		if (ph->state == THINKING && ph->alive == ALIVE)
			ph_eat(ph, data);
		if (ph->state == SLEEPING && ph->alive == ALIVE)
			ph_sleep(ph, data);
		i++;
	}
	return (0);
}

void	ph_eat(t_lst_ph *ph, t_philo *data)
{
	pthread_mutex_lock(&data->mutex[ph->fork_left]);
	if (ph->alive == ALIVE)
		printf("%d %d has taken a fork\n", get_time_start(data), ph->id);
	pthread_mutex_lock(&data->mutex[ph->fork_right]);
	if (ph->alive == ALIVE)
		printf("%d %d has taken a fork\n", get_time_start(data), ph->id);
	if (ph->alive == ALIVE)
		printf("%d %d is eating\n", get_time_start(data), ph->id);
	ft_usleep(data->time_to_eat, data);
	ph->state = SLEEPING;
}

void	ph_sleep(t_lst_ph *ph, t_philo *data)
{
	if (ph->alive == ALIVE)
		printf("%d %d is sleeping\n", get_time_start(data), ph->id);
	ft_usleep(data->time_to_sleep, data);
}
