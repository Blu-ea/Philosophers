/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:01:50 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/30 13:40:03 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo	data;
	int		i;
	int		j;

	i = ft_pars(argc, argv, &data);
	if (i != 0)
		return (ft_error(i, &data, 0));
	i = ft_init(&data);
	if (i != 0)
		return (ft_error(i, &data, 0));
	gettimeofday(&data.start, NULL);
	i = thread_create(&data);
	if (i != 0)
		return (ft_error(THREAD_ERR, &data, i));
	while (ft_check_dead(&data, -1) == 0)
		ft_usleep(10);
	ft_leave(&data);
	free (data.lst_philo);
	free (data.mutex);
}

int	ft_init(t_philo *data)
{
	int	i;

	data->lst_philo = malloc(sizeof(t_lst_ph) * data->nb_philo);
	if (data->lst_philo == NULL)
		return (MAL_2);
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (data->mutex == NULL)
		return (MAL_1);
	i = -1;
	while (++i < data->nb_philo)
	{
		data->lst_philo[i].id = i;
		data->lst_philo[i].data = data;
		data->lst_philo[i].fork_right = i;
		data->lst_philo[i].fork_left = i - 1;
		data->lst_philo[i].state = ALIVE;
		if (pthread_mutex_init(&data->mutex[i], NULL))
			return (MUTEX_ERR + i);
	}
	if (data->nb_philo != 1)
		data->lst_philo[0].fork_left = data->nb_philo - 1;
	return (0);
}

int	ft_check_dead(t_philo *data, int id)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		calc_last_eat(&data->lst_philo[i], data);
		if (data->lst_philo[i].state == DEAD)
		{
			if (id == i)
			{
				printf("{%llu} ========= ", ft_get_time(data->lst_philo[i]));
				printf("  Philosopher[%d] is  ==== dead\n", i);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	thread_create(t_philo *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < data->nb_philo)
	{
		data->lst_philo[i].last_eat = data->start;
		printf ("thread created\n");
		j = pthread_create(&data->lst_philo[i].thread, NULL,
				ft_thread, &data->lst_philo[i]);
		if (j != 0)
			return (i);
		ft_usleep(10);
		i++;
	}
	return (0);
}
