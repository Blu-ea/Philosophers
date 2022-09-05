/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:55:58 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/05 18:50:17 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_dead(t_ph *data)
{
	int				i;
	struct timeval	now;
	int				eat;

	gettimeofday(&now, NULL);
	i = 0;
	eat = 1;
	while (i < data->nb_philo)
	{
		//pthread_mutex_lock(&data->end);
		if (data->lst_philo[i].eat != 0)
			eat = 0;
		//pthread_mutex_unlock(&data->end);
		calc_last_eat(data, i);
		if (data->lst_philo[i].alive == DEAD)
		{
			print_act(data, i, "died\n", 1);
			return (0);
		}
		i++;
	}
	if (eat == 1)
		return (0);
	return (1);
}

void	calc_last_eat(t_ph *data, int i)
{
	struct timeval	now;
	int				time_diff;

	gettimeofday(&now, NULL);
	time_diff = ((now.tv_sec - data->lst_philo[i].last_eat.tv_sec) * 1000
			+ (now.tv_usec - data->lst_philo[i].last_eat.tv_usec) / 1000);
	if (time_diff > data->time_to_die)
		data->lst_philo[i].alive = DEAD;
}

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

void	ft_usleep(u_int64_t time)
{
	struct timeval	now;
	struct timeval	current;

	gettimeofday(&now, NULL);
	current = now;
	while (1)
	{
		usleep(10);
		gettimeofday(&now, NULL);
		if ((u_int64_t)((now.tv_sec - current.tv_sec) * 1000
			+ (now.tv_usec - current.tv_usec) / 1000) > time)
			break ;
	}
}
