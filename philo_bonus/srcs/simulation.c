/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 05:54:33 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/16 08:39:12 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_philo(void *arg)
{
	t_ph		*data;
	t_lst_ph	*ph;

	ph = (t_lst_ph *)arg;
	data = ph->data;
	ft_usleep(ph->id * 5);
	while (ph->alive == ALIVE)
	{
		if (ph->alive == ALIVE)
			ft_eat(data, ph);
		if (ph->alive == ALIVE)
			ft_sleep(data, ph);
	}
	return (NULL);
}

void	ft_eat(t_ph *data, t_lst_ph *ph)
{
	sem_wait(data->sem_fork);
	print_act(data, ph->id, "has taken a fork\n", 0);
	sem_wait(data->sem_fork);
	print_act(data, ph->id, "has taken a fork\n", 0);
	print_act(data, ph->id, "is eating\n", 0);
	gettimeofday(&ph->last_eat, NULL);
	if (ph->alive == ALIVE)
		ft_usleep(data->time_to_eat);
	sem_post(data->sem_fork);
	sem_post(data->sem_fork);
	if (ph->eat != -1 && ph->eat != 0)
		ph->eat--;
}

void	ft_sleep(t_ph *data, t_lst_ph *ph)
{
	print_act(data, ph->id, "is sleeping\n", 0);
	if (ph->alive == ALIVE)
		ft_usleep(data->time_to_sleep);
	print_act(data, ph->id, "is thinking\n", 0);
}

void	print_act(t_ph *data, int i, char *str, int pass)
{
	u_int64_t	time;

	time = get_time(data);
	if (data->lst_philo[i].alive == ALIVE || pass == 1)
		printf("%llu %d %s", time, i, str);
}
