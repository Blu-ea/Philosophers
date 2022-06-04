/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:02:04 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/01 16:14:09 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_simul(void *philo)
{
	t_philo		*data;
	t_lst_ph	*ph;

	ph = (t_lst_ph *)philo;
	data = ph->data;
	gettimeofday(&ph->last_eat, NULL);
	if (ph->id % 2 != 0)
		ft_usleep(70);
	// printf("launch %d\n", ph->id);
	// printf ("state %d %d\n", ph->id, ph->state);
	while (check_dead(data))
	{
		if (ph->state == THINKING && ph->alive != DEAD)
			ft_eat(philo, data);
		else if (ph->state == EATING && ph->alive != DEAD)
			ft_sleep(philo, data);
	}
	return (NULL);
}

void	ft_eat(t_lst_ph *philo, t_philo *data)
{
	pthread_mutex_lock(&data->mutex[philo->fork_left]);
	ft_print_act(data, philo, "has taken a fork");
	pthread_mutex_lock(&data->mutex[philo->fork_right]);
	gettimeofday(&philo->last_eat, NULL);
	ft_print_act(data, philo, "has taken a fork");
	ft_print_act(data, philo, "is eating");
	philo->eat++;
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(&data->mutex[philo->fork_left]);
	pthread_mutex_unlock(&data->mutex[philo->fork_right]);
	philo->state = EATING;
}

void	ft_sleep(t_lst_ph *philo, t_philo *data)
{
	ft_print_act(data, philo, "is sleeping");
	ft_usleep(data->time_to_sleep);
	ft_print_act(data, philo, "is thinking");
	philo->state = THINKING;
}

void	ft_print_act(t_philo *data, t_lst_ph *ph, char *str)
{
	if (ph->alive != DEAD)
		printf("%d %d %s\n", ft_get_time(*data), ph->id, str);
}


/**
 * @brief va prendre en donne data et retourner 0 si un philo est mort
 * 
 * @param data 
 * @return id -> quellequ'un est mort | 0 -> tout est vivant
 */
int		check_dead(t_philo *data)
{
	int			i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (data->lst_philo[i].alive == DEAD)
			return (i);
		i++;
	}
	return (0);
}

/**
 * @brief retourne id si il elle trouve un philo mort qui n as pas manger
 * 
 * @param data 
 * @return int 
 */
int	ft_test_dead(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		calc_last_eat(&data->lst_philo[i], data);
		i++;
	}
	if (i == data->nb_philo)
		return (0);
	return (check_dead(data));
}
