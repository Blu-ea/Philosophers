/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:45:25 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/04 17:00:15 by amiguez          ###   ########.fr       */
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
	i = 0;
	gettimeofday(&data.start, NULL);
	while (i < data.nb_philo)
	{
		if (pthread_create(&data.lst_philo[i].thread, NULL,
				ft_simul, &data.lst_philo[i]) != 0)
			return (ft_error(THREAD_ERROR, &data, i));
		i++;
	}
}

int	ft_error(int err_code, t_philo *data, int place)
{
	if (err_code == WRONG_ARGS)
		printf ("Error : Wrong arguments\n");
	if (err_code == MALLOC_ERROR)
		printf ("Error : Malloc error\n");
	if (err_code == MALLOC_ERROR_2)
	{
		free(data->lst_philo);
		printf ("Error : Malloc error\n");
	}
	if (err_code == MUTEX_ERROR)
	{
		while (place--)
			pthread_mutex_destroy(&data->mutex[place]);
		free(data->mutex);
		free(data->lst_philo);
	}
	if (err_code == THREAD_ERROR)
	{
		kill_all(data);
		free(data->lst_philo);
		free(data->mutex);
		printf ("Error : Thread error\n");
	}
	return (err_code);
}

void	kill_all(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->lst_philo[i].alive = DEAD;
		i++;
	}
}
