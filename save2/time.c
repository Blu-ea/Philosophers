/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:09:29 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/01 16:10:49 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

u_int32_t	ft_get_time(t_philo data)
{
	u_int32_t	start;
	u_int32_t	current;

	gettimeofday(&data.current, NULL);
	start = (data.start.tv_sec * (u_int32_t) 1000)
		+ (data.start.tv_usec / (u_int32_t) 1000);
	current = (data.current.tv_sec * (u_int32_t) 1000)
		+ (data.current.tv_usec / (u_int32_t) 1000);
	return (current - start);
}

void	ft_usleep(useconds_t time)
{
	struct timeval	start;
	struct timeval	current;

	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&current, NULL);
		if (((current.tv_sec * (u_int64_t) 1000)
				+ (current.tv_usec / (u_int64_t) 1000))
			- ((start.tv_sec * (u_int64_t) 1000)
				+ (start.tv_usec / (u_int64_t) 1000)) > time)
			break ;
	}
}

void	calc_last_eat(t_lst_ph *ph, t_philo *data)
{
	struct timeval	time;
	u_int64_t		start;
	u_int64_t		current;

	gettimeofday(&time, NULL);
	start = (ph->last_eat.tv_sec * (u_int64_t) 1000)
		+ (ph->last_eat.tv_usec / (u_int64_t) 1000);
	current = (time.tv_sec * (u_int64_t) 1000)
		+ (time.tv_usec / (u_int64_t) 1000);
	if (current - start > (u_int64_t) data->time_to_die)
	{
		// printf ("last eat kill philo %d\n", ph->id);
		ph->alive = DEAD;
		// ft_print_act(data, ph, "has died");
		// printf("%d %d has died\n", ft_get_time(*data), ph->id);
	}
	// printf("=== %d ===\n", ph->id);
	// printf ("current = %d\n", current);
	// printf ("start = %d\n", start);
	// printf ("curent - start = %d\n", current - start);
}
