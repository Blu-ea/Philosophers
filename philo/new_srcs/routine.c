/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:02:01 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/07 16:45:46 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/new_philo.h"

void	*routine(void *temp)
{
	t_lst_ph	*philo;
	t_ph		*data;

	philo = (t_lst_ph *)temp;
	data = philo->data;
	return (0);
}
