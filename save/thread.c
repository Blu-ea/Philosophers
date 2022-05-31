/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:05:42 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/30 13:33:49 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_thread(void *temp)
{
	t_lst_ph	*ph;
	t_philo		*data;

	ph = (t_lst_ph *)temp;
	data = ph->data;
	if (ph->id % 2 != 0)
		ft_usleep(150);
	while (1)
	{
		ft_action_print(ph, ph->id, "thinking");
		pthread_eat(data, ph);
		if (ft_check_dead(data, ph->id) == 1)
			break ;
		pthread_sleep(data, ph);
		if (ft_check_dead(data, ph->id) == 1)
			break ;
	}
	printf ("philo [%d] is out\n", ph->id);
	return ((void *)(0));
}

void	ft_action_print(t_lst_ph *ph, int i, char *str)
{
	u_int64_t	time;

	time = ft_get_time(*ph);
	printf("{%llu}  Philosopher[%d] is %s\n", time, ph->id, str);
}

void	pthread_eat(t_philo *data, t_lst_ph *ph)
{
	pthread_mutex_lock(&data->mutex[ph->fork_left]);
	ft_action_print(ph, ph->id, "taking a fork");
	pthread_mutex_lock(&data->mutex[ph->fork_right]);
	ft_action_print(ph, ph->id, "taking a fork");
	gettimeofday(&ph->last_eat, NULL);
	ft_action_print(ph, ph->id, "eating");
	ft_usleep(data->time_to_eat * 1000);
	ft_action_print(ph, ph->id, "done eating");
	pthread_mutex_unlock(&data->mutex[ph->fork_left]);
	pthread_mutex_unlock(&data->mutex[ph->fork_right]);
}

void	pthread_sleep(t_philo *data, t_lst_ph *ph)
{
	ft_action_print(ph, ph->id, "sleeping");
	ft_usleep(data->time_to_sleep * 1000);
}
