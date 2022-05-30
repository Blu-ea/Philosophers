/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 07:29:04 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/30 02:17:36 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error(char *str, t_philo *data)
{
	if(data != NULL)
	{
		if (!data->lst_philo)
			free(data->lst_philo);
		if (!data->mutex)
			free(data->mutex);
	}
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	ft_error_mutex(char *str, t_philo *data, int i)
{
	int	j;

	j = -1;
	while (++j < i)
		pthread_mutex_destroy(&data->mutex[j]);
	ft_error(str, data);
}

void	ft_error_thread(char *str, t_philo *data, int i)
{
	int	j;

	j = -1;
	while (++j < i)
		pthread_join(data->lst_philo[j].thread, NULL);
	ft_error_mutex(str, data, data->nb_philo);
}
