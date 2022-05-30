/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:01:50 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/29 23:54:41 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo		data;
	int			i;

	i = 0;
	ft_pars(argc, argv, &data);
	ft_init(&data);
	// ft_printf_data(data);
	gettimeofday(&data.start, NULL);
	while (i < data.nb_philo)
	{
		pthread_create(&data.lst_philo[i].thread, NULL, ft_thread, &data.lst_philo[i]);
		i++;
	}
	while (1)
		ft_check_dead(&data);
}

void	ft_init(t_philo *data)
{
	int	i;

	data->lst_philo = malloc(sizeof(t_lst_ph) * data->nb_philo);
	if (data->lst_philo == NULL)
		ft_error("malloc error", data);
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (data->mutex == NULL)
		ft_error("malloc error", data);
	i = -1;
	while (++i < data->nb_philo)
	{
		data->lst_philo[i].id = i;
		data->lst_philo[i].data = data;
		if (pthread_mutex_init(&data->mutex[i], NULL))
			ft_error_mutex("Error: pthread_mutex_init failed", data, i);
		data->lst_philo[i].fork_right = i;
		data->lst_philo[i].fork_left = i - 1;
		data->lst_philo[i].state = ALIVE;
	}
	if (data->nb_philo != 1)
		data->lst_philo[0].fork_left = data->nb_philo - 1;
}

void	ft_leave(t_philo *data, int i)
{
	int	j;
	j = 0;
	while (j < i)
	{
		pthread_join(data->lst_philo[i].thread, NULL);
		j++;
	}
	j = 0;
	while (j < data->nb_philo)
	{
		free(data->lst_philo);
		j++;
	}
	exit(0);
}

void	ft_check_dead(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (data->lst_philo[i].state == DEAD)
			ft_leave(data, i);
		i++;
	}

}