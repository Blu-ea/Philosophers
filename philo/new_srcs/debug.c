/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:12:35 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/06 19:47:11 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/new_philo.h"

void	print_t_ph(t_ph data)
{
	int	i;

	printf("data -> nb_philo : %d\n", data.nb_philo);
	printf("data -> t_die : %d\n", data.t_die);
	printf("data -> t_eat : %d\n", data.t_eat);
	printf("data -> t_sleep : %d\n", data.t_sleep);
	printf("data -> nb_eat : %d\n", data.nb_eat);
	i = 0;
	printf("====== Philo\n");
	while (i < data.nb_philo)
	{
		printf("   id		: %d\n", data.philo[i].id);
		printf("   fork_l	: %d\n", data.philo[i].fork_l);
		printf("   fork_r	: %d\n", data.philo[i].fork_r);
		printf("   state	: %d\n", data.philo[i].state);
		printf("   eat		: %d\n", data.philo[i].eat);
		printf("   *data	: %p\n", data.philo[i].data);
		printf("=====\n");
		i++;
	}
}
