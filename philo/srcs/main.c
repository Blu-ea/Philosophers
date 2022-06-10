/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:25:05 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/10 19:55:05 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_ph	data;
	int		i;

	i = ft_pars(argc, argv, &data);
	if (i != 0)
		return (ft_error(i, NULL));
	i = ft_init(&data);
	if (i != 0)
		return (ft_error(i, NULL));
	i = ft_create_philo(&data);
	if (i != 0)
		return (ft_error(i, NULL));
	return (0);
	while (check_dead(&data))
		;
	kill_all(&data);
	ft_exit(&data);
}

int	ft_init(t_ph *data)
{
	int		i;

	i = 0;
	data->lst_philo = malloc(sizeof(t_ph) * data->nb_philo);
	if (data->lst_philo == NULL)
		return (MALLOC_ERROR);
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (data->mutex == NULL)
		return (MALLOC_ERROR_2);
	while (i < data->nb_philo)
	{
		data->lst_philo[i].id = i;
		data->lst_philo[i].fork_right = i;
		data->lst_philo[i].fork_left = i + 1 % data->nb_philo;
		data->lst_philo[i].data = data;
		data->lst_philo[i].alive = ALIVE;
		if (pthread_mutex_init(&data->mutex[i], NULL))
			return (ft_error_mutex(i, data));
		i++;
	}
	return (0);
}

int	ft_create_philo(t_ph *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->lst_philo[i].thread, NULL,
				ft_thread, &data->lst_philo[i]) != 0)
			return (ft_error_thread(i, data));
		i++;
	}
}

void	kill_all(t_ph *data)
{
	int	i;

	while (i < data->nb_philo)
	{
		data->lst_philo[i].alive = DEAD;
		i++;
	}
}

int	ft_check_dead(t_ph *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (data->lst_philo[i].alive == ALIVE)
			return (1);
		i++;
	}
}

int	ft_exit(t_ph *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->lst_philo[i].thread, NULL);
		pthread_mutex_destroy(&data->mutex[i]);
		i++;
	}
	free(data->lst_philo);
	free(data->mutex);
	return (0);
}
