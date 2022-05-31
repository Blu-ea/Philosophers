/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:02:04 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/31 18:25:54 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_simul(void *philo)
{
	t_philo		*data;
	t_lst_ph	*ph;

	ph = (t_lst_ph *)philo;
	data = ph->data;
	printf("launch %d\n", ph->id);
	printf ("state %d %d\n", ph->id, ph->state);
	gettimeofday(&ph->last_eat, NULL);
	while (ph->state != DEAD)
	{
		printf("test%d\n" , ph->id);
		calc_last_eat(ph, data);
		if (ph->state == THINKING)
			ft_eat(philo, data);
		else if (ph->state == EATING)
			ft_sleep(philo, data);
	}
	return (NULL);
}

void	ft_eat(t_lst_ph *philo, t_philo *data)
{
	if (philo->state == THINKING)
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
	}
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
	printf("%d %d %s\n", ft_get_time(*data), ph->id, str);
}

int	check_dead(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		calc_last_eat(&data->lst_philo[i], data);
		if (data->lst_philo[i].state == DEAD)
			return (0);
		i++;
	}
	return (1);
}
