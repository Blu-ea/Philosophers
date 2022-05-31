/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 06:48:33 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/29 09:14:35 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_printf_data(t_philo data)
{
	printf ("====== Debug ======\n");
	printf("nb_philo      : %d\n", data.nb_philo);
	printf("time_to_die   : %d\n", data.time_to_die);
	printf("time_to_eat   : %d\n", data.time_to_eat);
	printf("time_to_sleep : %d\n", data.time_to_sleep);
	printf("nb_must_eat   : %d\n", data.nb_must_eat);
	printf("\n");

	int	i;

	i = -1;
	while (++i < data.nb_philo)
	{
		printf("------ philo nb %d -----\n", i);
		printf("id = %d\n", data.lst_philo[i].id);
		printf("fork left = %d\n", data.lst_philo[i].fork_left);
		printf("fork right = %d\n", data.lst_philo[i].fork_right);
		printf("------------------------\n");
	}
	printf ("\n====== Debug ======\n");
}