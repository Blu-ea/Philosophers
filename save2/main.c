/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:58:41 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/01 16:15:18 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo	data;
	int		i;

	if (ft_pars(argc, argv, &data))
		return (ft_error(WRONG_ARGS, &data, 0));
	i = ft_init_philo(&data);
	if (i != 0)
		return (ft_error(i, &data, 0));
	i = ft_init_threads(&data);
	if (i != 0)
		return (ft_error(THREAD_ERROR, &data, i));
	i = ft_test_dead(&data);
	while (!i)
		i = ft_test_dead(&data);
	ft_print_act(&data,&data.lst_philo[i], "has died");
	ft_kill_all(&data);
	return (0);
}

int	ft_init_philo(t_philo *data)
{
	int		i;

	i = 0;
	data->lst_philo = malloc((sizeof(t_lst_ph)) * (data->nb_philo));
	if (!data->lst_philo)
		return (MALLOC_ERROR);
	data->mutex = malloc((sizeof(pthread_mutex_t)) * (data->nb_philo));
	if (!data->mutex)
		return (MALLOC_ERROR_2);
	while (i < data->nb_philo)
	{
		data->lst_philo[i].id = i;
		data->lst_philo[i].eat = 0;
		data->lst_philo[i].state = THINKING;
		data->lst_philo[i].fork_left = i;
		data->lst_philo[i].fork_right = (i + 1) % data->nb_philo;
		data->lst_philo[i].data = data;
		data->lst_philo[i].alive = ALIVE;
		if (pthread_mutex_init(&data->mutex[i], NULL))
			return (ft_error(MUTEX_ERROR, data, i));
		i++;
	}
	return (0);
}

int	ft_init_threads(t_philo *data)
{
	int	i;

	i = 0;
	gettimeofday(&data->start, NULL);
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->lst_philo[i].thread, NULL,
				ft_simul, &data->lst_philo[i]))
			return (ft_error(THREAD_ERROR, data, i));
		i++;
	}
	return (0);
}

void	ft_kill_all(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		// printf ("==== Kill all ======\n");
		data->lst_philo[i].alive = DEAD;
		i++;
	}
	ft_leave(data);
}

void	ft_leave(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->lst_philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		i++;
	}
	free(data->lst_philo);
	free(data->mutex);
}

///////////////////////////////////

void	ft_printf_data(t_philo data)
{
	printf ("====== Debug ======\n");
	printf("nb_philo      : %d\n", data.nb_philo);
	printf("time_to_die   : %d\n", data.time_to_die);
	printf("time_to_eat   : %d\n", data.time_to_eat);
	printf("time_to_sleep : %d\n", data.time_to_sleep);
	printf("nb_must_eat   : %d\n", data.nb_must_eat);
	printf("\n");

	int	i;

	i = -1;
	while (++i < data.nb_philo)
	{
		printf("------ philo nb %d -----\n", i);
		printf("id = %d\n", data.lst_philo[i].id);
		printf("fork left = %d\n", data.lst_philo[i].fork_left);
		printf("fork right = %d\n", data.lst_philo[i].fork_right);
		printf("state = %d\n", data.lst_philo[i].state);
		printf("------------------------\n");
	}
	printf ("\n====== Debug ======\n");
}
