/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:07:41 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/30 12:18:44 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_pars(int argc, char **argv, t_philo *data)
{
	if (argc != 5 && argc != 6)
		return (WRONG_ARGS);
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_must_eat = ft_atoi(argv[5]);
	else
		data->nb_must_eat = -1;
	if (ft_check_values(*data))
		return (WRONG_ARGS);
	return (0);
}

int	ft_check_values(t_philo data)
{
	if (data.nb_philo <= 0)
		return (1);
	if (data.time_to_die < 0)
		return (1);
	if (data.time_to_eat < 0)
		return (1);
	if (data.time_to_sleep < 0)
		return (1);
	return (0);
}
