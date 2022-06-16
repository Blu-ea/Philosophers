/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:38:30 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/16 07:04:43 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_error(int i, t_ph *data, int place)
{
	if (i == WRONG_ARGS || i == WRONG_ARGS_2)
		printf ("Wrong arguments\n");
	if (i == ERROR_SEM)
		printf ("Semaphore Failed\n");
	if (i > ERROR_SEM)
	{
		if (i == ERROR_MALLOC)
			printf ("Malloc Failed\n");
		sem_close(data->sem_fork);
		sem_unlink(SEMAFORK);
	}
	if (i > ERROR_MALLOC)
		free(data->lst_philo);
	if (i == ERROR_THREAD)
		ft_error_thread(place, data);
	return (1);
}

void	ft_error_thread(int place, t_ph *data)
{
	int	i;

	printf("Thread %d failed\n", place);
	i = -1;
	while (++i < data->nb_philo)
		data->lst_philo[i].alive = DEAD;
	i = -1;
	while (++i < place)
		pthread_join(data->lst_philo[i].thread, NULL);
	free(data->lst_philo);
}
