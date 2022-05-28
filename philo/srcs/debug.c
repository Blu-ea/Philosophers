/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 06:48:33 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/28 06:54:58 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdio.h>

void	ft_printf_data(t_philo data)
{
	printf ("====== Debug ======\n");
	printf("nb_philo      : %d\n", data.nb_philo);
	printf("time_to_die   : %d\n", data.time_to_die);
	printf("time_to_eat   : %d\n", data.time_to_eat);
	printf("time_to_sleep : %d\n", data.time_to_sleep);
	printf("nb_must_eat   : %d\n", data.nb_must_eat);
	printf ("====== Debug ======\n");
}