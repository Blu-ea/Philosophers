/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:45:25 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/04 19:38:24 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo	data;
	int		i;

	i = ft_pars(argc, argv, &data);
	if (i != 0)
		return (ft_error(i, &data, 0));
	i = ft_mutex_init(&data);
	if (i != 0)
		return (ft_error(MUTEX_ERROR, &data, i));
	ft_thread_init(&data);
	i = 0;
	gettimeofday(&data.start, NULL);
	while (i < data.nb_philo)
	{
		data.lst_philo[i].data = &data;
		if (pthread_create(&data.lst_philo[i].thread, NULL, ft_simul, &data.lst_philo[i]))
			return (ft_error(THREAD_ERROR, &data, i));
		i++;
	}
	while (check_death(&data))
		;
	kill_all(&data);
	return (0);
}

int	ft_error(int err_code, t_philo *data, int place)
{
	if (err_code == WRONG_ARGS)
		printf ("Error : Wrong arguments\n");
	if (err_code == MALLOC_ERROR)
		printf ("Error : Malloc error\n");
	if (err_code == MALLOC_ERROR_2)
		printf ("Error : Malloc error\n");
	if (err_code == MUTEX_ERROR)
	{
		while (place--)
			pthread_mutex_destroy(&data->mutex[place]);
	}
	if (err_code == THREAD_ERROR)
	{
		kill_all(data);
		while (data->nb_philo--)
			pthread_mutex_destroy(&data->mutex[place]);
		while (place--)
			pthread_join(data->lst_philo[place].thread, NULL);
		printf ("Error : Thread error\n");
	}
	if (err_code <= MALLOC_ERROR_2)
		free(data->lst_philo);
	if (err_code <= MUTEX_ERROR)
		free(data->mutex);
	return (err_code);
}

void	kill_all(t_philo *data)
{
	int	i;

	i = 0;
	printf ("\n========= KILL ALL ========\n\n");
	while (i < data->nb_philo)
	{
		data->lst_philo[i].alive = DEAD;
		i++;
	}
}

/**
 * @brief will return 1 if someone is dead, 0 otherwise
 */
int	check_death(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (data->lst_philo[i].alive == DEAD)
			return (1);
		i++;
	}
	return (0);
}