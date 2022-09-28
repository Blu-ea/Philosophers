/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:39:56 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/28 18:13:09 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

int	main(int argc, char **argv)
{
	t_ph	data;

	if (argc != 5 && argc != 6)
		return (ft_error(__NO_ARG, &data));
	if (parsing(argv) == EXIT_FAILURE)
		return (ft_error(__WRONG_ARG, &data));
	if (init(argc, argv, &data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (launch(&data) == EXIT_FAILURE)
		return (ft_error(__PTHREAD, &data));
	check_loop(&data);
	kill_all(&data);
	return (0);
}

int	launch(t_ph *data)
{
	data->i = 0;
	pthread_mutex_init(&data->m_start, NULL);
	pthread_mutex_lock(&data->m_start);
	while (data->i < data->nb_philo)
	{
		gettimeofday(&data->philo[data->i].last_eat, NULL);
		if (pthread_create(&data->philo[data->i].thread, NULL,
				routine, &data->philo[data->i]))
			return (EXIT_FAILURE);
		data->i++;
	}
	gettimeofday(&data->start, NULL);
	pthread_mutex_unlock(&data->m_start);
	return (EXIT_SUCCESS);
}

void	check_loop(t_ph *data)
{
	int	i;
	int	end;
	int	last_eat;

	last_eat = 0;
	usleep((data->t_die * 1000) / 2);
	while (data->state_check.__opaque[24] == 0)
	{
		end = 1;
		i = 0;
		while (i < data->nb_philo && last_eat == 0)
		{
			pthread_mutex_lock(&data->eat_check);
			if (data->philo[i].eat != 0)
				end = 0;
			pthread_mutex_unlock(&data->eat_check);
			if (g_last_eat(data->philo[i], data))
			{
				print_state(data->philo, data, _DIED);
				last_eat = 1;
			}
			i++;
		}
		if (end == 1)
			pthread_mutex_lock(&data->state_check);
	}
}

void	kill_all(t_ph *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	while (i)
	{
		i--;
		pthread_mutex_destroy(&data->fork[i]);
	}
}

int	g_last_eat(t_lst_ph philo, t_ph *data)
{
	struct timeval	time;
	int				ret;

	gettimeofday(&time, NULL);
	pthread_mutex_lock(&data->last_eat_check);
	ret = ((philo.last_eat.tv_sec * 1000 - time.tv_sec * 1000)
			+ (philo.last_eat.tv_usec / 1000 - time.tv_usec / 1000)) * -1;
	pthread_mutex_unlock(&data->last_eat_check);
	if (ret > data->t_die)
		return (1);
	return (0);
}
