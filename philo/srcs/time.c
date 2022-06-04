/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:29:42 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/04 16:18:47 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_usleep(useconds_t time, t_philo *data)
{
	u_int64_t	start;
	u_int64_t	current;

	start = get_time_start(data);
	current = get_time_start(data);
	while (current < start + time)
	{
		usleep (10);
		current = get_time_start(data);
	}
}

/**
 * @brief Get the time from the start
 * 
 * @param data 
 * @return int 
 */
int	get_time_start(t_philo *data)
{
	u_int64_t	start;
	u_int64_t	current;

	start = (data->start.tv_sec * (u_int64_t) 1000)
		+ (data->start.tv_usec / (u_int64_t) 1000);
	current = (data->current.tv_sec * (u_int64_t) 1000)
		+ (data->current.tv_usec / (u_int64_t) 1000);
	return (current - start);
}
