/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:32:28 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/10 20:15:46 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_thread(void *arg)
{
	t_ph		*data;
	t_lst_ph	*ph;

	ph = (t_lst_ph *)arg;
	data = ph->data;
	printf ("if thread nb %d\n", ph->id);
	return (0);
}
