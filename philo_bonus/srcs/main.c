/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:25:05 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/16 08:36:06 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_ph	data;
	int		i;

	sem_unlink("/sem_fork2");
	sem_unlink(SEMAFORK);
	i = ft_pars(argc, argv, &data);
	if (i != 0)
		return (ft_error(i, &data, 0));
	i = ft_init(&data);
	if (i != 0)
		return (ft_error(i, &data, 0));
	i = ft_launch(&data);
	if (i != 0)
		return (ft_error(ERROR_THREAD, &data, i));
	while (check_dead(&data))
		;
	kill_all(&data);
	ft_exit(&data);
}

int	ft_launch(t_ph *data)
{
	int	i;

	i = 0;
	gettimeofday(&data->start, NULL);
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->lst_philo[i].thread, NULL,
				ft_philo, &data->lst_philo[i]))
			return (i);
		gettimeofday(&data->lst_philo[i].last_eat, NULL);
		i++;
	}
	return (0);
}

int	ft_init(t_ph *data)
{
	int	i;
	int	value;
	int	j;

	i = 0;
	data->sem_fork = sem_open(SEMAFORK, O_CREAT, 777, data->nb_philo);
	if (data->sem_fork == SEM_FAILED)
		return (ERROR_SEM);
	data->lst_philo = malloc(sizeof(t_lst_ph) * data->nb_philo);
	if (data->lst_philo == NULL)
		return (ERROR_MALLOC);
	while (i < data->nb_philo)
	{
		data->lst_philo[i].id = i;
		data->lst_philo[i].data = data;
		data->lst_philo[i].alive = ALIVE;
		data->lst_philo[i].eat = data->nb_must_eat;
		i++;
	}
	return (0);
}

void	kill_all(t_ph *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->lst_philo[i].alive = DEAD;
		i++;
	}
}

void	ft_exit(t_ph *data)
{
	int	i;

	i = 0;
	sem_unlink(SEMAFORK);
	sem_close(data->sem_fork);
	while (i < data->nb_philo)
	{
		pthread_join(data->lst_philo[i].thread, NULL);
		i++;
	}
	free(data->lst_philo);
}
