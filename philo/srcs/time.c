/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 07:16:09 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/28 07:48:07 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

u_int64_t	ft_get_time(t_lst_ph *ph)
{
	u_int64_t	start;
	u_int64_t	current;

	gettimeofday(&ph->data->current, NULL);
	start = (ph->data->start.tv_sec * (u_int64_t) 1000)
		+ (ph->data->start.tv_usec / (u_int64_t) 1000);
	current = (ph->data->current.tv_sec * (u_int64_t) 1000) 
		+ (ph->data->current.tv_usec / (u_int64_t) 1000);
	return (current - start);
}
