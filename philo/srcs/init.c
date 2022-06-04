/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:42:55 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/04 19:40:22 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_mutex_init(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->mutex[i], NULL) != 0)
			return (i);
		i++;
	}
	return (0);
}

void	ft_thread_init(t_philo *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		data->lst_philo[i].id = i;
		data->lst_philo[i].state = THINKING;
		data->lst_philo[i].alive = ALIVE;
		data->lst_philo[i].fork_left = i;
		data->lst_philo[i].fork_right = (i + 1) % data->nb_philo;
		data->lst_philo[i].eat = 0;
	}
}
