/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:07:41 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/28 07:09:44 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_pars(int argc, char **argv, t_philo *data)
{
	if (argc != 5 && argc != 6)
		ft_error ("Error: wrong number of arguments");
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_must_eat = ft_atoi(argv[5]);
	else
		data->nb_must_eat = -1;
	ft_check_values(*data);
}

void	ft_check_values(t_philo data)
{
	if (data.nb_philo < 0)
		ft_error ("Error: There must be at least one philosopher");
	if (data.time_to_die < 0)
		ft_error ("Error: time_to_die must be positive");
	if (data.time_to_eat < 0)
		ft_error ("Error: time_to_eat must be positive");
	if (data.time_to_sleep < 0)
		ft_error ("Error: time_to_sleep must be positive");
}
